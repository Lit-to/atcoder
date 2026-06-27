// ABC464C
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
    ll N, M;
    cin >> N >> M;
    struct EVENT
    {
        ll A, D, B;
        /**
         * ソート用の比較関数
         */
        bool operator<(const EVENT &target) const
        {
            return D < target.D;
        }
    };
    vector<EVENT> events(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> events[i].A >> events[i].D >> events[i].B;
        --events[i].A;
        --events[i].B;
        --events[i].D;
    }
    sort(all(events));
    vector<ll> colors(N);
    for (ll i = 0; i < N; ++i)
    {
        ++colors[events[i].A];
    }
    ll ans = 0;
    for (ll i = 0; i < N; ++i)
    {
        ans += 0 < colors[i];
    }
    ll j = 0;
    for (ll i = 0; i < M; ++i) // 現在i日目,色変化処理済み鳥数がj
    {

        while (j < N && events[j].D <= i)
        {
            --colors[events[j].A];
            if (colors[events[j].A] == 0)
            {
                --ans;
            }
            ++colors[events[j].B];
            if (colors[events[j].B] == 1)
            {
                ++ans;
            }
            ++j;
        };
        cout << ans << endl;
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