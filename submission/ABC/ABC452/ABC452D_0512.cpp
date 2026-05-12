// ABC452D
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
    string S, T;
    cin >> S >> T;
    ll N = S.size();
    ll M = T.size();
    ll ALP = 26;
    vector<vector<ll>> TABLE(ALP, vector<ll>(N + 1, N));
    for (ll i = 0; i < N; ++i)
    {
        TABLE[S[i] - 'a'][i] = i;
    }
    for (ll i = ALP - 1; 0 <= i; --i)
    {
        for (ll j = N; 0 < j; --j)
        {
            TABLE[i][j - 1] = min(TABLE[i][j - 1], TABLE[i][j]);
        }
    }
    ll result = 0;
    for (ll l = 0; l < N; ++l)
    {
        ll pos = l;
        for (ll i = 0; i < M; ++i)
        {
            // ll of = 0;
            // while (TABLE[T[i] - 'a'][pos + of] == pos)
            // {
            // ++of;
            // }
            // pos = TABLE[T[i] - 'a'][pos + of];
            pos = TABLE[T[i] - 'a'][pos];
            if (N == pos)
            {
                break;
            }
            if (!(i + 1 == M))
            {
                ++pos;
            }
        }
        result += pos - l;
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