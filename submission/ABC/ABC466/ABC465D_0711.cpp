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
    std::reverse(all(komas));
    std::vector<bool> row(N);
    std::vector<bool> col(N);
    ll result = 0;
    for (ll i = 0; i < M; ++i)
    {
        if (row[komas[i].r] || col[komas[i].c])
        {
        }
        else
        {
            ++result;
        }
        row[komas[i].r] = true;
        col[komas[i].c] = true;
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