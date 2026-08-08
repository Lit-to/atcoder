// ABC470C
// template
// clang-format off
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::cin;using std::cout;using std::endl;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
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
    */
    const auto N = input<ll>();
    const auto Q = input<ll>();
    struct QUERY
    {
        ll q;
        ll index;
    };
    std::vector<QUERY> queries(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> queries[i].q;
        if (queries[i].q == 1)
        {
            cin >> queries[i].index;
            --queries[i].index;
        }
        else
        {
            queries[i].index = -1;
        }
    }
    std::vector<ll> a(N);
    std::vector<ll> counts(N);
    counts[0] = N;
    ll allUpdateCost = 0;
    ll offset = 0;
    ll result = 0;
    std::set<ll> uset;
    for (ll i = 0; i < Q; ++i)
    {
        if (queries[i].q == 1)
        {
            ll index = queries[i].index;
            result ^= a[index];
            ++a[index];
            uset.insert(index);
            result ^= a[index];
        }
        else
        {

            for (auto itr = uset.begin(); itr != uset.end();)
            {
                result ^= a[*itr];
                --a[*itr];
                result ^= a[*itr];
                if (a[*itr] == 0)
                {
                    itr = uset.erase(itr);
                }
                else
                {
                    ++itr;
                }
            }
        }
        cout << result << endl;
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