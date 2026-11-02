#include <cstdio>

int main()
{
    int t;
    std::scanf("%d", &t);
    while (t--)
    {
        int n, k;
        std::scanf("%d%d", &n, &k);
        std::printf("%lld\n", (1LL << (n - k + 1)) + 2LL * (k - 1));
    }
    return 0;
}
