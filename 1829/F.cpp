#include <cstdio>
#include <vector>

int main()
{
    unsigned t;
    for (std::scanf("%u", &t); t; --t)
    {
        unsigned n, m;
        std::scanf("%u%u", &n, &m);

        static std::vector<int> adj[201];
        for (unsigned i = 1; i <= n; ++i)
            adj[i].clear();

        for (unsigned i = 0; i < m; ++i)
        {
            unsigned u, v;
            std::scanf("%u%u", &u, &v);
            adj[u].push_back(static_cast<int>(v));
            adj[v].push_back(static_cast<int>(u));
        }

        // 度最小者必是叶子：叶子 1，中心 x >= 2，中间层 y + 1 >= 3
        unsigned v = 1;
        for (unsigned i = 2; i <= n; ++i)
            if (adj[i].size() < adj[v].size())
                v = i;

        // v 的唯一邻居 u 是中间层顶点，deg[u] = y + 1
        unsigned y = static_cast<unsigned>(adj[adj[v][0]].size()) - 1;

        // u 的邻居里唯一不是叶子的那个是中心，deg[center] = x
        unsigned x = 0;
        for (int w : adj[adj[v][0]])
            if (adj[w].size() > 1)
                x = static_cast<unsigned>(adj[w].size());

        std::printf("%u %u\n", x, y);
    }
    return 0;
}