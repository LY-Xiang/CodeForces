// 1213D1 -- Equalizing by Division (easy version).
// n <= 50, k <= n, 1 <= a_i <= 2e5.
//
// One operation is a_i := a_i >> 1, so a_i can turn into v exactly when v is one
// of the binary prefixes of a_i, and the cheapest price for that is
//     L = bitlen(a_i) - bitlen(v)      (v >= 1),      L = bitlen(a_i)   (v = 0).
// Target v therefore costs "the sum of the k cheapest prices among the elements
// that can reach it"; the answer is the min of that over all v.
//
// Walk the prices in increasing order, L = 0, 1, 2, ...: the first k elements
// that reach a target are exactly its k cheapest ones, so one (count, sum) pair
// per target is enough and no sort is ever needed.
// Target 0 is universal (every a_i >= 1 reaches it at cost bitlen(a_i)), so it is
// answered up front -- which also keeps v = 0 out of the table, where it would be
// revisited once per extra level.
// At most n * 18 <= 900 distinct targets are ever touched, so an open-addressed
// table beats indexing by value: 16 KiB that stays in L1, against 1.6 MiB that has
// to be faulted in page by page.
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>

namespace io
{
    constexpr int ISZ{1 << 16};

    namespace
    {
        char ib[ISZ];
        int ip{0}, il{0};
    }

    static inline int gc()
    {
        if (ip == il)
        {
            il = static_cast<int>(std::fread(ib, 1, ISZ, stdin));
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
}

namespace solve
{
    // (target << 44) | (count << 24) | sum, all three fields saturated well inside
    // their widths: target <= 2e5 < 2^18, count <= k <= 50, sum <= 17 * k <= 850.
    constexpr int        MASK{2047};                      // >= 2 * 900 keys
    std::uint64_t        tab[MASK + 1]{};

    constexpr std::uint64_t CNT{1ull << 24};                   // count lives in bits 24..43
    constexpr std::uint64_t SUM{0xffffffull};                  // sum lives in bits 0..23
    constexpr std::uint64_t FLD{0xfffffull << 24};             // the count field itself
    constexpr int               SHK{44};                      // the target field's shift

    static int run(const int* a, int n, int k)
    {
        // multiply-shift: a 2-universal family for any odd multiplier, so a fresh
        // odd seed per run costs nothing measurable and no input can be aimed at
        // it.  Reading the HIGH half of the product is the point: our keys are
        // a_i >> L and right shifts preserve low bits, so a low-bit hash would
        // drop a whole ancestor chain into one bucket.
        const std::uint32_t seed{static_cast<std::uint32_t>(
            std::chrono::steady_clock::now().time_since_epoch().count()) | 1u};

        // target 0: the k smallest bit lengths.
        int hist[33]{}, mx{1};
        for (int i{0}; i < n; ++i)
        {
            mx = std::max(mx, a[i]);
            ++hist[32 - __builtin_clz(static_cast<unsigned>(a[i]))];
        }
        int best{0};
        for (int b{1}, need{k}; b <= 32 && need; ++b)
        {
            const int take{std::min(need, hist[b])};
            best += take * b;
            need -= take;
        }

        const std::uint32_t ku{static_cast<std::uint32_t>(k)};
        const int levels{32 - __builtin_clz(static_cast<unsigned>(mx))};
        for (int L{0}; L < levels && L < best; ++L)
        {
            for (int i{0}; i < n; ++i)
            {
                const std::uint32_t v{static_cast<std::uint32_t>(a[i] >> L)};
                if (!v) continue;   // target 0, already settled above
                std::uint32_t h{((v * seed) >> 21) & MASK};
                for (;;)
                {
                    std::uint64_t& e{tab[h]};
                    const std::uint32_t key{static_cast<std::uint32_t>(e >> SHK)};
                    if (key != v && key != 0) { h = (h + 1) & MASK; continue; }
                    if (!key) e = static_cast<std::uint64_t>(v) << SHK;
                    if (static_cast<std::uint32_t>((e & FLD) >> 24) < ku)
                    {
                        e += CNT + static_cast<std::uint64_t>(L);
                        if (static_cast<std::uint32_t>((e & FLD) >> 24) == ku)
                        {
                            const std::uint64_t tot{e & SUM};
                            if (tot < static_cast<std::uint64_t>(best)) best = static_cast<int>(tot);
                        }
                    }
                    break;
                }
            }
        }
        return best;
    }
}

int main()
{
    const int n{io::rd()}, k{io::rd()};
    if (n < 1) return 0;

    int a[50];
    for (int i{0}; i < n; ++i) a[i] = io::rd();

    std::printf("%d\n", solve::run(a, n, k));
    return 0;
}