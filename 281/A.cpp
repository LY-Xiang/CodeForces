#include <cstdio>
#include <cctype>

int main()
{
    char buf[1000];
    std::putchar(std::toupper(std::getchar()));
    std::fgets(buf, 1000 - 1,stdin);
    std::puts(buf);
}
