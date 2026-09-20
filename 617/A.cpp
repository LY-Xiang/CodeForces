#include <cstdio>

int main()
{
    unsigned long x;
    std::scanf("%lu", &x);
    std::printf("%lu", x / 5 + static_cast<bool>(x % 5));
}
