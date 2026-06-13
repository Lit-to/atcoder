// ABC462D
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

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, D;
    cin >> N >> D;
    struct PERSON
    {
        ll S;
        ll T;
        /**
         * ソート用の比較関数
         */
        bool operator<(const PERSON &target) const
        {
            return this->S < target.S || S == target.S && T < target.T;
        }
    };
    const ll T_MAX = 1e6 + 10;
    // const ll T_MAX = 30;
    vector<PERSON> PEOPLE;
    for (ll i = 0; i < N; ++i)
    {
        ll s, t;
        cin >> s >> t;
        t -= D;
        if (s <= t)
        {
            PEOPLE.push_back(PERSON{.S = s, .T = t});
        }
    }
    N = PEOPLE.size();
    vector<ll> exitCount(T_MAX);
    vector<ll> enterCount(T_MAX);
    for (ll i = 0; i < N; ++i)
    {
        ++enterCount[PEOPLE[i].S];
        ++exitCount[PEOPLE[i].T];
    }
    ll nowCount = 0;
    ll result = 0;
    for (ll i = 0; i < T_MAX; ++i)
    {
        nowCount += enterCount[i];
        // cerr << nowCount << " ";
        result += (nowCount * (nowCount - 1)) / 2;
        nowCount -= exitCount[i];
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