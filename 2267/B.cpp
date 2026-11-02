#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> cnt(101, 0);
        for (int i = 0; i < n; ++i)
        {
            int x;
            std::cin >> x;
            ++cnt[x];
        }

        std::vector<int> answer;
        answer.reserve(n);

        while (true)
        {
            int x = 100;
            while (x > 0 && cnt[x] == 0)
            {
                --x;
            }
            if (x == 0) break;

            int f = cnt[x];
            for (int i = 0; i < f; ++i)
            {
                answer.push_back(x);
            }
            cnt[x] = 0;

            for (int y = x - 1; y >= 1; --y)
            {
                int take = std::min(f, cnt[y]);
                for (int i = 0; i < take; ++i)
                {
                    answer.push_back(y);
                }
                cnt[y] -= take;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            std::cout << answer[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
