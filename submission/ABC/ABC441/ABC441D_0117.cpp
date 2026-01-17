// ABC441D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <queue>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

int main()
{
    int64_t N, M, L, S, T;
    std::cin >> N >> M >> L >> S >> T;
    struct node
    {
        int64_t distination;
        int64_t cost;
    };
    std::vector<std::vector<node>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v, c;
        std::cin >> u >> v >> c;
        --u;
        --v;
        GRAPH[u].push_back(node{.distination = v, .cost = c});
    }
    struct item
    {
        int64_t node;
        int64_t cost;
        int64_t count;
    };
    std::queue<item> queue;
    std::vector<bool> result(N);
    queue.push(item{.node = 0, .cost = 0, .count = 0});
    while (!queue.empty())
    {
        item &pos = queue.front();
        queue.pop();
        ++pos.count;
        for (node &dist : GRAPH[pos.node])
        {
            int64_t newCost = pos.cost + dist.cost;
            if (pos.count == L && S <= newCost && newCost <= T)
            {
                result[dist.distination] = true;
                continue;
            }
            if (pos.count < L && newCost < T)
            {
                queue.push(item{
                    .node = dist.distination,
                    .cost = newCost,
                    .count = pos.count,
                });
            }
        }
    }
    for (int64_t i = 0; i < N; ++i)
    {
        if (result[i])
        {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;
}