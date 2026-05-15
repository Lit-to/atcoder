// ABC415D
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
    ll N, M;
    cin >> N >> M;
    struct SHOP
    {
        ll A;
        ll B;
        ll D;
        bool operator<(const SHOP &rhs) const
        {
            return this->D != rhs.D ? this->D < rhs.D : (this->A != rhs.A ? this->A < rhs.A : this->B < rhs.B);
        }
    };
    vector<SHOP> shops(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> shops[i].A;
        cin >> shops[i].B;
        shops[i].D = shops[i].A - shops[i].B;
    }
    sort(shops.begin(), shops.end());
    ll n = N;
    ll result = 0;
    for (ll i = 0; i < M; ++i)
    {
        if (n < shops[i].A)
        {
            continue;
        }
        ll x = max<ll>(0, ((n - shops[i].A) / shops[i].D) + 1);
        n -= x * shops[i].D;
        result += x;
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