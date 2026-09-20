#include <cstdio>

int main()
{
    unsigned n, m{0};
    for (std::scanf("%u", &n); n; --n)
    {
        unsigned t{0};
        std::getchar();
        if (std::getchar() == '1')++t;
        std::getchar();
        if (std::getchar() == '1')++t;
        std::getchar();
        if (std::getchar() == '1')++t;
        if (t == 2 || t == 3)++m;
    }
    std::printf("%u", m);
}
