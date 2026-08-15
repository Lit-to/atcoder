// ABC471D
// template
// clang-format off
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::cin;using std::cout;using std::endl;using std::vector;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on
#include <queue>
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /*
    // const auto S = input<std::string>();
    // const auto A = input<ll>(10);
    */
    const auto Q = input<ll>();
    const auto V = input<ll>();
    struct QUERY
    {
        ll q;
        ll t;
        ll w;
    };
    struct BAT
    {
        ll time;
        ll value;
        ll eval(const ll t) const
        {
            return t - this->time + this->value;
        }
        bool operator>(const BAT &target) const
        {
            return target.value < target.value;
        }
    };
    vector<QUERY> queries(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> queries[i].q;
        cin >> queries[i].t;
        if (queries[i].q == 1)
        {
            cin >> queries[i].w;
        }
    }
    greater_priority_queue<ll> gpq;
    for (auto &query : queries)
    {
        if (query.q == 1)
        {
            gpq.push(query.w - query.t);
        }
        else
        {
            if (gpq.size() == 0)
            {
                cout << -1 << endl;
                continue;
            }
            auto e = gpq.top();
            ll result = e + query.t;
            cout << result << endl;
            gpq.pop();
        }
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