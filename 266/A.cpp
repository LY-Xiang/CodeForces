#include <cstdio>

int main()
{
    unsigned n, s{0};
    std::scanf("%u", &n);
    std::getchar();
    for (int c, cp{'\0'}; n; --n)
    {
        if ((c = std::getchar()) == cp)++s;
        cp = c;
    }
    std::printf("%u", s);
}
