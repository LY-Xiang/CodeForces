#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        char c;
        std::string s;
        std::cin >> n >> c >> s;

        int ans{0};

        for (int i = 0; i < n / 2; i++)
        {
            const char a{s[i]};
            const char b{s[n - 1 - i]};

            if (a == b) continue;

            if (a == c || b == c)
                ans += 1;

            else

                ans += 2;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
