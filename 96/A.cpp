#include <cstdio>

int main()
{
    for (int c, r{0}, s{0}; (c = getchar()) != EOF;)
        if (c == r)
        {
            if (++s == 7)
            {
                std::puts("YES");
                return 0;
            }
        }
        else
        {
            s = 1;
            r = c;
        }
    std::puts("NO");
}
