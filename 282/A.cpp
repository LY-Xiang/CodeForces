#include <cstdio>

int main()
{
    signed short x{0};
    for (char c; (c = std::getchar()) != EOF;)
    {
        if (c == '+')
        {
            ++x;
            std::getchar();
        }
        else if (c == '-')
        {
            --x;
            std::getchar();
        }
    }
    std::printf("%hd", x);
}