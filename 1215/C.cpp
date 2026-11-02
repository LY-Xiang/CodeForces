// 1215C -- Swap Letters.
//
// One operation picks pos1 in s and pos2 in t, independently, and exchanges
// s[pos1] with t[pos2]; pos1 == pos2 is legal and the setter's own first
// sample uses it.  Let A be the number of indices with s[i]=='a' && t[i]=='b'
// and B those with the pair reversed.  A and B need not be equal: an operation
// moves letters between the two strings, so s="aa", t="bb" has A=2, B=0 and is
// still solved by one swap.
//
// Feasible iff A + B is even.  Each operation preserves the total count of 'a'
// across both strings, which is A + B + 2*(indices holding "aa"); s == t forces
// that total to be even.  The constructions below show even is also sufficient.
//
// Minimum is (A + B) / 2, plus one when A is odd.  An operation changes at most
// two indices, and it nets two only when they are distinct and of the same
// type: pairing a type-A index with a type-B one leaves s[i] holding 'a'
// against t[i]=='b', and pos1 == pos2 just turns the index into the other
// type.  Same-type pairing is therefore the only way to retire two indices per
// operation, and it retires an even number of each type.  A odd (hence B odd
// too) needs one operation to move a single index across instead, which is the
// (pos,pos) exchange on the leftover index: it turns a type-A index into a
// type-B one, leaving A-1 and B+1, both even.
#include <cstddef>
#include <cstdio>

namespace {

// "200000\n" plus the two strings plus two newlines is 400009 bytes.  One fread
// of a fixed buffer replaces the ~400000 getchar() calls the obvious reading
// makes, and it leaves both strings in place for the second pass -- so the
// solution never allocates an index array at all.
constexpr std::size_t kIn = 1u << 20;

// The answer is at most 100001 lines of at most 14 bytes, about 1.4 MB.  Holding
// all of it would cost 341 first-touch page faults to no purpose, so build it
// in cache-sized pieces instead.  kOut only has to leave room for the longest
// line's growth below.
constexpr std::size_t kOut = 1u << 16;

char in[kIn];
char out[kOut];
char* o = out;
char* const oend = out + kOut;

void flush()
{
    std::fwrite(out, 1, static_cast<std::size_t>(o - out), stdout);
    o = out;
}

inline char* put(char* q, unsigned v)
{
    char tmp[8];
    int m = 0;
    do { tmp[m++] = static_cast<char>('0' + v % 10); v /= 10; } while (v);
    while (m) *q++ = tmp[--m];
    return q;
}

// One swap line: the first index is read in s, the second in t.
inline char* pair(char* q, int a, int b)
{
    q = put(q, static_cast<unsigned>(a));
    *q++ = ' ';
    q = put(q, static_cast<unsigned>(b));
    *q++ = '\n';
    return q;
}

}  // namespace

int main()
{
    const std::size_t len = std::fread(in, 1, sizeof in, stdin);
    char* p = in;
    const char* const end = in + len;

    // Skipping every byte <= ' ' rather than one newline keeps the parse correct
    // under CRLF as well as LF.
    while (p < end && static_cast<unsigned char>(*p) <= ' ') ++p;
    int n = 0;
    while (p < end && *p >= '0' && *p <= '9') n = n * 10 + (*p++ - '0');
    while (p < end && static_cast<unsigned char>(*p) <= ' ') ++p;
    char* const s = p;
    p += n;
    while (p < end && static_cast<unsigned char>(*p) <= ' ') ++p;
    char* const t = p;

    // Branchless, and no branch on whether the two strings agree.  mism is
    // enough to decide feasibility, so B is never needed.
    int a = 0, mism = 0;
    for (int i = 0; i < n; ++i)
    {
        const int xs = s[i] == 'a';
        const int xt = t[i] == 'a';
        mism += xs ^ xt;
        a += xs & (1 - xt);
    }

    if (mism & 1)
    {
        std::fputs("-1\n", stdout);
        return 0;
    }

    o = put(o, static_cast<unsigned>(mism / 2 + (a & 1)));
    *o++ = '\n';

    // Stream the pairs straight out of the input: rescan s and t and keep only
    // the one unmatched index per type.  When A is odd exactly one index per
    // type survives the scan, and the two closing lines use it.
    int pa = -1, pb = -1;
    for (int i = 0; i < n; ++i)
    {
        const char x = s[i], y = t[i];
        if (x == y) continue;
        if (x == 'a')
        {
            if (pa < 0) pa = i + 1;
            else
            {
                if (o + 32 >= oend) flush();
                o = pair(o, pa, i + 1);
                pa = -1;
            }
        }
        else
        {
            if (pb < 0) pb = i + 1;
            else
            {
                if (o + 32 >= oend) flush();
                o = pair(o, pb, i + 1);
                pb = -1;
            }
        }
    }
    if (pa > 0)
    {
        if (o + 64 >= oend) flush();
        // (pa, pa) turns the leftover type-A index into type B; (pa, pb) then
        // retires two same-type indices at once.
        o = pair(o, pa, pa);
        o = pair(o, pa, pb);
    }

    flush();
    return 0;
}