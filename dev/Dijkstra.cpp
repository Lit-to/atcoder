#include <vector>
#include <cstdint>
#include <unordered_map>
#include <queue>

template <class Func>

std::vector<uint64_t> calcEdgeCost(int64_t startNode, std::unordered_map<int64_t, int64_t> graph, std::vector<uint64_t> weights, Func eval) // 評価関数もつけること
{
    std::priority_queue<int64_t, func> queue;
    queue.push(startNode);
    while (!queue.empty())
    {
    }
}
