// DFS001K
// ARC037B
// clang-format off
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cin;using std::cout;using std::endl;using std::vector;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on
/**
 * @brief グラフの辺情報
 */
struct EDGE
{
    int64_t u;
    int64_t v;
};
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    const auto N = input<ll>();
    const auto M = input<ll>();
    vector<EDGE> edges(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> edges[i].u >> edges[i].v;
        --edges[i].u;
        --edges[i].v;
    }
    vector<vector<ll>> GRAPH(N);
    for (ll i = 0; i < M; ++i)
    {
        GRAPH[edges[i].u].push_back(edges[i].v);
        GRAPH[edges[i].v].push_back(edges[i].u);
    }
    vector<ll> done(N);
    /**
     * DFSスニペット
     */
    auto dfs = [&](auto self, ll par, ll pos) -> bool // 引数にノード、戻り値は適度に
    {
        // 訪問済み管理のチェック
        if (done[pos])
        {
            return false;
        }

        // 訪問済み管理の登録
        done[pos] = true;
        // 行きがけ順に処理したい内容

        for (auto &dest : GRAPH[pos]) // 遷移処理
        {
            if (par == dest)
            {
                continue;
            }
            if (!self(self, pos, dest))
            {
                return false;
            }
        }
        // 帰りがけ順に処理したい内容
        return true;
    };
    ll result = 0;
    for (ll i = 0; i < N; ++i)
    {
        result += dfs(dfs, -1, i);
    }
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
