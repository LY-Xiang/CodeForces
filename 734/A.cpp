#include <cstdio>

int main()
{
    int s{0};
    unsigned long n;
    for (std::scanf("%lu%*c", &n); n; --n)
        if (std::getchar() == 'A')++s;
        else --s;
    std::puts(s > 0 ? "Anton" : s < 0 ? "Danik" : "Friendship");
}
