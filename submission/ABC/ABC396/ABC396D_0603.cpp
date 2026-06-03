// ABC396D
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

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, M;
    cin >> N >> M;
    /**
     * @brief グラフの辺情報
     */
    struct EDGE
    {
        int64_t destination; // 隣の行先ノード
        int64_t label;       // そのノードのラベル
    };

    vector<vector<EDGE>> GRAPH(N);
    for (ll i = 0; i < M; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        GRAPH[u].push_back(EDGE{.destination = v, .label = w});
        GRAPH[v].push_back(EDGE{.destination = u, .label = w});
    }
    ll result = INT64_MAX;
    ll now = 0;
    vector<bool> done(N);
    auto dfs = [&](auto &self, ll node) -> void
    {
        if (node == N - 1)
        {
            result = min(now, result);
            return;
        }
        for (ll i = 0; i < GRAPH[node].size(); ++i)
        {
            if (done[GRAPH[node][i].destination])
            {
                continue;
            }
            done[node] = true;
            now ^= GRAPH[node][i].label;
            self(self, GRAPH[node][i].destination);
            done[node] = false;
            now ^= GRAPH[node][i].label;
        }
    };
    dfs(dfs, 0);
    cout << result << endl;
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