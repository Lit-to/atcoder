// TESOK003I
// clang-format off
#include <iostream>
#include <string>
#include <vector>
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
    // const auto A = input<ll>(10);
    */
    const auto N = input<ll>();
    const auto M = input<ll>();
    struct AB
    {
        ll A;
        ll B;
    };
    std::vector<AB> edges(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> edges[i].A;
        cin >> edges[i].B;
    }
    std::vector<std::vector<ll>> result(N);
    for (ll i = 0; i < M; ++i)
    {
        result[edges[i].A - 1].push_back(edges[i].B - 1);
        result[edges[i].B - 1].push_back(edges[i].A - 1);
    }
    for (ll i = 0; i < N; ++i)
    {
        cout << i + 1 << ": {";
        for (ll j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] + 1;
            if (j != result[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "}" << endl;
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