#include <bitset>
#include <cctype>
#include <cstdio>

int main() {
  std::bitset<26> l;
  for (char a; std::isalpha(a = std::getchar()); l.set(a - 'a'))
    ;
  std::puts(l.count() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
}
