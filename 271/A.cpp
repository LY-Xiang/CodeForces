#include <cstdio>

static bool distinct(unsigned n)
{
    unsigned k{0};
    for (; n; n /= 10)
    {
        const unsigned d{n % 10};
        if (k >> d & 1u) return false;
        k |= 1u << d;
    }
    return true;
}

int main()
{
    unsigned y;
    std::scanf("%u", &y);
    while (!distinct(++y)) {}
    std::printf("%u", y);
}