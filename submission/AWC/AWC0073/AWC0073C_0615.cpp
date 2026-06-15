// AWC0073C
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
    ll N, D;
    cin >> N >> D;
    struct SHOP
    {
        ll X;
        ll S;
        /**
         * ソート用の比較関数
         */
        bool operator<(const SHOP &target) const
        {
            return X < target.X;
        }
    };
    vector<SHOP> shops(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> shops[i].X;
        cin >> shops[i].S;
    }
    std::sort(all(shops));
    std::queue<ll> que;
    ll r = 0;
    ll allSum = 0;
    ll result = 0;
    for (ll i = 0; i < N; ++i)
    {
        while (!que.empty() && !((shops[i].X - shops[que.front()].X) <= D))
        {
            ll front = que.front();
            allSum -= shops[front].S;
            que.pop();
        }
        result += allSum * shops[i].S;
        allSum += shops[i].S;
        que.push(i);
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