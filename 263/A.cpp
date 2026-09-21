#include <cstdio>

int main()
{
    for (unsigned r{0}; r != 5; ++r)
        for (unsigned c{0}; c != 5; ++c)
        {
            if (std::getchar() == '1')
            {
                std::printf("%u", (r > 2 ? r - 2 : 2 - r) + (c > 2 ? c - 2 : 2 - c));
                return 0;
            }
            std::getchar();
        }
}
