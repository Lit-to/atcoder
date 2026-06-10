// ABC336D
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
    vector<ll> A(N + 2);
    for (ll i = 1; i < N + 1; ++i)
    {
        cin >> A[i];
    }
    ++N;
    ++N;
    vector<ll> leftD(N);
    for (ll i = 1; i < N - 1; ++i)
    {
        leftD[i] = min(A[i], leftD[i - 1] + 1);
    }
    vector<ll> rightD(N);
    for (ll i = N - 2; 1 <= i; --i)
    {
        rightD[i] = min(A[i], rightD[i + 1] + 1);
    }
    ll result = 1;
    for (ll i = 0; i < N; ++i)
    {
        result = max(result, std::min(leftD[i], rightD[i]));
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