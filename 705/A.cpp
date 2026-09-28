#include <cstdio>
#include <cstring>
#include <cstddef>

int main()
{
    unsigned n{};
    if (std::scanf("%u", &n) != 1) return 0;

    static char out[12 * 100 - 3];
    char* p{out};
    std::memcpy(p, "I hate", 6);
    p += 6;
    for (unsigned i{2}; i <= n; ++i)
    {
        std::memcpy(p, i & 1U ? " that I hate" : " that I love", 12);
        p += 12;
    }
    std::memcpy(p, " it", 3);
    p += 3;
    std::fwrite(out, 1, static_cast<std::size_t>(p - out), stdout);
    return 0;
}
