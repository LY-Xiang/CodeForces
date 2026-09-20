#include <cstdio>

int main()
{
    unsigned n, s{0}, m{0};
    for (std::scanf("%u", &n); n; --n)
    {
        unsigned i;
        std::scanf("%u", &i);
        s -= i;
        std::scanf("%u", &i);
        s += i;
        if (m < s)m = s;
    }
    std::printf("%u\n", m);
}
