#include <cstdio>
#include <cctype>

int main()
{
    for (int c; std::isalpha(c = std::tolower(std::getchar()));)

        if (c != 'e' && c != 'a' && c != 'o' && c != 'i' && c != 'u' && c != 'y')
        {
            std::putchar('.');
            std::putchar(c);
        }
}
