#include <cstdio>

int main()
{
    unsigned n, s{0}, m{0};
    for (std::scanf("%u", &n); n; --n)
    {
        unsigned at, bt;
        std::scanf("%u%u", &at, &bt);
        if (m < (s = s - at + bt))m = s;
    }
    std::printf("%u\n", m);
}
