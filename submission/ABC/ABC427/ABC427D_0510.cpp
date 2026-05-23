// ABC427D
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
    ll N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    vector<vector<ll>> GRAPH(N, vector<ll>(M));
    for (ll i = 0; i < M; ++i)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        GRAPH[u].push_back(v);
    }
    vector<vector<ll>> DP(11, vector<ll>(N)); // i回目の操作でマスjに居るときにAliceが勝つかどうか
    for (ll j = N; 0 < j; --j)
    {
        DP[10][j] = S[j] == 'A';
    }

    for (ll i = 9; 0 < i; --i)
    {
        for (ll j = N; 0 < j; --j)
        {
            DP[i][j];
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

    std::cin >> TESTCASES;

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