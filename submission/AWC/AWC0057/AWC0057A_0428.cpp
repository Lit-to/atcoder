// AWC0057A
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
void v_output(const std::vector<T> &a)
{
    for (int64_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N, X;
    std::cin >> N >> X;
    std::vector<ll> A(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    std::vector<ll> B(N);
    B[0] = A[0];
    B[N - 1] = A[N - 1];
    for (ll i = 1; i < N - 1; ++i)
    {
        if (A[i - 1] == A[i + 1] && A[i - 1] != A[i])
        {
            B[i] = 0;
        }
        else
        {
            B[i] = A[i];
        }
    }
    ll D = X;
    for (int64_t i = 0; i < N; ++i)
    {
        D = D ^ B[i];
    }
    cout << D << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t TESTCASES = 1;

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