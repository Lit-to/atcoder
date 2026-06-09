// AWC0068B
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
    std::cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct SECTION
    {
        int64_t l;     //<! 区間の左端
        int64_t r;     //<! 区間の右端
        int64_t power; //<! 生産力
        /**
         * ソート用の比較関数
         */
        bool operator<(const SECTION &target) const
        {
            return power < target.power;
        }
    };
    vector<SECTION> FIELDS(M);
    for (ll i = 0; i < M; ++i)
    {
        std::cin >> FIELDS[i].l;
        std::cin >> FIELDS[i].r;
        --FIELDS[i].l;
    }
    for (ll i = 0; i < M; ++i)
    {
        for (ll j = FIELDS[i].l; j < FIELDS[i].r; ++j)
        {
            FIELDS[i].power += A[j];
        }
    }
    sort(all(FIELDS));
    cout << FIELDS.back().power - FIELDS.front().power << endl;
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