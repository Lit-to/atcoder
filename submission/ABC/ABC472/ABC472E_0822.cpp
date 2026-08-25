// ABC472E
// template
// clang-format off
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>
#include <unordered_map>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cin;using std::cout;using std::endl;using std::vector;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on

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
        ll nodeU;
        ll nodeV;
    };
    vector<vector<ll>> GRAPH(M);
    for (ll i = 0; i < N; ++i)
    {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        GRAPH[a].push_back(b);
        GRAPH[b].push_back(a);
    }
    std::unordered_map<ll, bool> done;
    vector<ll> trace;
    vector<ll> result;
    auto dfs = [&](auto &self, ll pos, bool color, ll bef) -> bool
    {
        done[pos] = color;
        for (ll i = 0; i < GRAPH[pos].size(); ++i)
        {
            ll c = 1 - color;
            ll p = GRAPH[pos][i];
            if (p == bef)
            {
                continue;
            }
            if (done.contains(p))
            {
                if (done[p] != c)
                {
                    // 矛盾！
                    result.resize(trace.size());
                    std::copy(all(trace), result.begin());
                    return true;
                }
            }
            else
            {
                trace.push_back(p);
                if (self(self, p, c, pos))
                {
                    return true;
                }
                trace.pop_back();
            }
        }
        done.erase(pos);
        return false;
    };
    done[0] = false;
    trace.push_back(0);
    if (dfs(dfs, 0, true, -1))
    {
        cout << result.size() << endl;
        for (ll i = 0; i < result.size(); ++i)
        {
            cout << result[i] + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
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