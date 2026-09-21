#include <cstdio>

int main()
{
    long long n;
    std::scanf("%lld", &n);
    std::printf("%lld", n & 1 ? -(n + 1) / 2 : n / 2);
}