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

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, M, K;
    cin >> N >> M >> K;
    struct EDGE
    {
        ll to;
        ll cost;
    };
    --K;
    vector<vector<EDGE>> GRAPH(N);
    for (ll i = 0; i < M; ++i)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        GRAPH[u].push_back(EDGE{.to = v, .cost = c});
        GRAPH[v].push_back(EDGE{.to = u, .cost = c});
    }
    auto dijkstra = [&](ll start) -> vector<ll>
    {
        struct node
        {
            ll to;
            ll cost;
            bool operator>(const node &rhs) const
            {
                return cost > rhs.cost;
            };
        };
        vector<ll> costs(N, INT64_MAX);
        costs[start] = 0;
        greater_priority_queue<node> gpq;
        gpq.push({.to = start, .cost = 0});
        while (!gpq.empty())
        {
            node pos = gpq.top();
            gpq.pop();
            if (costs[pos.to] < pos.cost)
            {
                continue;
            }
            for (const EDGE &nextNode : GRAPH[pos.to])
            {
                ll nextCost = pos.cost + nextNode.cost;
                if (nextCost < costs[nextNode.to])
                {
                    costs[nextNode.to] = nextCost;
                    gpq.push({.to = nextNode.to, .cost = nextCost});
                }
            }
        }
        return costs;
    };
    vector<ll> costs = dijkstra(K);
    ll front = costs[0];
    ll back = costs[N - 1];
    if (front == INT64_MAX || back == INT64_MAX)
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