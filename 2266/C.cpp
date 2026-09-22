#include <cstdio>
#include <cstddef>

namespace io
{
    static constexpr std::size_t BSZ{1 << 12};
    static char ib[BSZ], ob[BSZ];
    static std::size_t ip{0}, in{0}, op{0};

    static inline char gc()
    {
        if (ip == in)
        {
            in = std::fread(ib, 1, BSZ, stdin);
            ip = 0;
            if (in == 0) return 0;
        }
        return ib[ip++];
    }

    template <class T>
    static inline T readU()
    {
        char c{gc()};
        while (c < '0' || c > '9') c = gc();
        T v{0};
        do
        {
            v = T(v * 10 + (c - '0'));
            c = gc();
        }
        while (c >= '0' && c <= '9');
        return v;
    }

    static inline bool readBit()
    {
        char c{gc()};
        while (c != '0' && c != '1') c = gc();
        return c == '1';
    }

    static inline void flush()
    {
        if (op)
        {
            std::fwrite(ob, 1, op, stdout);
            op = 0;
        }
    }

    static inline void writeU(unsigned long long v)
    {
        char t[24];
        int k{0};
        do
        {
            t[k++] = static_cast<char>('0' + v % 10);
            v /= 10;
        }
        while (v);
        while (k)
        {
            ob[op++] = t[--k];
            if (op == BSZ) flush();
        }
        ob[op++] = '\n';
        if (op == BSZ) flush();
    }
}

int main()
{
    for (auto t{io::readU<unsigned>()}; t; --t)
    {
        const auto n{io::readU<unsigned>()};
        int zeros, w, minw;
        const bool f{io::readBit()};
        if (f)
        {
            zeros = minw = 0;
            w = 1;
        }
        else
        {
            minw = w = -1;
            zeros = 1;
        }
        for (unsigned i{1}; i != n; ++i)
            if (const bool b{io::readBit()}; b)
                ++w;
            else
            {
                if (--w < minw) minw = w;
                ++zeros;
            }
        io::writeU(static_cast<unsigned long long>(f ? zeros : zeros + minw));
    }
    io::flush();
    return 0;
}
