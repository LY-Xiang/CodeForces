#include <cstdio>
#include <iostream>

int main()
{
    unsigned char n, k, kt, a;
    std::scanf("%hhu%hhu", &n, &k);
    for (kt = k; kt; --kt)
    {
        std::scanf("%hhu", &a);
        if (a == 0)break;
    }
    if (kt == 0 && n != k)
    {
        kt = k - 1;
        for (unsigned char at{a}; at == a && kt < n; std::scanf("%hhu", &at))
            ++kt;    }
    else kt = k - kt;
    std::printf("%hhu", kt);
}
