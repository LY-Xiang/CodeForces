#include <cstdio>
#include <memory>

int main()
{
    unsigned n;
    std::scanf("%u", &n);
    const std::unique_ptr<unsigned[]> p(new unsigned[n]);
    for (unsigned i{0}, t; i != n; p[t - 1] = ++i)
        std::scanf("%u", &t);
    for (const auto* q{p.get()}; q != p.get() + n; ++q)
        std::printf("%u ", *q);
}
