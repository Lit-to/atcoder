// ABC469D
// clang-format off
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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
    struct WINNER_PAIR
    {
        ll A;
        ll B;
    };
    std::vector<WINNER_PAIR> AB(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> AB[i].A >> AB[i].B;
        --AB[i].A;
        --AB[i].B;
    }
    if (N == 2)
    {
        cout << 1 << endl;
        return;
    }
    std::vector<ll> candidates(2);
    candidates[0] = AB[0].A;
    candidates[1] = AB[0].B;
    ll battles = 0;
    std::vector<ll> withCan0(N);
    for (ll i = 0; i < M; ++i)
    {

        if (AB[i].A == candidates[0])
        {
            ++battles;
        }
        else if (AB[i].B == candidates[0])
        {
            ++battles;
        }
        else
        {
            ++withCan0[AB[i].A];
            ++withCan0[AB[i].B];
        }
    }
    ll result = 0;

    for (ll i = 0; i < N; ++i)
    {
        if (i == candidates[0])
        {
            continue;
        }
        if (M == withCan0[i] + battles)
        {
            ++result;
        }
    }
    //==
    battles = 0;
    std::vector<ll> withCan1(N);
    for (ll i = 0; i < M; ++i)
    {

        if (AB[i].A == candidates[1])
        {
            ++battles;
        }
        else if (AB[i].B == candidates[1])
        {
            ++battles;
        }
        else
        {
            ++withCan1[AB[i].A];
            ++withCan1[AB[i].B];
        }
    }
    for (ll i = 0; i < N; ++i)
    {
        if (i == candidates[1])
        {
            continue;
        }

        if (M == withCan1[i] + battles)
        {
            ++result;
        }
    }
    //==
    ll c = 0;
    for (ll i = 0; i < M; ++i)
    {
        if (AB[i].A == candidates[0] || AB[i].A == candidates[1] || AB[i].B == candidates[0] || AB[i].B == candidates[1])
        {
            ++c;
        }
    }
    if (c == M)
    {
        --result;
    }

    cout << result << endl;
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