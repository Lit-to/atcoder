// TESOK002F
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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<bool> DP(N + 1);
    DP[0] = false;
    for (ll i = 1; i <= N; ++i)
    {
        if (A <= i && !DP[i - A])
        {
            DP[i] = true;
        }
        else if (B <= i && !DP[i - B])
        {
            DP[i] = true;
        }
    }
    if (DP[N] == true)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
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