#include <array>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int MAX_N = 200'000;
    // Safe without clearing between cases: a_i is a permutation of 1..n, so the
    // writes cover exactly {1..n}, and the checks below only read indices in
    // {1..n} (value < n, hence value+1 <= n).  Read set is a subset of write set.
    static std::array<unsigned char, MAX_N + 1> position_parity{};

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;

        for (int i = 0; i < n; ++i)
        {
            int value;
            std::cin >> value;
            position_parity[value] = static_cast<unsigned char>(i & 1);
        }

        bool possible = true;
        int first = 1;
        if (n & 1)
        {
            possible = position_parity[1] == 0;
            first = 2;
        }

        for (int value = first; value < n; value += 2)
        {
            if (position_parity[value] == position_parity[value + 1])
            {
                possible = false;
                break;
            }
        }

        std::cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
