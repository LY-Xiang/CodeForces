#include <cstdio>

int main()
{
    constexpr char s[5 + 1]{"hello"};
    const char* p{s};
    for (int c; (c = std::getchar()) != '\n' && c != EOF;)
        if (c == *p)
            if (++p == s + 5)
            {
                std::puts("YES");
                return 0;
            }
    std::puts("NO");
}
