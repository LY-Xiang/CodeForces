#include<cstdio>

int main()
{
    constexpr char s[]{
        "codeforces"
    };
    int t;
    std::scanf("%d", &t);
    while (t--)
    {
        const char* p = s;
        int a{0};
        std::getchar();
        for (; p != s + 10; p++)
            if (std::getchar() != *p)++a;
        std::printf("%d\n", a);
    }
}
