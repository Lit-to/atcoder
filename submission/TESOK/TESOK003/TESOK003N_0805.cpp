// TESOK003N
// clang-format off
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::cin;using std::cout;using std::endl;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /*
    // const auto S = input<std::string>();
    // const auto A = input<ll>(10);
    */
    const auto N = input<ll>();
    const auto M = input<ll>();
    struct EDGE
    {
        ll A;
        ll B;
    };
    std::vector<EDGE> ab(M);
    for (ll i = 0; i < M; ++i)
    {
        std::cin >> ab[i].A >> ab[i].B;
        --ab[i].A;
        --ab[i].B;
    }
    std::vector<std::vector<ll>> edges(N);
    for (ll i = 0; i < M; ++i)
    {
        edges[ab[i].A].push_back(ab[i].B);
        edges[ab[i].B].push_back(ab[i].A);
    }
    std::vector<bool> done(N);
    done[0] = true;
    std::vector<ll> result(N, -1);
    struct TASK
    {
        ll pos;
        ll count;
    };
    std::queue<TASK> tasks;
    tasks.push({0, 0});
    while (!tasks.empty())
    {
        auto task = tasks.front();
        ll node = task.pos;
        ll count = task.count;
        tasks.pop();
        if (result[node] != -1)
        {
            continue;
        }
        result[node] = count;
        for (ll i = 0; i < edges[node].size(); ++i)
        {
            tasks.push({edges[node][i], count + 1});
        }
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << result[i] << endl;
    };
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