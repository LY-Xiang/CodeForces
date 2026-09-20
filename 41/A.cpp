#include <cstdio>

int main()
{
    int a[100 + 1], *p{a - 1};
    while ((*++p = std::getchar()) != '\n')
    {
    }
    while (std::getchar() == *--p)
        if (p == a)
        {
            std::puts(std::getchar() == '\n' ? "YES" : "NO");
            return 0;
        }
    std::puts("NO");
}
