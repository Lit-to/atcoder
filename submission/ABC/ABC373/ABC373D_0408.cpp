// ABC373D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cassert>
//
int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    struct nextTo
    {
        int64_t node;
        int64_t weight;
    };
    std::vector<std::vector<nextTo>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v, w;
        std::cin >> u >> v >> w;
        GRAPH[u - 1].push_back(nextTo{.node = v - 1, .weight = w});
        GRAPH[v - 1].push_back(nextTo{.node = u - 1, .weight = w * -1});
    }
    std::vector<int64_t> result(N, 0);
    std::vector<bool> done(N);
    auto dfs = [&](auto &&dfs, int64_t node, int64_t weight) -> void
    {
        result[node] = weight;
        done[node] = true;
        for (nextTo &i : GRAPH[node])
        {
            if (done[i.node])
            {
                // assert(result[i.node] == weight + i.weight);
                continue;
            }
            dfs(dfs, i.node, weight + i.weight);
        }
    };
    for (int64_t i = 0; i < N; ++i)
    {
        if (done[i])
        {
            continue;
        }
        dfs(dfs, i, 0);
    }
    for (int64_t i : result)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================