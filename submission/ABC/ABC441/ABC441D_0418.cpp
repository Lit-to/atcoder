// ABC441D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
int main()
{
    int64_t N, M, L, S, T;
    std::cin >> N >> M >> L >> S >> T;
    struct EDGE
    {
        int64_t distination;
        int64_t cost;
    };
    std::vector<std::vector<EDGE>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v, c;
        std::cin >> u >> v >> c;
        --u;
        --v;
        GRAPH[u].push_back(EDGE{.distination = v, .cost = c});
        // GRAPH[v].push_back(EDGE{.distination = u, .cost = c});
    }
    std::vector<bool> result(N);
    auto dfs = [&](auto self, int64_t node, int64_t cost, int64_t count) -> void
    {
        if (T < cost)
        {
            return;
        }
        if (count == L)
        {
            if (S <= cost)
            {
                result[node] = true;
            }
            return;
        }
        for (int i = 0; i < GRAPH[node].size(); ++i)
        {
            int64_t newCost = cost + GRAPH[node][i].cost;
            if (T < newCost)
            {
                continue;
            }
            self(self, GRAPH[node][i].distination, newCost, count + 1);
        }
    };
    dfs(dfs, 0, 0, 0);
    for (int64_t i = 0; i < N; ++i)
    {
        if (result[i])
        {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================