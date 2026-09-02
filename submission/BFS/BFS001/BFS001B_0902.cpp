// BFS001B
// clang-format off
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <queue>
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
    struct AB
    {
        ll A;
        ll B;
    };
    vector<AB> edges(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> edges[i].A >> edges[i].B;
        --edges[i].A;
        --edges[i].B;
    }
    vector<vector<ll>> GRAPH(N);
    for (ll i = 0; i < M; ++i)
    {
        GRAPH[edges[i].A].push_back(edges[i].B);
        GRAPH[edges[i].B].push_back(edges[i].A);
    }
    struct TASK
    {
        ll node;
        ll cost;
    };
    std::queue<TASK> tasks;
    tasks.push(TASK{.node = 0, .cost = 0});
    vector<bool> done(N);
    vector<ll> costs(N, -1);
    done[0] = true;
    costs[0] = 0;
    while (!tasks.empty())
    {
        // キューから取り出す
        auto task = tasks.front();
        tasks.pop();

        for (ll &dest : GRAPH[task.node])
        // 遷移
        {
            // 訪問済み確認
            if (done[dest])
            {
                continue;
            }
            // 訪問済み登録
            done[dest] = true;

            // タスク処理
            costs[dest] = task.cost + 1;

            // キューの登録
            tasks.push(TASK{.node = dest, .cost = costs[dest]});
        }
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << costs[i] << endl;
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
