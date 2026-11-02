#include <cstddef>
#include <cstdio>

namespace
{
    // "00".."99" in rodata, so emitting a 2-digit value costs 2 loads and 2 stores
    // instead of a divide/modulo chain.
    struct D2
    {
        char v[200];
        constexpr D2() : v{}
        {
            for (unsigned i{0}; i < 100; ++i)
            {
                v[i * 2] = static_cast<char>('0' + i / 10);
                v[i * 2 + 1] = static_cast<char>('0' + i % 10);
            }
        }
    };
    constexpr D2 T{};

    // Parse one integer. '\0' and ' ' are both < '0', so the blank skip and the
    // digit loop need only one comparison each; buf is static and zero-filled,
    // so the terminator always stops the digit loop.
    inline const char* rd(const char* p, unsigned& v)
    {
        while (*p < '0') ++p;
        v = 0;
        do
        {
            v = v * 10 + static_cast<unsigned>(*p++ - '0');
        } while (*p >= '0');
        return p;
    }

    // Gravity turns the histogram into its conjugate, and a partition's conjugate
    // is its own conjugate, so the result is just the values sorted ascending.
    // Counting sort over a_i <= 100 is O(n + 100) with no comparisons.
}

int main()
{
    // n <= 100 and a_i <= 100, so the input is at most "100\n" + 100*4 = 404 bytes.
    static char buf[416], out[416];
    const std::size_t len{std::fread(buf, 1, sizeof buf, stdin)};
    (void)len;

    unsigned n;
    const char* p{rd(buf, n)};
    unsigned char f[101]{}; // counts fit in a byte: n <= 100
    for (unsigned i{0}; i < n; ++i)
    {
        unsigned v;
        p = rd(p, v);
        ++f[v];
    }

    // Trailing space after every number, then the last one becomes '\n': that keeps
    // the "have I written anything yet?" test out of the inner loop.
    char* o{out};
    for (unsigned v{0}; v < 100; ++v)
    {
        const unsigned c{f[v]};
        if (!c) continue;
        if (v < 10)
        {
            const char d0{static_cast<char>('0' + v)};
            for (unsigned i{c}; i--;)
            {
                *o++ = d0;
                *o++ = ' ';
            }
        }
        else
        {
            // T stores the 2-digit form of k at offset 2k
            const char d0{T.v[v * 2]}, d1{T.v[v * 2 + 1]};
            for (unsigned i{c}; i--;)
            {
                *o++ = d0;
                *o++ = d1;
                *o++ = ' ';
            }
        }
    }
    for (unsigned i{f[100]}; i--;) // the only 3-digit value
    {
        *o++ = '1';
        *o++ = '0';
        *o++ = '0';
        *o++ = ' ';
    }

    o[-1] = '\n';
    std::fwrite(out, 1, static_cast<std::size_t>(o - out), stdout);
}
