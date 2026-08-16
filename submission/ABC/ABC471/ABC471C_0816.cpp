// ABC471C
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
    /*
    // const auto S = input<std::string>();
    */
    const auto N = input<ll>();
    const auto A = input<ll>(N);
    vector<ll> a(A);
    a.push_back(0);
    a.push_back(1e18);
    a.push_back(-1 * 1e18);
    std::sort(all(a));
    ll pos = 0;
    for (ll i = 0; i < a.size(); ++i)
    {
        if (a[i] == 0)
        {
            pos = i;
        }
    }
    ll left = pos;
    ll right = pos;
    ll result = 0;
    while (!(left == 0 && right == a.size() - 1))
    {
        if (a[pos] - a[left] <= a[right] - a[pos])
        {
            result += std::abs(a[pos] - a[left]);
            pos = left;
            --left;
        }
        else
        {
            result += std::abs(a[pos] - a[right]);
            pos = right;
            ++right;
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