#include<cstdio>

int main()
{
    unsigned long s[4]{}, t;
    unsigned d{0};
    for (unsigned i{4}; i; --i)
    {
        std::scanf("%lu", &t);
        bool D{true};
        for (unsigned j{d}; D && j--;)
            if (t == s[j])
                D = false;
        if (D)
            s[d++] = t;
    }
    std::printf("%u\n", 4 - d);
}
