#include <cstdio>

int main()
{
    unsigned short int n, m{0};
    for (std::scanf("%hu", &n); n; --n)
    {
        unsigned char t{0};
        std::getchar();
        if (std::getchar() == '1')++t;
        std::getchar();
        if (std::getchar() == '1')++t;
        std::getchar();
        if (std::getchar() == '1')++t;
        if (t == 2 || t == 3)++m;
    }
    std::printf("%hu", m);
}
