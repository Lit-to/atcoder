// AWC0059D
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
    int64_t N;
    cin >> N;
    string S;
    cin >> S;
    int64_t vegfru = 0;
    vector<ll> m(2 * N + 1, 0);
    ++m[N];
    for (int64_t i = 0; i < N; ++i)
    {
        if (S[i] == 'V')
        {
            vegfru++;
        }
        else if (S[i] == 'F')
        {
            vegfru--;
        }
        ++m[vegfru + N];
    }
    int64_t result = 0;
    for (ll i = 0; i < m.size(); ++i)
    {
        if (0 < m[i])
        {
            result += (m[i] * (m[i] - 1)) / 2;
        }
    }
    cout << result << endl;
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