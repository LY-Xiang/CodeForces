#include <iostream>
#include <vector>
using int64 = long long;

constexpr int MAXV{300000};

static int spf[MAXV + 1];

static void init()
{
    for (int i = 2; i <= MAXV; ++i)
    {
        if (spf[i] != 0) continue;

        spf[i] = i;

        if (1LL * i * i <= MAXV)
        {
            for (int j = i * i; j <= MAXV; j += i)
            {
                if (spf[j] == 0)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> a(n);
        for (int& v : a) std::cin >> v;

        std::vector<int> factors;
        int value{x};

        while (value > 1)
        {
            int p = spf[value];
            factors.push_back(p);

            while (value % p == 0)
            {
                value /= p;
            }
        }

        int64 answer{0};

        for (const int p : factors)
        {
            int64 current{0};

            for (const int v : a)
            {
                if (v % p == 0)
                {
                    current += v;
                }
            }

            answer = std::max(answer, current);
        }

        std::cout << answer << '\n';
    }

    return 0;
}
