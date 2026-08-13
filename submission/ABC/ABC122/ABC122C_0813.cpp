// ABC122C
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
    const auto Q = input<ll>();
    const auto S = input<std::string>();
    /**
     * @brief 半開区間を表す構造体
     */
    struct SECTION
    {
        int64_t l; //<! 区間の左端
        int64_t r; //<! 区間の右端
        /**
         * ソート用の比較関数
         */
        bool operator<(const SECTION &target) const
        {
            return l < target.l || l == target.l && r < target.r;
        }
    };
    vector<SECTION> queries(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> queries[i].l >> queries[i].r;
    }

    vector<ll> preSum(N + 1);
    for (ll i = 1; i < N; ++i)
    {
        if (S[i - 1] == 'A' && S[i] == 'C')
        {
            preSum[i + 1] = preSum[i] + 1;
        }
        else
        {
            preSum[i + 1] = preSum[i];
        }
    }
    for (auto &query : queries)
    {
        cout << preSum[query.r] - preSum[query.l] << endl;
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