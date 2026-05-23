// AWC0067A
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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> students(N);
    for (ll i = 0; i < Q; ++i)
    {
        ll q, a, b, c;
        cin >> q >> a >> b >> c;
        if (q == 1)
        {
            students[a - 1] -= c;
            students[b - 1] += c;
        }
        else if (q == 2)
        {
            ll r = 0;
            for (ll i = b - 1; i < c; ++i)
            {
                r += students[a - 1] < students[i];
            }
            cout << r << endl;
        }
        else
        {
            ll r = 0;
            for (ll i = a - 1; i < b; ++i)
            {
                r += students[i] += c;
            }
        }
    }
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