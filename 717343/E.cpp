#include <algorithm>
#include <cstdio>
#include <vector>

namespace
{
    struct lake_set
    {
        std::vector<int> p;         // 父指针，p[x] == x 表示 x 是根
        std::vector<long long> s;   // s[根] == 该集合的蓄水量

        lake_set()
        {
            p.push_back(0);         // 下标 0 留作占位：标签 0 在 a[] 里表示"没有水"，
            s.push_back(0);         // 不能拿来当湖的编号
        }

        int make(long long v)
        {
            p.push_back(static_cast<int>(p.size()));
            s.push_back(v);
            return static_cast<int>(p.size()) - 1;
        }

        int find(int x)
        {
            return p[x] == x ? x : p[x] = find(p[x]);
        }

        // 合并后 b 的根指向 a，两个集合的水量直接加到 a 的根上，
        // 不需要像原来那样把合并记录下来再倒序补算
        void uni(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (s[a] < s[b]) std::swap(a, b);   // 按水量小的挂到大的下面
            p[b] = a;
            s[a] += s[b];
        }
    };
}

int main()
{
    int t;
    if (std::scanf("%d", &t) != 1) return 0;

    while (t--)
    {
        int n, m;
        if (std::scanf("%d%d", &n, &m) != 2) return 0;

        lake_set u;
        std::vector<int> a(n * m, 0);   // a[] 存标签，0 表示没有水

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                int v;
                if (std::scanf("%d", &v) != 1) return 0;   // 读失败就直接退出，
                const int at = i * m + j;                  // 别让 v 保留上一格的脏值
                if (v == 0) continue;

                const int up = i ? a[(i - 1) * m + j] : 0;   // 上
                const int lf = j ? a[i * m + j - 1] : 0;      // 前

                int root;
                if (!up && !lf)  root = -1;                   // 还没起过湖
                else if (!up)    root = u.find(lf);
                else if (!lf)    root = u.find(up);
                else                                           // 上和前都在，合并
                {
                    u.uni(up, lf);
                    root = u.find(up);
                }

                if (root < 0) a[at] = u.make(v);              // 新的湖
                else
                {
                    a[at] = root;
                    u.s[root] += v;                            // 并入已有湖泊的蓄水量
                }
            }

        long long ans = 0;
        for (std::size_t k = 0; k < u.p.size(); ++k)
            if (u.find(k) == static_cast<int>(k)) ans = std::max(ans, u.s[k]);

        std::printf("%lld\n", ans);
    }
    return 0;
}
