#include <cstdio>

int main()
{
    static char buf[1025];
    const auto len{std::fread(buf, 1, sizeof buf - 1, stdin)};
    buf[len] = '\0';
    const char* p{buf};

    auto next = [&]
    {
        while (*p < '0' && *p)
            ++p;
        unsigned x{};
        while (*p >= '0')
            x = x * 10 + (*p++ - '0');
        return x;
    };

    unsigned cnt[101]{}, total{}, n{next()};
    for (unsigned t{}; n; --n)
    {
        ++cnt[t = next()];
        total += t;
    }

    for (unsigned i{100}, s{}, target{total >> 1}; i; --i)
        while (cnt[i])
        {
            --cnt[i];
            ++s;
            if (target < i)
            {
                char o[3];
                int k{};
                do
                {
                    o[k++] = static_cast<char>('0' + s % 10);
                    s /= 10;
                }
                while (s);
                while (k)
                    std::putchar(o[--k]);
                return 0;
            }
            target -= i;
        }
}
