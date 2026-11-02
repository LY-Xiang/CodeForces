#include <cstddef>
#include <cstdint>
#include <cstdio>

namespace
{
    struct Tbl
    {
        std::uint32_t v[256];

        constexpr Tbl() : v{}
        {
            for (unsigned c{0}; c < 256; ++c)
            {
                const unsigned u{(c | 32u) - 'a'};
                v[c] = u < 26 ? 1u << u : 0u;
            }
        }
    };

    constexpr Tbl T{};
}

int main()
{
    static char buf[112];
    const std::size_t len{std::fread(buf, 1, sizeof buf, stdin)};

    std::size_t p{0};
    while (p < len && buf[p] < '0') ++p;
    unsigned n{0};
    while (p < len && buf[p] >= '0' && buf[p] <= '9')
        n = n * 10 + static_cast<unsigned>(buf[p++] - '0');
    ++p;

    if (n < 26)
    {
        std::puts("NO");
        return 0;
    }

    const std::size_t e{p + n < len ? p + n : len};
    std::uint32_t m{0};
    for (; p < e; ++p)
        m |= T.v[static_cast<unsigned char>(buf[p])];
    std::puts(m == 0x3FFFFFFu ? "YES" : "NO");
}
