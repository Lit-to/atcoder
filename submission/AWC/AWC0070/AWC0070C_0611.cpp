// AWC0070C
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
    string S;
    cin >> S;
    vector<char> s(N + 1);
    s[0] = '.';
    for (ll i = 0; i < N; ++i)
    {
        s[i + 1] = S[i];
    }
    vector<ll> result(N + 1);
    result[0] = 1;
    for (ll i = 0; i < N + 1; ++i)
    {
        if (s[i] == '#')
        {
            continue;
        }
        if (i + 1 < result.size())
        {
            result[i + 1] += result[i];
            result[i + 1] %= ((ll)1e9 + (ll)7);
        }
        if (i + 2 < result.size())
        {
            result[i + 2] += result[i];
            result[i + 2] %= ((ll)1e9 + (ll)7);
        }
        if (i + 3 < result.size())
        {
            result[i + 3] += result[i];
            result[i + 3] %= ((ll)1e9 + (ll)7);
        }
    }
    cout << result[N] << endl;
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