// AWC0061B
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
template <class T>
void v_output(const std::vector<T> &a)
{
    for (int64_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
template <class T>
void v_input(std::vector<T> &a)
{
    for (int64_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
    }
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N;
    cin >> N;
    vector<ll> S(N);
    v_input(S);
    vector<ll> C(N);
    for (int64_t i = 1; i < C.size(); ++i)
    {
        std::cin >> C[i];
    }
    ll r = -1 * (ll)10e16;
    ll score = 0;
    for (ll i = 0; i < N; ++i)
    {
        score += S[i];
        score -= C[i];
        r = max(r, score);
    }
    cout << r << endl;
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