#include <cstdint>
#include <cstdio>

namespace io
{
    constexpr int ISZ{1 << 16}, OSZ{1 << 16};

    namespace
    {
        char ib[ISZ], ob[OSZ];
        int ip{0}, il{0}, op{0};
    }

    static inline int gc()
    {
        if (ip == il)
        {
            il = static_cast<int>(fread(ib, 1, ISZ, stdin));
            ip = 0;
            if (!il) return -1;
        }
        return ib[ip++];
    }

    static inline unsigned rd()
    {
        int c{gc()};
        while (c < '0') c = gc();
        unsigned x{0};
        do
        {
            x = x * 10 + static_cast<unsigned>(c - '0');
            c = gc();
        }
        while (static_cast<unsigned>(c - '0') < 10u);
        return x;
    }

    static inline void flush()
    {
        fwrite(ob, 1, static_cast<size_t>(op), stdout);
        op = 0;
    }

    static inline void wr(unsigned x)
    {
        if (op + 8 > OSZ) flush();
        char t[8];
        int k{0};
        do
        {
            t[k++] = static_cast<char>('0' + x % 10);
            x /= 10;
        }
        while (x);
        while (k) ob[op++] = t[--k];
        ob[op++] = ' ';
    }

    static inline void nl()
    {
        if (op + 2 > OSZ) flush();
        ob[op++] = '\n';
    }
}

static constexpr unsigned GOOD{0x9669u};
static uint8_t a[200000];

int main()
{
    int t{static_cast<int>(io::rd())};
    while (t--)
    {
        const int n{static_cast<int>(io::rd())};
        int q{static_cast<int>(io::rd())}, ans{0};
        for (int i{0}; i < n; i++)
        {
            const unsigned v{io::rd()};
            a[i] = static_cast<uint8_t>(v);
            ans += static_cast<int>((GOOD >> v) & 1u);
        }
        io::wr(static_cast<unsigned>(ans));
        while (q--)
        {
            const unsigned p{io::rd() - 1}, x{io::rd()};
            ans += static_cast<int>((GOOD >> x) & 1u) - static_cast<int>((GOOD >> a[p]) & 1u);
            a[p] = static_cast<uint8_t>(x);
            io::wr(static_cast<unsigned>(ans));
        }
        io::nl();
    }
    io::flush();
    return 0;
}
