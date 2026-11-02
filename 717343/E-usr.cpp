#include <algorithm>
#include <cstdio>
#include <vector>

namespace
{
    struct lake;
    struct lake_pair
    {
        unsigned long long pv;
        lake* l;
    };
    struct lake
    {
        std::vector<lake_pair> p;
        void merge(lake *t)
        {
            for (auto & [pv,l]:p)
            {
                l=t;
            }
            t->p.append_range(p);
        }
    };
    typedef std::vector<lake> lake_set;

}

int main()
{
    int t;
    if (std::scanf("%d", &t) != 1) return 0;

    while (t--)
    {
        int n, m;
        if (std::scanf("%d%d", &n, &m) != 2) return 0;

        lake_set s;
        std::vector<lake_pair*> a(m);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                int v;
                if (std::scanf("%d", &v) != 1) return 0;
                if (v == 0) continue;
                lake_pair* at=a[j],
                            *pv=j?a[j-1]:nullptr;

                lake_pair* root;
                if (!at && !pv)  root = nullptr;                   // 还没起过湖
                else if (!at)    root = pv;
                else if (!pv||at==pv)    root = at;
                else
                {
                    pv->l->merge(at->l);
                    root = at;
                }

                if (root) a[j] = root;
                else //新湖
                {
                    s.emplace_back(lake());
                    lake* l=&s.back();
                    l->p.emplace_back(lake_pair());
                    a[j]=&l->p.back();
                }
            }

    }
    return 0;
}
