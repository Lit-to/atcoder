// ABC461C
// template
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
    ll N, K, M;
    cin >> N >> K >> M;
    struct CV
    {
        ll C;
        ll V;
        /**
         * ソート用の比較関数
         */
        bool operator<(const CV &target) const
        {
            return V < target.V || V == target.V && C < target.C;
        }
    };
    vector<CV> JUWERY(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> JUWERY[i].C;
        cin >> JUWERY[i].V;
        --JUWERY[i].C;
    }
    sort(rall(JUWERY));
    unordered_map<ll, ll> maxBag;
    for (ll i = 0; i < N; ++i)
    {
        if (!maxBag.contains(JUWERY[i].C))
        {
            maxBag[JUWERY[i].C] = i;
            continue;
        }
        if (JUWERY[maxBag[JUWERY[i].C]].V < JUWERY[i].V)
        {
            maxBag[JUWERY[i].C] = i;
            continue;
        }
    }
    vector<pair<ll, ll>> tops;
    for (auto &p : maxBag)
    {
        tops.push_back({JUWERY[p.second].V, p.second});
    }
    sort(rall(tops));
    ll result = 0;
    vector<bool> done(N);
    for (ll i = 0; i < M; ++i)
    {
        result += tops[i].first;
        done[tops[i].second] = true;
    }
    ll r = 0;
    ll i = 0;
    while (r < K - M)
    {
        if (!done[i])
        {
            result += JUWERY[i].V;
            done[i] = true;
            ++r;
        }
        ++i;
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