// ABC354C
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
    struct CARD
    {
        ll A;
        ll C;
        ll index;
        /**
         * ソート用の比較関数
         */
        bool operator<(const CARD &target) const
        {
            return C < target.C;
        }
    };
    vector<CARD> cards(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> cards[i].A;
        cin >> cards[i].C;
        cards[i].index = i;
    }
    sort(all(cards));
    vector<ll> validCard;
    validCard.push_back(cards[0].index);
    ll mx = cards[0].A;
    for (ll i = 1; i < N; ++i)
    {
        if (mx < cards[i].A)
        {
            validCard.push_back(cards[i].index);
            mx = cards[i].A;
        }
        continue;
    }
    cout << validCard.size() << endl;
    sort(all(validCard));
    for (ll i = 0; i < validCard.size(); ++i)
    {
        cout << validCard[i] + 1 << " ";
    }
    cout << endl;
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