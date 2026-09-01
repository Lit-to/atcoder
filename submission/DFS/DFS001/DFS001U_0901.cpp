// DFS001U
// ABC373D
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
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力スニペ
    // const auto S = input<std::string>();
    // const auto A = input<ll>(N);
    //
    const auto N = input<ll>();
    const auto M = input<ll>();
    struct EDGE
    {
        ll U;
        ll V;
        ll W;
    };
    vector<EDGE> edges(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> edges[i].U >> edges[i].V >> edges[i].W;
        --edges[i].U;
        --edges[i].V;
    }
    struct POINT
    {
        ll to;
        ll number;
    };
    vector<vector<POINT>> GRAPH(N);
    for (ll i = 0; i < M; ++i)
    {
        GRAPH[edges[i].U].push_back(POINT{.to = edges[i].V, .number = edges[i].W});
        GRAPH[edges[i].V].push_back(POINT{.to = edges[i].U, .number = -1 * edges[i].W});
    }
    vector<ll> costs(N);
    vector<bool> done(N);
    /**
     * DFSスニペット
     */
    auto dfs = [&](auto self, ll pos, ll cost) -> void // 引数にノード、戻り値は適度に
    {
        // 訪問済み管理のチェック
        if (done[pos])
        {
            return;
        }
        // 訪問済み管理の登録
        done[pos] = true;

        // 行きがけ順に処理したい内容
        costs[pos] = cost;
        for (auto &dest : GRAPH[pos]) // 遷移処理
        {
            self(self, dest.to, costs[pos] + dest.number);
        }
        // 帰りがけ順に処理したい内容
    };
    for (ll i = 0; i < N; ++i)
    {
        dfs(dfs, i, 0);
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << costs[i] + 100 << " ";
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
