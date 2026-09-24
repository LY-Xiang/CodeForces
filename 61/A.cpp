#include <cstdio>

int main()
{
    static char buf[201];
    std::fread(buf, 1, 201, stdin);
    char* p{buf};
    const char* q{buf};

    while (*q++ != '\n')
    {
    }

    for (const char* const r{q - 1}; p < r; *p++ ^= *q++ & 1)
    {
    }
    std::fwrite(buf, 1, p - buf, stdout);
}
