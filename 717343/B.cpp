#include<cstdio>

int main()
{
    int t;
    for (std::scanf("%d", &t); t; t--)
    {
        int n, max = 0, cur = 0;
        std::scanf("%d", &n);
        for (; n; --n)
        {
            std::getchar();
            if (std::getchar() == '0')
            {
                ++cur;
            }
            else
            {
                if (cur > max)max = cur;
                cur = 0;
            }

        }
        if (cur > max)max = cur;
        std::printf("%d\n", max);
    }
}
