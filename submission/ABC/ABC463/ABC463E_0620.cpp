// ABC463E
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#include <vector>
#include <cstdint>
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
            return cost == rhs.cost ? to > rhs.to : cost > rhs.cost;
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
            for (const EDGE &nextEdge : m_graph[pos.to])
            {
                int64_t nextCost = pos.cost + nextEdge.cost;
                if (nextCost < costs[nextEdge.to])
                {
                    costs[nextEdge.to] = nextCost;
                    gpq.push({.to = nextEdge.to, .cost = nextCost});
                }
            }
        }
        return costs;
    }
    std::vector<std::vector<EDGE>> m_graph; //<! 隣接リスト
    int64_t m_graphSize;                    //<! グラフの頂点数
    const int64_t m_INF = (int64_t)1e18;    //<! コストの上限値
};

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, M, Y;
    cin >> N >> M >> Y;
    struct inp
    {
        ll u, v, T;
    };
    vector<inp> INPUT_NODES(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> INPUT_NODES[i].u;
        cin >> INPUT_NODES[i].v;
        cin >> INPUT_NODES[i].T;
        --INPUT_NODES[i].u;
        --INPUT_NODES[i].v;
    }
    vector<ll> X(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> X[i];
    }
    vector<vector<Dijkstra::EDGE>> graph(N + 2);
    for (ll i = 0; i < M; ++i)
    {
        ll u = INPUT_NODES[i].u;
        ll v = INPUT_NODES[i].v;
        ll T = INPUT_NODES[i].T;
        graph[u].push_back(Dijkstra::EDGE{.to = v, .cost = T});
        graph[v].push_back(Dijkstra::EDGE{.to = u, .cost = T});
    }
    graph[N].push_back(Dijkstra::EDGE{.to = N + 1, .cost = Y});
    for (ll i = 0; i < N; ++i)
    {
        graph[i].push_back(Dijkstra::EDGE{.to = N, .cost = X[i]});
        graph[N + 1].push_back(Dijkstra::EDGE{.to = i, .cost = X[i]});
    }
    Dijkstra dijk(graph);
    auto result = dijk.calcCosts(0);
    for (ll i = 1; i < N; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t TESTCASES = 1;

    // std::cin >> TESTCASES;

    for (int64_t i = 0; i < TESTCASES; ++i)
    {
        solve();
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================