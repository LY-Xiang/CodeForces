#include <cstdio>

int main()
{
    unsigned char n;
    std::scanf("%hhu", &n);
    std::puts((n % 2 == 0) && (n >= 4) ? "YES" : "NO");
}
