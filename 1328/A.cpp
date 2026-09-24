#include <cstdio>

int main()
{
    unsigned t;
    for (std::scanf("%u", &t); t; --t)
    {
        unsigned a, b;
        std::scanf("%u%u", &a, &b);
        a %= b;
        std::printf("%u\n", a ? b - a : 0);
    }
}
