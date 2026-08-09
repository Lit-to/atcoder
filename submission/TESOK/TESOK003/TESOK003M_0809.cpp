// TESOK003M
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
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n+1,-1);for (int64_t i = 0; i < n; ++i){contents[i+1] = input<T>()-1;}return contents;}
// clang-format on

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /*
    // const auto S = input<std::string>();
    */
    const auto N = input<ll>();
    const auto A = input<ll>(N - 1);
    std::vector<ll> graph(N);
    // auto dfs = [&](auto &self, ll pos) -> void
    // {
    //     if (A[pos] == -1)
    //     {
    //         return;
    //     }
    //     ++graph[A[pos]];
    //     return self(self, A[pos]);
    // };
    for (ll i = N - 1; 0 <= i; --i)
    {
        if (A[i] == -1)
        {
            continue;
        }
        ++graph[A[i]];
        graph[A[i]] += graph[i];
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << graph[i] << " ";
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