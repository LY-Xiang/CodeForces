#include <cstdio>

int main()
{
    unsigned n;
    std::scanf("%u", &n);
    unsigned p[100];
    for (unsigned i{0}, t; i != n; p[t - 1] = ++i)
        std::scanf("%u", &t);
    for (const auto* q{p}; q != p + n; ++q)
        std::printf("%u ", *q);
}
