#include <cstdio>

int main()
{
    char s[25]{
        '4', '3', '2', '3', '4',
        '3', '2', '1', '2', '3',
        '2', '1', '0', '1', '2',
        '3', '2', '1', '2', '3',
        '4', '3', '2', '3', '4',
    };
    const char* p{s};
    for (int c; (c = std::getchar()) != '1'; std::getchar())++p;
    std::putchar(*p);
}
