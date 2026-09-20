#include <cstdio>

int main()
{
    int x{0};
    for (int c; (c = std::getchar()) != EOF;)
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
