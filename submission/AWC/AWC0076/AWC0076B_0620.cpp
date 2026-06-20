// AWC0076B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> A[i];
        cin >> B[i];
    }
    vector<ll> ids(N);
    for (ll i = 0; i < N; ++i)
    {
        ids[i] = i;
    }
    sort(all(ids), [&](ll j, ll i)
         { 
            if (B[i] != B[j]) { return B[i]< B[j]; } 
            if (A[i] != A[j]) { return A[i]< A[j]; }
            return i > j; });

    for (ll i = 0; i < N; ++i)
    {
        cout << ids[i] + 1 << endl;
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
    int64_t TESTCASES = 1;

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