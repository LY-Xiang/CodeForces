#include <cstdio>

int main()
{
    unsigned long long n, k;
    std::scanf("%llu%llu", &n, &k);
    const unsigned long long odd{(n + 1) >> 1};
    std::printf("%llu", k > odd ? (k - odd) << 1 : (k << 1) - 1);
}
