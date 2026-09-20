#include <cstdio>

int main()
{
    unsigned long n;
    unsigned k;

    for (std::scanf("%lu%u", &n, &k); k;)
        if (n % 10 >= k)
        {
            n -= k;
            k = 0;
        }
        else
        {
            k -= n % 10 + 1;
            n /= 10;
        }
    std::printf("%lu", n);
}
