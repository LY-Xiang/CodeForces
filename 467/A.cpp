#include <cstdio>

int main()
{
    unsigned n, s{0};
    std::scanf("%u", &n);
    for (unsigned p, q; n; --n)
    {
        std::scanf("%u%u", &p, &q);
        if (p + 1 < q)++s;
    }
    std::printf("%u", s);
}
