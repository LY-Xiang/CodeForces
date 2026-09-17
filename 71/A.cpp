#include <cstdio>

int main()
{
    unsigned char n;
    for (std::scanf("%hhu%*c", &n); n; --n)
    {
        char t[10];
        unsigned char l{0};
        for (std::putchar(std::getchar());
             l != 10;
             ++l)
            if ((t[l] = std::getchar()) == '\n' || t[l] == EOF)
                break;
        if (t[l] == '\n' || t[l] == EOF)
            for (unsigned char lt{0}; lt != l+1; ++lt)
                std::putchar(t[lt]);
        else
        {
            for (t[0] = t[9];
                 (t[9] = std::getchar()) != '\n' && t[9] != EOF;
                 ++l)
                t[0] = t[9];
            std::printf("%hhu", l - 1);
            std::putchar(t[0]);
            std::putchar(t[9]);
        }
    }
}
