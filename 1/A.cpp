#include <cstdio>

int main()
{
    unsigned long n, m, a;
    std::scanf("%lu%lu%lu", &n, &m, &a);
    std::printf(
        "%llu", (static_cast<unsigned long long>(n + a - 1) / a) * ((m + a - 1) / a));
}
