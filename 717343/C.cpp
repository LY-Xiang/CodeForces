#include <array>
#include<cstdio>

int main()
{
    int t;
    for (std::scanf("%d", &t); t; t--)
    {
        int n;
        int a = -1, b = -1, c = -1, cur;
        std::scanf("%d", &n);
        for (; n; --n)
        {
            std::scanf("%d", &cur);
            std::getchar();
            if (std::getchar() == '0')
            {
                if (std::getchar() == '0');
                else
                {
                    if (cur < b || b == -1)b = cur;
                }
            }
            else
            {
                if (std::getchar() == '0')
                {
                    if (cur < a || a == -1)a = cur;
                }
                else
                {
                    if (cur < c || c == -1)c = cur;
                }
            }
        }
        if (c == -1 && (a == -1 || b == -1))
            std::puts("-1");
        else
        {
            if (a != -1 && b != -1 && (c == -1 || a + b < c))
                std::printf("%d\n", a + b);
            else
                std::printf("%d\n", c);
        }
    }
}
