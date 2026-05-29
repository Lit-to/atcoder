// ABC403D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#include <unordered_map>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uniqueAll(v)   \
    std::sort(all(v)); \
    v.erase(std::unique(all(v)), v.end());
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
    std::cin >> N >> D;
    std::vector<ll> A(N);
    for (ll i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    if (D == 0)
    {
        uniqueAll(A);
        cout << N - A.size() << endl;
        return;
    }
    vector<ll> modes((ll)(10e6 + 1));
    for (ll i = 0; i < N; ++i)
    {
        ++modes[A[i]];
    }
    ll result = 0;
    for (ll i = 0; i < D; ++i)
    {
        ll deleteMe = 0;    // 自分自身を消したときのコストの最小値
        ll notDeleteMe = 0; // 自分自身を消さなかったときのコストの最小値
        for (ll j = i; j < modes.size(); j += D)
        {
            ll tmpNotDeleteMe = deleteMe;
            ll tmpDeleteMe = min(deleteMe, notDeleteMe) + modes[j];
            deleteMe = tmpDeleteMe;
            notDeleteMe = tmpNotDeleteMe;
        }
        result += min(deleteMe, notDeleteMe);
    }
    std::cout << result << std::endl;
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