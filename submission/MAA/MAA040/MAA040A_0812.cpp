// MAA040A
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
    /*
    // const auto S = input<std::string>();
    */
    const auto N = input<ll>();
    const auto A = input<ll>(N - 1);
    const auto M = input<ll>();
    const auto B = input<ll>(M);
    vector<ll> preSum(N);
    for (ll i = 0; i < N; ++i)
    {
        preSum[i + 1] = preSum[i] + A[i];
    }
    ll result = 0;
    for (ll i = 0; i < M - 1; ++i)
    {
        ll from = B[i] - 1;
        ll to = B[i + 1] - 1;
        if (to <= from)
        {
            std::swap(to, from);
        }
        result += preSum[to] - preSum[from];
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