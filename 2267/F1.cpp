#include <algorithm>
#include <bit>
#include <cstdio>
#include <vector>

namespace
{
    class FastInput
    {
        static constexpr int kBufferSize = 1 << 16;
        char buffer_[kBufferSize];
        int size_ = 0;
        int pos_ = 0;

        int get()
        {
            if (pos_ == size_)
            {
                size_ = static_cast<int>(std::fread(buffer_, 1, kBufferSize, stdin));
                pos_ = 0;
                if (size_ == 0) return -1;
            }
            return static_cast<unsigned char>(buffer_[pos_++]);
        }

    public:
        // Every number of this problem is non-negative; -1 marks end of input.
        int read()
        {
            int c;
            do
            {
                c = get();
            } while (c != -1 && c <= ' ');
            if (c == -1) return -1;
            int value = 0;
            while (c >= '0' && c <= '9')
            {
                value = value * 10 + (c - '0');
                c = get();
            }
            return value;
        }
    };

    // a must be sorted; returns #{i < j : a[i] ^ a[j] < (1 << shift)}.
    long long pairs_below(const std::vector<int>& a, int shift)
    {
        long long total = 0;
        long long run = 1;
        for (std::size_t i = 1; i < a.size(); ++i)
        {
            if ((a[i] >> shift) == (a[i - 1] >> shift))
            {
                ++run;
            }
            else
            {
                total += run * (run - 1) / 2;
                run = 1;
            }
        }
        return total + run * (run - 1) / 2;
    }

    // Appends a[i] ^ a[j] for every i < j sharing the same a[.]>>shift prefix.
    // Such a pair agrees above shift, so every appended value is below 1 << shift.
    void collect_below(const std::vector<int>& a, int shift, std::vector<int>& out)
    {
        out.clear();
        const int n = static_cast<int>(a.size());
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n && (a[j] >> shift) == (a[i] >> shift)) ++j;
            for (int u = i; u < j; ++u)
            {
                const int value = a[u];
                for (int v = u + 1; v < j; ++v) out.push_back(value ^ a[v]);
            }
            i = j;
        }
    }

    // Least significant digit radix sort; every element must be below 1 << bits.
    void radix_sort(std::vector<int>& values, std::vector<int>& scratch, int bits)
    {
        constexpr int kDigitBits = 11;
        constexpr int kRadix = 1 << kDigitBits;
        static int count[kRadix];
        scratch.resize(values.size());
        for (int shift = 0; shift < bits; shift += kDigitBits)
        {
            std::fill(count, count + kRadix, 0);
            for (const int x : values) ++count[(x >> shift) & (kRadix - 1)];
            int prefix = 0;
            for (int digit = 0; digit < kRadix; ++digit)
            {
                const int run = count[digit];
                count[digit] = prefix;
                prefix += run;
            }
            for (const int x : values) scratch[count[(x >> shift) & (kRadix - 1)]++] = x;
            values.swap(scratch);
        }
    }

    // Radix pays for its 2^11 counter clear only once the arrays are big.
    void sort_values(std::vector<int>& values, std::vector<int>& scratch, int bits)
    {
        if (values.size() < 512)
        {
            std::sort(values.begin(), values.end());
        }
        else
        {
            radix_sort(values, scratch, bits);
        }
    }

    void append(std::vector<char>& out, int value, bool last)
    {
        char digits[12];
        int length = 0;
        do
        {
            digits[length++] = static_cast<char>('0' + value % 10);
            value /= 10;
        } while (value > 0);
        while (length > 0) out.push_back(digits[--length]);
        out.push_back(last ? '\n' : ' ');
    }
}

int main()
{
    FastInput input;
    std::vector<char> output;
    output.reserve(1 << 16);

    int t = input.read();
    if (t < 0) return 0;

    std::vector<int> pairs;
    std::vector<int> scratch;

    while (t--)
    {
        const int n = input.read();
        const int q = input.read();

        std::vector<int> a(n);
        for (int& value : a) value = input.read();

        std::vector<int> queries(q);
        int max_query = 0;
        for (int& x : queries)
        {
            x = input.read();
            max_query = std::max(max_query, x);
        }

        const auto [min_it, max_it] = std::minmax_element(a.begin(), a.end());
        const int initial_range = *max_it - *min_it;
        const int bits = std::bit_width(static_cast<unsigned>(*max_it));

        if (max_query == 0 || initial_range == 0)
        {
            for (int i = 0; i < q; ++i) append(output, initial_range, i + 1 == q);
            continue;
        }

        // A transformation never keeps the top set bit.  Splitting the array by
        // that bit, C(s,2)+C(n-s,2) pairs agree on it, and that count is
        // minimised at s = n/2: it is 6 at n = 6 and grows from there, so for
        // n >= 6 at least n pairs agree and the n smallest XORs all lie below
        // the bit.  For n == 5 the minimum is only C(2,2)+C(3,2) = 4 < 5, but
        // such a step leaves four elements below the bit and exactly one above
        // it, so the next step does drop it.  2 * bits steps always suffice.
        const int limit = std::min(max_query, 2 * bits);

        sort_values(a, scratch, bits);

        std::vector<int> next(n);
        std::vector<int> answer(limit + 1);
        answer[0] = initial_range;
        pairs.reserve(static_cast<std::size_t>(n) * 3);
        scratch.reserve(static_cast<std::size_t>(n) * 3);
        int last = 0;

        for (int step = 1; step <= limit; ++step)
        {
            // Smallest shift with at least n pairs below 1 << shift.  Those
            // pairs are exactly the ones inside a run of a[.]>>shift, and they
            // hold the n smallest XORs, so no pair outside them can be kept.
            // Fewer than 2.5n of them exist: each such run is a union of two
            // runs of a[.]>>(shift-1), and those hold fewer than n pairs.
            int low = 0;
            int high = std::bit_width(static_cast<unsigned>(a.back()));
            while (low < high)
            {
                const int mid = low + (high - low) / 2;
                if (pairs_below(a, mid) >= n) high = mid; else low = mid + 1;
            }

            // Shift 0 means at least n equal pairs: the next array is all zeros.
            if (low == 0)
            {
                answer[step] = 0;
                last = step;
                break;
            }

            collect_below(a, low, pairs);
            sort_values(pairs, scratch, low);
            std::copy_n(pairs.begin(), n, next.begin());

            answer[step] = next.back() - next.front();
            last = step;

            if (answer[step] == 0 || next == a) break;
            a.swap(next);
        }

        for (int i = 0; i < q; ++i)
        {
            append(output, answer[std::min(queries[i], last)], i + 1 == q);
        }
    }

    std::fwrite(output.data(), 1, output.size(), stdout);
    return 0;
}
