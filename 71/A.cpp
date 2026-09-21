#include <cstdio>

int main()
{
    unsigned n;
    for (std::scanf("%u%*c", &n); n; --n)
    {
        char w[10];
        unsigned l{0};
        int a;
        while (l != 10 && (a = std::getchar()) != '\n' && a != EOF)
            w[l++] = static_cast<char>(a);
        if (a == '\n' || a == EOF)
        {
            for (unsigned i{0}; i != l; ++i) std::putchar(w[i]);
        }
        else
        {
            a = std::getchar();
            if (a == '\n' || a == EOF)
            {
                for (unsigned i{0}; i != 10; ++i) std::putchar(w[i]);
            }
            else
            {
                char last{static_cast<char>(a)};
                unsigned len{11};
                while ((a = std::getchar()) != '\n' && a != EOF)
                {
                    last = static_cast<char>(a);
                    ++len;
                }
                std::printf("%c%u%c", w[0], len - 2, last);
            }
        }
        std::putchar('\n');
    }
}