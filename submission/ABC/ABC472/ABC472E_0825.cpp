// ABC472E
// clang-format off
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>
#include <unordered_set>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cin;using std::cout;using std::endl;using std::vector;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on
#include <vector>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <limits>

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /*
    // const auto S = input<std::string>();
    // const auto A = input<ll>(10);
    */
    const auto N = input<ll>();
    const auto M = input<ll>();
    struct EDGE
    {
        ll U;
        ll V;
    };
    vector<EDGE> edges(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> edges[i].U >> edges[i].V;
        --edges[i].U;
        --edges[i].V;
    }
    vector<vector<ll>> graph(N);
    for (ll i = 0; i < M; ++i)
    {
        graph[edges[i].U].push_back(edges[i].V);
        graph[edges[i].V].push_back(edges[i].U);
    }
    std::unordered_set<ll> done;
    vector<bool> color(N);
    vector<ll> result;
    auto dfs = [&](auto &self, bool c, ll node, ll parent) -> bool
    {
        result.push_back(node);
        if (done.contains(node))
        { // 色判定
            if (color[node] != c)
            {
                return true;
            }
            else
            {
                result.pop_back();
                return false;
            }
        }
        done.insert(node);
        color[node] = c;
        bool r = false;
        for (auto &dest : graph[node])
        {
            if (r)
            {
                // 既に答えが判明している
                return true;
            }
            else if (dest == parent)
            {
                // 逆流禁止
                continue;
            }
            else if (self(self, !c, dest, node))
            {
                // 探索先で答えが見つかった
                r = true;
                return true;
            }
        }
        // 帰りがけ
        result.pop_back();
        return false;
    };
    bool r = dfs(dfs, true, 0, -1);
    if (!r)
    {
        cout << -1 << endl;
        return;
    }
    ll startPos = result.back();
    vector<ll> ans;
    ans.push_back(startPos);
    result.pop_back();
    for (ll i = result.size() - 1; 0 <= i; --i)
    {
        if (result[i] == startPos)
        {
            break;
        }
        ans.push_back(result[i]);
    }
    cout << ans.size() << endl;
    for (auto &i : ans)
    {
        cout << i + 1 << " ";
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
    int64_t TESTCASES = DEFAULT_TESTCASE;
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