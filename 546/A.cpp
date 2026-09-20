#include <cstdio>

int main()
{
    unsigned k, w;
    unsigned long n;
    std::scanf("%u%lu%u", &k, &n, &w);
    const unsigned long int s{(w * (w + 1) / 2 * k)};
    std::printf("%lu", s > n ? s - n : 0);
}
