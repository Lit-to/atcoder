#include <vector>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// template <class Func>
std::vector<int64_t> calctaskCost(int64_t startNode, std::vector<std::vector<int64_t>> graph, std::vector<int64_t> costs)
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
    tasks.push(task{.m_node = startNode, .m_cost = 0});
    std::unordered_set<int64_t> done;
    std::vector<int64_t> results(graph.size(), INT64_MAX);
    while (!tasks.empty())
    {
        task pos = tasks.top();
        tasks.pop();
        results[pos.m_node] = std::min(results[pos.m_node], pos.m_cost + costs[pos.m_node]);
        done.insert(pos.m_node);
        for (int64_t i : graph[pos.m_node])
        {
            if (!done.contains(i))
            {
                done.insert(i);
                tasks.push(task{.m_node = i, .m_cost = pos.m_cost});
            }
        }
    }
    return results;
}
// int main() { return 0; }
