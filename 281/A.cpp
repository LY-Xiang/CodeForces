#include <cctype>
#include <cstdio>

int main()
{
    int c1;
    if ((c1 = std::getchar()) != EOF) std::putchar(std::toupper(c1));
    for (int c; (c = std::getchar()) != '\n' && c != EOF;) std::putchar(c);
    std::putchar('\n');
}