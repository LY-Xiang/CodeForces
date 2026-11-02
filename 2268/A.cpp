#include <algorithm>
#include <cstdio>
#include <vector>

namespace io
{
    constexpr int ISZ{1 << 16},
                  OSZ{1 << 16};

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
        return static_cast<unsigned char>(ib[ip++]);
    }

    static inline int rd()
    {
        int c{gc()};
        while (c != -1 && (c < '0' || c > '9')) c = gc();
        if (c == -1) return -1;
        int x{0};
        do
        {
            x = x * 10 + (c - '0');
            c = gc();
        } while (c >= '0' && c <= '9');
        return x;
    }

    static inline void flush()
    {
        fwrite(ob, 1, static_cast<size_t>(op), stdout);
        op = 0;
    }

    // One answer per test case, so the newline is folded in.
    static inline void wr(long long x)
    {
        if (op + 24 > OSZ) flush();
        char digits[24];
        int length{0};
        do
        {
            digits[length++] = static_cast<char>('0' + x % 10);
            x /= 10;
        } while (x);
        while (length) ob[op++] = digits[--length];
        ob[op++] = '\n';
    }
}

int main()
{
    int t{io::rd()};
    if (t < 0) return 0;
    while (t--)
    {
        const int n{io::rd()};
        const int k{io::rd()};

        std::vector<int> a(n);
        long long tot{0};
        for (int& x : a)
        {
            x = io::rd();
            tot += x;
        }

        const int s{std::min(k - 1, n - k + 1)};
        long long ans{tot};
        for (int i{0}; i < s; ++i) ans -= std::min(a[i], a[n - 1 - i]);
        for (int i{s}; i <= k - 2; ++i) ans -= a[i];
        io::wr(ans);
    }
    io::flush();
    return 0;
}
