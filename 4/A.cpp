#include <cstdio>

int main()
{
    unsigned n;
    std::scanf("%u", &n);
    std::puts((n % 2 == 0) && (n >= 4) ? "YES" : "NO");
}
