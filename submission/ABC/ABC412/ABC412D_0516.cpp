// ABC412D
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
    ll N, M;
    cin >> N >> M;
    struct NODE
    {
        ll A;
        ll B;
    };
    vector<NODE> nodes(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> nodes[i].A;
        cin >> nodes[i].B;
        --nodes[i].A;
        --nodes[i].B;
    }
    vector<vector<bool>> GRAPH(N, vector<bool>(N));
    for (ll i = 0; i < M; ++i)
    {
        GRAPH[min(nodes[i].A, nodes[i].B)][max(nodes[i].A, nodes[i].B)] = true;
    }
    vector<ll> target;
    ll result = INT64_MAX;
    for (ll i = 0; i < N; ++i)
    {
        target.push_back(i);
    }
    do
    {
        vector<vector<bool>> graph(N, vector<bool>(N));
        for (ll i = 0; i < N; ++i)
        {
            ll u = min(target[i], target[(i + 1) % N]);
            ll v = max(target[i], target[(i + 1) % N]);
            graph[u][v] = true;
        }
        ll candidate = 0;
        for (ll i = 0; i < N; ++i)
        {
            for (ll j = 0; j < N; ++j)
            {
                if (GRAPH[i][j] != graph[i][j])
                {
                    candidate++;
                }
            }
        }
        result = min(result, candidate);
        for (ll d = 3; d <= N - 3; ++d)
        {
            vector<vector<bool>> graph2(N, vector<bool>(N));
            for (ll i = 0; i < d; ++i)
            {
                ll u = min(target[i], target[(i + 1) % d]);
                ll v = max(target[i], target[(i + 1) % d]);
                graph2[u][v] = true;
            }
            for (ll i = 0; i < N - d; ++i)
            {
                ll u = min(target[i + d], target[(i + 1) % (N - d) + d]);
                ll v = max(target[i + d], target[(i + 1) % (N - d) + d]);
                graph2[u][v] = true;
            }
            ll candidate2 = 0;
            for (ll i = 0; i < N; ++i)
            {
                for (ll j = 0; j < N; ++j)
                {
                    if (GRAPH[i][j] != graph2[i][j])
                    {
                        candidate2++;
                    }
                }
            }
            result = min(result, candidate2);
        }
    } while (next_permutation(all(target)));
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