#include <cstdio>

int main()
{
    unsigned a, b, t{0};
    std::scanf("%u%u", &a, &b);
    for (; a <= b; a *= 3, b *= 2) ++t;
    std::printf("%u", t);
}