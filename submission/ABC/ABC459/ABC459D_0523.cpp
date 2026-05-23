// ABC459D
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
    string S;
    cin >> S;
    ll N = S.size();
    if (N == 1)
    {
        cout << "Yes" << endl;
        cout << S << endl;
        return;
    }
    struct charact
    {
        ll count;
        char m;
        bool operator<(const charact &target) const
        {
            return count < target.count;
        }
    };
    vector<charact> counts(26);
    for (ll i = 0; i < 26; ++i)
    {
        counts[i].m = i + 'a';
    }
    for (ll i = 0; i < N; ++i)
    {
        ++counts[S[i] - 'a'].count;
    }
    sort(rall(counts));
    vector<string> s(counts[0].count);
    for (ll i = 0; i < s.size(); ++i)
    {
        s[i].push_back(counts[0].m);
    }
    ll index = 0;
    ll countsIndex = 1;
    while (countsIndex < counts.size())
    {
        while (0 < counts[countsIndex].count)
        {
            s[index % s.size()].push_back(counts[countsIndex].m);
            --counts[countsIndex].count;
            ++index;
        };
        ++countsIndex;
    }
    if (s[s.size() - 1].size() == 1 && s[s.size() - 2].size() == 1)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (ll i = 0; i < s.size(); ++i)
    {
        cout << s[i];
    }
    cout << endl;
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

    std::cin >> TESTCASES;

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