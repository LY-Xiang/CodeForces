#include <cstdio>
#include <cstdint>

namespace
{
    constexpr int MAXS{810},
                  SZ{MAXS + 1};

    std::uint8_t cls[SZ];
    std::uint8_t prv[SZ];
    std::uint32_t cnt[SZ];
    int ncls{0};

    void build()
    {
        int nxt[SZ];
        std::uint8_t st[SZ]{};
        int path[SZ];
        for (int v{1}; v <= MAXS; ++v)
        {
            int s{0};
            for (int y = v; y; y /= 10)
            {
                const int d{y % 10};
                s += d * d;
            }
            nxt[v] = s;
        }

        for (int v = 1; v <= MAXS; ++v)
        {
            if (st[v]) continue;
            int len{0}, x{v};
            while (!st[x])
            {
                st[x] = 1;
                path[len++] = x;
                x = nxt[x];
            }
            int s;
            if (st[x] == 2)
                s = len;
            else
            {
                s = 0;
                while (path[s] != x) ++s;
                const int L{len - s}, base{ncls};
                for (int i{0}; i < L; ++i) cls[path[s + i]] = static_cast<std::uint8_t>(ncls++);
                for (int i{0}; i < L; ++i) prv[base + i] = static_cast<std::uint8_t>(base + (i + L - 1) % L);
            }
            std::uint8_t c{cls[x]};
            for (int i{s - 1}; i >= 0; --i)
                cls[path[i]] = c = prv[c];
            for (int i = 0; i < len; ++i) st[path[i]] = 2;
        }
    }

    int digit_square_sum(int x)
    {
        int sum{0};
        while (x)
        {
            const int d{x % 10};
            sum += d * d;
            x /= 10;
        }
        return sum;
    }
}

int main()
{
    build();
    int t;
    if (std::scanf("%d", &t) != 1) return 0;
    while (t-- > 0)
    {
        int n;
        if (std::scanf("%d", &n) != 1) return 0;
        for (int i{0}; i < ncls; ++i) cnt[i] = 0;
        long long ans{0};
        for (int i{0}; i < n; ++i)
        {
            int value;
            if (std::scanf("%d", &value) != 1) return 0;
            const std::uint32_t c{cls[digit_square_sum(value)]};
            ans += cnt[c];
            ++cnt[c];
        }
        std::printf("%lld\n", ans);
    }
}
