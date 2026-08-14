// ABC425C
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
    const auto Q = input<ll>();
    const auto A = input<ll>(N);
    ll n = 2 * N;
    vector<ll> a(n);
    for (ll i = 0; i < N; ++i)
    {
        a[i] = A[i];
        a[N + i] = A[i];
    }
    struct QUERY
    {
        ll q;
        ll c;
        ll l;
        ll r;
    };
    vector<QUERY> queries(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> queries[i].q;
        if (queries[i].q == 1)
        {
            cin >> queries[i].c;
        }
        else
        {
            cin >> queries[i].l >> queries[i].r;
            --queries[i].l;
        }
    }
    std::vector<ll> preSum(n + 1);
    for (ll i = 0; i < n; ++i)
    {
        preSum[i + 1] = preSum[i] + a[i];
    }
    ll offset = 0;
    for (auto &query : queries)
    {
        if (query.q == 1)
        {
            offset += query.c;
            offset %= N;
        }
        else
        {
            ll result = preSum[query.r + offset] - preSum[query.l + offset];
            cout << result << endl;
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