#include <cstdio>
#include <cmath>

int main()
{
    unsigned a, b;
    std::scanf("%u%u", &a, &b);
    std::printf(
        "%u", 1 + static_cast<unsigned>(std::log(static_cast<double>(b) / a) / std::log(1.5)));
}
