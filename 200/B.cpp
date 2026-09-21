#include <cstdio>

int main()
{
    unsigned n, s{0};
    std::scanf("%u", &n);
    for (unsigned p, i{n}; i; --i)
    {
        std::scanf("%u", &p);
        s += p;
    }
    std::printf("%.12f\n", s * 1.0 / n);
}
