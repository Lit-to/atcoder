#include <vector>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <queue>

template <class Func>

std::vector<int64_t> calctaskCost(int64_t startNode, std::unordered_map<int64_t, std::vector<int64_t>> graph, std::vector<uint64_t> costs, Func eval) // 評価関数もつけること
{
    struct task
    {
        int64_t m_node; //! 頂点
        int64_t m_cost; //! その頂点までの現在の最短コスト
        bool operator<(const task &rhs) const
        {
            return m_cost > rhs.m_cost;
        }
    };
    std::priority_queue<task> tasks;
    tasks.push(task{.m_node = 0, .m_cost = 0});
    std::unordered_set<int64_t> done;
    std::vector<int64_t> results(-1);
    while (!tasks.empty())
    {
        task pos = tasks.top();
        done.insert(pos.m_node);
        tasks.pop();
        for (task i : graph[pos.m_node])
        {
            if (!done.contains(i))
            {
                tasks.push(task{.m_node = i, .m_cost = costs[i] + pos.m_cost});
            }
        }
    }
    return results;
}
