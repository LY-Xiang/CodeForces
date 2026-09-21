#include <cctype>
#include <cstdio>

int main()
{
    char a[100 + 1], b[100 + 1];
    std::scanf("%s %s", a, b);
    for (int i{0}; i <= 100; ++i)
    {
        const int x{std::toupper(a[i])}, y{std::toupper(b[i])};
        if (x != y)
        {
            if (x < y) std::putchar('-');
            std::putchar('1');
            return 0;
        }
        if (x == 0) break;
    }
    std::putchar('0');
}