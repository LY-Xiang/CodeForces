#include <cstdio>

int main()
{
    unsigned long n, s{0};
    std::scanf("%lu%*c", &n);
    for (int c{0}, t; n; --n)
    {
        if ((t = std::getchar()) != c)
        {
            ++s;
            c = t;
        }
        std::getchar();
        std::getchar();
    }
    std::printf("%lu", s);
}
