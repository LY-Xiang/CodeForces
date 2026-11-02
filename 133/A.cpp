#include <iostream>
#include <string>

int main()
{
    std::string p;
    if (!(std::cin >> p)) return 0;

    // H prints Hello World, Q prints the source, 9 prints the song.  '+' only
    // bumps the accumulator, so it produces no output and does not count.
    for (const char c : p)
    {
        if (c == 'H' || c == 'Q' || c == '9')
        {
            std::cout << "YES\n";
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}