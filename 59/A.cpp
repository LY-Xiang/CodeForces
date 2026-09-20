#include <cstdio>
#include <cctype>

int main()
{
    char s[100 + 2];
    std::fgets(s, 100 + 1, stdin);
    int u{0};
    const char* p{s};
    for (; std::isalpha(*p); ++p)
        if (std::isupper(*p))++u;
        else --u;
    if (u > 0)
        for (const char* pt{s}; pt != p; ++pt)
            std::putchar(std::toupper(*pt));
    else
        for (const char* pt{s}; pt != p; ++pt)
            std::putchar(std::tolower(*pt));
}
