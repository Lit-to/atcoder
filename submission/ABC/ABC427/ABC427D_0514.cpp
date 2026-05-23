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
    vector<vector<ll>> GRAPH(N);
    string S;
    cin >> S;
    for (ll i = 0; i < M; ++i)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        GRAPH[u].push_back(v);
    }
    vector<vector<bool>> DP((2 * K + 1), vector<bool>(N));
    for (ll i = 0; i < N; ++i)
    {
        DP[2 * K][i] = S[i] == 'A';
    }
    for (ll i = 2 * K - 1; 0 <= i; --i)
    {
        for (ll j = 0; j < N; ++j)
        {
            DP[i][j] = false;
            for (ll &node : GRAPH[j])
            {
                if (DP[i + 1][node] == false)
                {
                    DP[i][j] = true;
                    break;
                }
            }
        }
    }
    if (DP[0][0])
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
    // std::cout << DP[0][1] << endl;
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