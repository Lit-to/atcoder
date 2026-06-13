// ABC462C
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
    ll N;
    cin >> N;
    struct point
    {
        ll X;
        ll Y;
        /**
         * ソート用の比較関数
         */
        bool operator<(const point &target) const
        {
            return X < target.X;
        }
    };
    vector<point> POINTS(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> POINTS[i].X >> POINTS[i].Y;
    }
    sort(all(POINTS));
    ll nowY = N + 1;
    ll result = 0;
    for (auto &p : POINTS)
    {
        if (p.Y < nowY)
        {
            ++result;
            nowY = p.Y;
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