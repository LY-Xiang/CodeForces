#include <cctype>
#include <cstdio>

int main() {
  char a[100 + 1], b, *p{a};
  for (std::scanf("%s%*c", a); *p != '\0'; ++p)
    if ((b = std::toupper(std::getchar())) != (*p = std::toupper(*p))) {
      if (*p < b)
        std::putchar('-');
      std::putchar('1');
      return 0;
    }
  std::putchar('0');
}
