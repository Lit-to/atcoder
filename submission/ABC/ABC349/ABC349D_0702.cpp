// ABC349D
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
using std::vector;
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
    ll L, R;
    cin >> L >> R;
    struct SECTION
    {
        int64_t l; //<! 区間の左端
        int64_t r; //<! 区間の右端
        /**
         * ソート用の比較関数
         */
        bool operator<(const SECTION &target) const
        {
            return l < target.l || l == target.l && r < target.r;
        }
    };
    vector<SECTION> result;
    auto resolve = [&](auto self, ll l, ll r, ll nl, ll nr) -> ll
    {
        if (l == nl && r == nr)
        {
            result.push_back(SECTION{.l = l, .r = r});
            return 1;
        }
        ll mid = nl + (nr - nl) / 2;
        SECTION childLeft = SECTION{.l = l, .r = std::min(mid, r)};
        SECTION childRight = SECTION{.l = std::max(mid, l), .r = r};
        ll sum = 0;
        if (childLeft.l < childLeft.r)
        {
            sum += self(self, childLeft.l, childLeft.r, nl, mid);
        }
        if (childRight.l < childRight.r)
        {
            sum += self(self, childRight.l, childRight.r, mid, nr);
        }
        return sum;
    };
    ll sum = resolve(resolve, L, R, 0LL, 1LL << 60);
    std::sort(all(result));
    cout << sum << endl;
    for (ll i = 0; i < result.size(); ++i)
    {
        cout << result[i].l << " " << result[i].r << endl;
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