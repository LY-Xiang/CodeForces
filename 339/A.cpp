#include <cstdio>

int main()
{
    unsigned s[3]{0, 0, 0};
    for (int c; ++s[(c = std::getchar()) - '1'], std::getchar() == '+';)
    {
    }
    if (s[0])
    {
        std::putchar('1');
        --s[0];
    }
    else if (s[1])
    {
        std::putchar('2');
        --s[1];
    }
    else
    {
        std::putchar('3');
        --s[2];
    }
    for (; s[0]--; std::putchar('1'))std::putchar('+');
    for (; s[1]--; std::putchar('2'))std::putchar('+');
    for (; s[2]--; std::putchar('3'))std::putchar('+');
}
