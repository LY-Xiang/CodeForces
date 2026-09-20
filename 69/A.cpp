#include <cstdio>

int main()
{
    unsigned n;
    int a{0}, b{0}, c{0};
    for (std::scanf("%u", &n); n; n--)
    {
        int at, bt, ct;
        std::scanf("%d%d%d", &at, &bt, &ct);
        a += at;
        b += bt;
        c += ct;
    }
    std::puts((a == 0 && b == 0 && c == 0) ? "YES" : "NO");
}
