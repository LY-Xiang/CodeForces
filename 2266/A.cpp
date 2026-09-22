#include <cstdio>
#include <cstddef>
#include <algorithm>

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
    for (unsigned t{io::readU<unsigned>()}; t; --t)
        io::writeU(io::readU<unsigned long long>() - std::min({
            io::readU<unsigned long long>(),
            io::readU<unsigned long long>(),
            io::readU<unsigned long long>()
        }));
    io::flush();
    return 0;
}
