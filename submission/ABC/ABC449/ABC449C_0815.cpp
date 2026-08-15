// ABC449C
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
    const auto N = input<ll>();
    const auto L = input<ll>();
    const auto R = input<ll>();
    const auto S = input<std::string>();
    vector<vector<ll>> charCount(26, vector<ll>(N));
    for (ll i = 0; i < N; ++i)
    {
        ++charCount[S[i] - 'a'][i];
    }
    vector<vector<ll>> preSums(26, vector<ll>(N + 1));
    for (ll c = 0; c < 26; ++c)
    {
        for (ll i = 0; i < N; ++i)
        {
            preSums[c][i + 1] = preSums[c][i] + charCount[c][i];
        }
    }
    ll result = 0;
    for (ll i = 0; i < N; ++i)
    {
        int c = S[i] - 'a';
        const ll r = i - L;
        const ll l = i - R;
        if (0 <= r)
        {
            result += preSums[c][r + 1] - preSums[c][std::max<ll>(0, l)];
        }
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