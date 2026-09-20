#include <cstdio>
#include <iostream>

int main()
{
    unsigned n, k, kt, a;
    std::scanf("%u%u", &n, &k);
    for (kt = k; kt; --kt)
    {
        std::scanf("%u", &a);
        if (a == 0)break;
    }
    if (kt == 0 && n != k)
    {
        kt = k - 1;
        for (unsigned at{a}; at == a && kt < n; std::scanf("%u", &at))
            ++kt;
    }
    else kt = k - kt;
    std::printf("%u", kt);
}
