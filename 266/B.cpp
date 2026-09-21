#include <cstdio>
#include <memory>

static void solve(const unsigned n, unsigned t, const char* s, char* out)
{
    if (t > n) t = n;
    if (n == 0)
    {
        out[0] = '\0';
        return;
    }

    const std::unique_ptr<unsigned[]> h{new unsigned[n + 1]};
    unsigned m{0};
    h[0] = 0;
    for (unsigned i{0}; i != n; ++i)
        h[i + 1] = m += s[i] == 'B';

    const unsigned qcap{(n + 2) / 2 + 1};
    const std::unique_ptr<unsigned[]> qb[2]{
        std::unique_ptr<unsigned[]>(new unsigned[qcap]),
        std::unique_ptr<unsigned[]>(new unsigned[qcap])
    };
    unsigned* q[2]{qb[0].get(), qb[1].get()};
    unsigned qh[2]{}, qt[2]{}, hi{0};

    unsigned prev{};
    for (unsigned x{0}; x != n; ++x)
    {
        const unsigned L{x > t ? x - t : 0},
                       R{x + t < n ? x + t : n};

        while (hi <= R)
        {
            const unsigned y{hi++},
                           p{y & 1},
                           wy{2 * h[y] + n - y};
            while (qt[p] > qh[p])
            {
                if (const unsigned tail{q[p][qt[p] - 1]};
                    2 * h[tail] + n - tail > wy)
                    break;
                --qt[p];
            }
            q[p][qt[p]++] = y;
        }
        for (unsigned p{0}; p != 2; ++p)
            while (qh[p] < qt[p] && q[p][qh[p]] < L)
                ++qh[p];

        const unsigned p{(x + t) & 1}, y{q[p][qh[p]]},
                       best{2 * h[y] + n - y},
                       interior{x + best >= n + t ? (x + best - n - t) / 2 : 0},
                       rightWall{n - x <= t && m >= n - x ? m - (n - x) : 0},
                       cur{interior > rightWall ? interior : rightWall};

        if (x) out[x - 1] = cur - prev == 1 ? 'B' : 'G';
        prev = cur;
    }
    out[n - 1] = m - prev == 1 ? 'B' : 'G';
    out[n] = '\0';
}

int main()
{
    unsigned n, t;
    std::scanf("%u%u%*c", &n, &t);
    const std::unique_ptr<char[]> s{new char[n > 0 ? n : 1]};
    size_t got{0};
    while (got < n)
    {
        const size_t k = std::fread(s.get(), 1, n - got, stdin);
        if (k == 0) break;
        got += k;
    }
    const std::unique_ptr<char[]> out{new char[n + 1]};
    solve(n, t, s.get(), out.get());
    std::fwrite(out.get(), 1, n, stdout);
    std::putchar('\n');
}
