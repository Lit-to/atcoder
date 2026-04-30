#include <vector>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <queue>
template <typename T>
using GreaterPriorityQueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
/**
 * @brief ダイクストラ法をするためのクラス
 */
class Dijkstra
{
public:
    struct EDGE
    {
        int64_t to;   //<! 行先となりのノード
        int64_t cost; //<! 距離(コスト)
        /**
         * @brief 比較演算子オーバーロード
         */
        bool operator>(const EDGE &rhs) const
        {
            return cost > rhs.cost;
        };
    };
    /**
     * @brief コンストラクタ
     * @details 隣接リストを渡して初期化を行う
     * @param GRAPH 検索したい隣接リスト
     */
    Dijkstra(const std::vector<std::vector<EDGE>> &GRAPH)
    {
        m_graph = GRAPH;
        m_graphSize = m_graph.size();
    }
    /**
     * @brief 全ての頂点についてコスト計算を行う
     * @details 探索開始ノードのコストを0としたときの全てのノードへの最小コストを計算する
     * @param start 探索開始ノード
     */
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
    std::vector<std::vector<EDGE>> m_graph; //<! 隣接リスト
    int64_t m_graphSize;                    //<! グラフの頂点数
    const int64_t m_INF = (int64_t)1e18;    //<! コストの上限値
};
