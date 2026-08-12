// TESOK014E
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
    */
    const auto N = input<ll>();
    const auto A = input<ll>(N);
    const auto Q = input<ll>();
    struct SECTION
    {
        ll L;
        ll R;
    };
    vector<SECTION> sections(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> sections[i].L >> sections[i].R;
    }
    vector<vector<ll>> preSum(2, vector<ll>(N + 1));
    for (ll i = 0; i < N; ++i)
    {
        if (A[i] == 1)
        {
            preSum[0][i + 1] = preSum[0][i] + 1; // あたり個数
            preSum[1][i + 1] = preSum[1][i] + 0; // はずれ個数
        }
        else
        {
            preSum[0][i + 1] = preSum[0][i] + 0; // あたり個数
            preSum[1][i + 1] = preSum[1][i] + 1; // はずれ個数
        }
    };
    for (ll i = 0; i < Q; ++i)
    {
        ll l = sections[i].L - 1;
        ll r = sections[i].R - 1;
        ++r;
        ll resultWin = preSum[0][r] - preSum[0][l];
        ll resultLose = preSum[1][r] - preSum[1][l];
        if (resultWin == resultLose)
        {
            cout << "draw" << endl;
        }
        else if (resultWin < resultLose)
        {
            cout << "lose" << endl;
        }
        else
        {
            cout << "win" << endl;
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