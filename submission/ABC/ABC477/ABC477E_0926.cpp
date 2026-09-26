// ABC477E
// template
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>

#include <map>
template <class KEY_TYPE, class VALUE_TYPE>
using TreeMap = std::map<KEY_TYPE, VALUE_TYPE>;
#include <unordered_map>
template <class KEY_TYPE, class VALUE_TYPE>
using HashMap = std::unordered_map<KEY_TYPE, VALUE_TYPE>;

#include <set>
template <class VALUE_TYPE>
using TreeSet = std::set<VALUE_TYPE>;
#include <unordered_set>
template <class VALUE_TYPE>
using HashSet = std::unordered_set<VALUE_TYPE>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
T input()
{
    T variable;
    cin >> variable;
    return variable;
}
template <typename T>
std::vector<T> input(int64_t n)
{
    std::vector<T> contents(n);
    for (int64_t i = 0; i < n; ++i)
    {
        contents[i] = input<T>();
    }
    return contents;
}
// 自作ライブラリここから
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

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力スニペ
    // const auto S = input<std::string>();
    // const auto A = input<ll>(N);
    //
    const auto N = input<ll>();
    const auto Q = input<ll>();
    const auto A = input<ll>(N);
    const auto B = input<ll>(N);
    struct QUERY
    {
        ll S;
        ll T;
    };
    vector<QUERY> queries(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> queries[i].S >> queries[i].T;
        --queries[i].S;
        --queries[i].T;
    }
    vector<vector<Dijkstra::EDGE>> GRAPH(N + 1);
    for (ll i = 0; i < N; ++i)
    {
        ll neig = ((i + 1) % (N));
        GRAPH[i].push_back(Dijkstra::EDGE{.to = neig, .cost = A[i]});
        GRAPH[neig].push_back(Dijkstra::EDGE{.to = i, .cost = A[i]});
        GRAPH[i].push_back(Dijkstra::EDGE{.to = N, .cost = B[i]});
        GRAPH[N].push_back(Dijkstra::EDGE{.to = i, .cost = B[i]});
    }
    Dijkstra dijk(GRAPH);
    for (auto &query : queries)
    {
        ll s = query.S;
        ll t = query.T;
        auto result = dijk.calcCosts(s);
        cout << result[t] << endl;
    }
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t TESTCASES = DEFAULT_TESTCASE;
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

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
