// ABC411D
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

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, Q;
    cin >> N >> Q;
    struct QUERY
    {
        ll q;
        ll p;
        string s = "-1";
    };
    vector<QUERY> QUERIES(Q);
    for (ll i = 0; i < Q; ++i)
    {
        ll q, p;
        cin >> q >> p;
        QUERIES[i].q = q;
        QUERIES[i].p = p;
        if (q == 2)
        {
            cin >> QUERIES[i].s;
            reverse(all(QUERIES[i].s));
        }
    }
    std::string ans = "";
    reverse(all(QUERIES));
    ll i = 0;
    for (QUERY &query : QUERIES)
    {
        if (query.q == 1)
        {
            if (i == query.p)
            {
                i = 0;
            }
        }
        else if (query.q == 2)
        {
            if (i == query.p)
            {
                ans += query.s;
            }
        }
        else
        {
            if (i == 0)
            {
                i = query.p;
            }
        }
    }
    reverse(all(ans));
    cout << ans << endl;
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