#include <cstdio>

int main()
{
    char a[100 + 1];
    unsigned n{0};
    for (int c; (c = std::getchar()) != '\n' && c != EOF;)
        a[n++] = static_cast<char>(c);
    unsigned i{n};
    bool ok{true};
    for (int c; ok && (c = std::getchar()) != '\n' && c != EOF;)
        ok = i != 0 && c == a[--i];
    std::puts(ok && i == 0 ? "YES" : "NO");
}