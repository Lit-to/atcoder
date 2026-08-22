// ABC472C
// template
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
    // const auto A = input<ll>(10);
    */
    const auto N = input<ll>();
    const auto M = input<ll>();
    const auto K = input<ll>();
    const auto A = input<ll>(N);
    ll l = 0;
    ll kal = 0;
    struct SNACK
    {
        ll day;
        ll kal;
    };
    std::queue<SNACK> ate;
    ll sum = 0;
    for (ll i = 0; i < N; ++i)
    {
        if (sum + A[i] <= K)
        {
            cout << "Yes" << endl;
            ate.push(SNACK{.day = i, .kal = A[i]});
            sum += A[i];
        }
        else
        {
            cout << "No" << endl;
        }
        while (!ate.empty() && ate.front().day <= i - M + 1)
        {
            sum -= ate.front().kal;
            ate.pop();
        }
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