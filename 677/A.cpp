    #include <cstdio>

    int main()
    {
        unsigned n, h, s{0};
        std::scanf("%u%u", &n, &h);
        for (unsigned i; n; --n)
        {
            std::scanf("%u", &i);
            if (i > h)s += 2;
            else ++s;
        }
        std::printf("%u", s);
    }
