// ABC401C
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
    // const auto A = input<ll>(10);
    */
    const ll MOD = 1e9;
    const auto N = input<ll>();
    const auto K = input<ll>();
    std::vector<ll> preSum(N + 2);
    preSum[0] = 1;
    for (ll i = 0; i < N + 1; ++i)
    {
        if (0 <= i && i < K)
        {
            preSum[i + 1] = preSum[i] + 1;
        }
        else
        {
            ll r = (preSum[i] - preSum[i - K]) % MOD;
            if (r < 0)
            {
                r += MOD;
            }
            preSum[i + 1] = (preSum[i] + r) % MOD;
        }
    }
    ll result = (preSum[N + 1] - preSum[N]) % MOD;
    if (result < 0)
    {
        result += MOD;
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