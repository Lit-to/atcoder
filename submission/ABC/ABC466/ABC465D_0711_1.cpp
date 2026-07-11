// ABC465D
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
using std::cin;
using std::cout;
using std::endl;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, M;
    cin >> N >> M;
    struct coma
    {
        ll r;
        ll c;
    };
    std::vector<coma> komas(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> komas[i].r >> komas[i].c;
        --komas[i].r;
        --komas[i].c;
    }
    std::vector<ll> row(N, -1);
    std::vector<ll> col(N, -1);
    for (ll i = 0; i < M; ++i)
    {
        if (row[komas[i].r] != -1)
        {
            col[row[komas[i].r]] = -1;
        }
        if (col[komas[i].c] != -1)
        {
            row[col[komas[i].c]] = -1;
        }
        row[komas[i].r] = komas[i].c;
        col[komas[i].c] = komas[i].r;
    }
    ll result = 0;
    for (ll i = 0; i < N; ++i)
    {
        if (0 <= row[i])
        {
            ++result;
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
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