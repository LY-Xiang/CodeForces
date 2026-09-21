#include <cstdio>

int main()
{
    unsigned n;
    scanf("%u", &n);
    std::puts(
        n % 4 &&
        n % 7 &&
        n % 44 &&
        n % 47 &&
        n % 74 &&
        n % 77 &&
        n % 444 &&
        n % 447 &&
        n % 474 &&
        n % 477 &&
        n != 744 &&
        n != 747 &&
        n != 774 &&
        n != 777
            ? "NO"
            : "YES");
}
