#include <cstdio>
#include <cctype>

int main()
{
    unsigned s{0};
    for (int c; std::isdigit(c = std::getchar());)if (c == '4' || c == '7')++s;
    std::puts(s == 4 || s == 7 ? "YES" : "NO");
}
