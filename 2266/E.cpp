#include <cstdio>
#include <cstddef>
#include <vector>
#include <algorithm>

namespace io
{
    static constexpr std::size_t BSZ{1 << 16};
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

constexpr int MAXN{200000};

int main()
{
    static std::vector<int> spf(MAXN + 1), primes;
    for (int i{2}; i <= MAXN; ++i)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (const int p : primes)
        {
            if (p > spf[i] || 1LL * i * p > MAXN) break;
            spf[i * p] = p;
        }
    }

    static std::vector<int> v;
    for (auto t{io::readU<unsigned>()}; t; --t)
    {
        const int n{static_cast<int>(io::readU<unsigned>())},
                  k{static_cast<int>(io::readU<unsigned>())};
        if (static_cast<int>(v.size()) <= n) v.resize(n + 1);
        std::fill(v.begin() + 1, v.begin() + n + 1, 0);
        for (int i{n}; i; --i)
            ++v[static_cast<int>(io::readU<unsigned>())];
        unsigned long long ans{0};
        for (int x{1}; x <= n; ++x)
        {
            int dx{0};
            if (x > k)
            {
                dx = x;
                int temp{x};
                while (temp > 1)
                {
                    const int p{spf[temp]};
                    if (const int cand{1 + p * v[x / p]}; cand < dx && (dx = cand) == 1)
                        break;
                    while (temp % p == 0) temp /= p;
                }
            }
            ans += 1ULL * v[x] * dx;
            v[x] = dx;
        }
        io::writeU(ans);
    }
    io::flush();
    return 0;
}
