// ABC479E
// template
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>

#include <map>
template <class KEY_TYPE, class VALUE_TYPE>
using TreeMap = std::map<KEY_TYPE, VALUE_TYPE>;
#include <unordered_map>
template <class KEY_TYPE, class VALUE_TYPE>
using HashMap = std::unordered_map<KEY_TYPE, VALUE_TYPE>;

#include <set>
template <class VALUE_TYPE>
using TreeSet = std::set<VALUE_TYPE>;
#include <unordered_set>
template <class VALUE_TYPE>
using HashSet = std::unordered_set<VALUE_TYPE>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
T input()
{
    T variable;
    cin >> variable;
    return variable;
}
template <typename T>
std::vector<T> input(int64_t n)
{
    std::vector<T> contents(n);
    for (int64_t i = 0; i < n; ++i)
    {
        contents[i] = input<T>();
    }
    return contents;
}
// 自作ライブラリここから

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力スニペ
    const auto N = input<ll>();
    struct EDGE
    {
        ll A;
        ll B;
    };
    vector<EDGE> edges(N - 1);
    for (ll i = 0; i < N - 1; ++i)
    {
        cin >> edges[i].A >> edges[i].B;
        --edges[i].A;
        --edges[i].B;
    }
    struct DIST
    {
        ll to;
    };
    vector<vector<ll>> GRAPH(N);
    for (ll i = 0; i < N - 1; ++i)
    {
        GRAPH[edges[i].A].push_back(edges[i].B);
    }
    vector<ll> weight(N);
    auto dfs = [&](auto self, ll pos) -> ll
    {
        if (weight[pos] != 0)
        {
            return weight[pos];
        }
        ll result = 1;
        for (auto &to : GRAPH[pos])
        {
            result += self(self, to);
        }
        weight[pos] = result;
        return result;
    };
    for (ll i = 0; i < N; ++i)
    {
        dfs(dfs, i);
    }
    vector<ll> xValue(N);
    for (ll i = 0; i < N - 1; ++i)
    {
        ll a = edges[i].A - edges[i].B;
        ll b = edges[i].B;
        if (a < b)
        {
            xValue[edges[i].B] += weight[edges[i].B];
        }
        else
        {
            xValue[edges[i].A] += weight[edges[i].A];
        }
    }
    vector<bool> done(N);
    vector<ll> resultValues(N);
    auto dfs_fill = [&](auto self, ll pos, ll value) -> void
    {
        if (done[pos] != true)
        {
            return;
        }
        done[pos] = true;
        resultValues[pos] = value;
        for (auto &to : GRAPH[pos])
        {
            self(self, to, value + xValue[to]);
        }
        return;
    };
    for (ll i = 0; i < N; ++i)
    {
        dfs_fill(dfs_fill, i, xValue[i]);
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << xValue[i] << " ";
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

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
