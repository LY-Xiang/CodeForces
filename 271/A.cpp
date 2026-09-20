#include <bitset>
#include <cstdio>

int main()
{
    std::bitset<10> b;
    unsigned a;
    std::scanf("%u", &a);
    const unsigned d1{a / 1000}, d2{a / 100 % 10}, d3{a / 10 % 10}, d4{a % 10};
    b.set(d1);
    b.set(d2);
    b.set(d3);
    if (d3 != d2 && d3 != d1 && d2 != d1)
        for (unsigned d{d4}; (++d) != 10;)
            if (!b.test(d))
            {
                std::printf("%u", a / 10 * 10 + d);
                return 0;
            }

    b.reset();
    b.set(d1);
    b.set(d2);
    if (d2 != d1)
        for (unsigned d{d3}; (++d) != 10;)
            if (!b.test(d))
            {
                b.set(d);
                for (unsigned t{0}; true; ++t)
                    if (!b.test(t))
                    {
                        std::printf("%u", a / 100 * 100 + d * 10 + t);
                        return 0;
                    }
            }


    b.reset();
    b.set(d1);
    for (unsigned d{d2}; (++d) != 10;)
        if (!b.test(d))
        {
            b.set(d);
            for (unsigned t{0}; true; ++t)
                if (!b.test(t))
                    for (unsigned t1{t + 1}; true; ++t1)
                        if (!b.test(t1))
                        {
                            std::printf("%u", d1 * 1000 + d * 100 + t * 10 + t1);
                            return 0;
                        }
        }

    b.reset();
    b.set(d1 + 1);
    for (unsigned t{0}; true; ++t)
        if (!b.test(t))
            for (unsigned t1{t + 1}; true; ++t1)
                if (!b.test(t1))
                    for (unsigned t2{t1 + 1}; true; ++t2)
                        if (!b.test(t2))
                        {
                            std::printf("%u", (d1 + 1) * 1000 + t * 100 + t1 * 10 + t2);
                            return 0;
                        }
}
