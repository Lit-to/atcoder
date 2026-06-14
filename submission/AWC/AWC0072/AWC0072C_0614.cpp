// AWC0072C
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
struct SECTION
{
    int64_t l; //<! 区間の左端
    int64_t r; //<! 区間の右端
    /**
     * ソート用の比較関数
     */
    bool operator<(const SECTION &target) const
    {
        return l < target.l || l == target.l && r < target.r;
    }
};
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> S(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> S[i];
    }
    vector<SECTION> EVENTS(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> EVENTS[i].l >> EVENTS[i].r;
        --EVENTS[i].l;
    }
    vector<ll> imos(N + 1);
    for (ll i = 0; i < Q; ++i)
    {
        ++imos[EVENTS[i].l];
        --imos[EVENTS[i].r];
    }
    for (ll i = 0; i < N; ++i)
    {
        imos[i + 1] += imos[i];
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << max<ll>(0, S[i] - imos[i]) << " ";
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