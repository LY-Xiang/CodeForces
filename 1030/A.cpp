#include <cstdio>

int main()
{
    unsigned n;
    std::scanf("%u", &n);
    for (; n; --n)
        if (std::getchar(), std::getchar() == '1')
        {
            std::puts("HARD");
            return 0;
        }
    std::puts("EASY");
}
