// ABC449D
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
    ll L, R, D, U;
    cin >> L >> R >> D >> U;
    ll result = 0;
    for (ll i = L; i < R + 1; ++i)
    {
        if (!((i + 1) % 2 == 0))
        {
            result += max<ll>(0, min(abs(i), U) - max(-abs(i), D) + 1);
        }
    }
    for (ll i = D; i < U + 1; ++i)
    {
        if (i == 0)
        {
            continue;
        }
        if (!((i + 1) % 2 == 0))
        {
            if (1 <= i)
            {
                result += max<ll>(0, (min(i - 1, R) + 1) - (max(1 - i, L)));
            }
            else if (i <= -1)
            {
                result += max<ll>(0, (min(-1 - i, R) + 1) - (max(i + 1, L)));
            }
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