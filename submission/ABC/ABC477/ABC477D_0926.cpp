// ABC477D
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
    const auto Q = input<ll>();
    struct QUERY
    {
        ll q;
        ll x;
        char c;
    };
    vector<QUERY> queries(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> queries[i].q;
        if (queries[i].q == 1)
        {
            cin >> queries[i].x;
            --queries[i].x;
        }
        else
        {
            cin >> queries[i].c;
        }
    }
    HashSet<ll> active;
    for (ll i = 0; i < N; ++i)
    {
        active.insert(i);
    }
    for (auto &query : queries)
    {
        if (query.q == 1)
        {
            if (active.contains(query.x))
            {
                active.erase(query.x);
            }
            else
            {
                active.insert(query.x);
            }
        }
        else
        {
            continue;
        }
    }
    HashSet<ll> done;
    std::reverse(all(queries));
    vector<char> color(N, 'a');
    for (auto &query : queries)
    {
        if (query.q == 1)
        {
            if (done.contains(query.x))
            {
                continue;
            }
            if (active.contains(query.x))
            {
                active.erase(query.x);
            }
            else
            {
                active.insert(query.x);
            }
        }
        else
        {
            for (auto i = active.begin(); i != active.end(); i = active.erase(i))
            {
                done.insert(*i);
                color[*i] = query.c;
            }
        }
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << color[i];
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
