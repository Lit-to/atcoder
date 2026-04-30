#include <vector>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <queue>
template <typename T>
using GreaterPriorityQueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
class Dijkstra
{
public:
    struct EDGE
    {
        int64_t to;
        int64_t cost;
        bool operator>(const EDGE &rhs) const
        {
            return cost > rhs.cost;
        };
    };
    Dijkstra(const std::vector<std::vector<EDGE>> &GRAPH)
    {
        m_graph = GRAPH;
        m_graphSize = m_graph.size();
    }
    std::vector<int64_t> calcCosts(int64_t start)
    {
        std::vector<int64_t> costs(m_graph.size(), m_INF);
        costs[start] = 0;
        GreaterPriorityQueue<EDGE> gpq;
        gpq.push({.to = start, .cost = costs[start]});
        while (!gpq.empty())
        {
            EDGE pos = gpq.top();
            gpq.pop();
            if (costs[pos.to] < pos.cost)
            {
                continue;
            }
            for (const EDGE &nextNode : m_graph[pos.to])
            {
                int64_t nextCost = pos.cost + nextNode.cost;
                if (nextCost < costs[nextNode.to])
                {
                    costs[nextNode.to] = nextCost;
                    gpq.push({.to = nextNode.to, .cost = nextCost});
                }
            }
        }
        return costs;
    }
    std::vector<std::vector<EDGE>> m_graph;
    int64_t m_graphSize;
    const int64_t m_INF = (int64_t)1e18;
};
