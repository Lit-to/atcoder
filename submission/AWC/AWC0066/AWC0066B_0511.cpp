// AWC0066B
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
    ll N, L, K, Y;
    cin >> N >> L >> K >> Y;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    sort(rall(A));
    ll c = 0;
    ll r = -1;
    for (ll i = 0; i < N; ++i)
    {
        if (max<ll>(0, A[i] - Y) <= L)
        {
            r = i;
            break;
        }
        ++c;
    }
    if (r != -1)
    {
        for (ll i = r; i < N && i < r + K; ++i)
        {
            c += (L < A[i]);
        }
    }
    cout << c << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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