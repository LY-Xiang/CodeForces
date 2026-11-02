#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::getchar();
        int l = -1, r = 0, o = 0;
        char c;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> c;
            if (c == '1')
            {
                ++o;
                if (l == -1)l = i;
                r = i;
            }
        }
        std::cout << ((o == 1) ? 0 : (o == 2 ? 1 : r - l)) << std::endl;
    }
}
