// AWC0059D
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
template <class T>
void v_output(const std::vector<T> &a)
{
    for (int64_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
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
        int64_t INF = INT64_MAX / 2;
        std::vector<int64_t> costs(m_graph.size(), INF);
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
};

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, M, K;
    cin >> N >> M >> K;
    --K;
    vector<vector<Dijkstra::EDGE>> GRAPH(N);
    for (ll i = 0; i < M; ++i)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        GRAPH[u].push_back(Dijkstra::EDGE{.to = v, .cost = c});
        GRAPH[v].push_back(Dijkstra::EDGE{.to = u, .cost = c});
    }
    Dijkstra dij(GRAPH);
    vector<ll> costs = dij.calcCosts(K);
    ll front = costs[0];
    ll back = costs[N - 1];
    if (1000000000LL < front || 1000000000LL < back)
    {
        cout << -1 << endl;
        return;
    }
    std::cout << front + back << std::endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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