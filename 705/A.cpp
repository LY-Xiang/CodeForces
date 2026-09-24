#include<cstdio>

static inline void putb(char*& o, const char* s)
{
    for (int k{0}; s[k]; *o++ = s[k++]);
}

int main()
{
    unsigned n;
    std::scanf("%u", &n);
    static char out[1024];
    char* o{out};
    for (unsigned i{1}; i < n; ++i)
    {
        putb(o, "I ");
        putb(o, i & 1 ? "hate" : "love");
        putb(o, " that ");
    }
    putb(o, "I ");
    putb(o, n & 1 ? "hate" : "love");
    putb(o, " it");
    std::fwrite(out, 1, o - out, stdout);
}
