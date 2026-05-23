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

std::string gen(string &a, ll ac, string &b, ll bc)
{
    string result = "";
    if (2 <= abs(ac - bc))
    {
        return result;
    }
    else
    {
        if (ac < bc)
        {
            swap(ac, bc);
            swap(a, b);
        }
        ll aindex = 0;
        ll bindex = 0;
        for (ll i = 0; i < ac + bc; ++i)
        {
            if (i % 2 == 0)
            {
                result.push_back(a[aindex]);
                ++aindex;
            }
            else
            {
                result.push_back(b[bindex]);
                ++bindex;
            }
        }
        return result;
    }
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    string S;
    cin >> S;
    ll N = S.size();
    struct charact
    {
        ll count;
        string m;
        bool operator<(const charact &target) const
        {
            return count < target.count;
        }
    };
    vector<charact> counts(26);
    // for (ll i = 0; i < 26; ++i)
    // {
    // counts[i].m
    // }
    for (ll i = 0; i < N; ++i)
    {
        ++counts[S[i] - 'a'].count;
        counts[S[i] - 'a'].m.push_back(S[i]);
    }
    sort(rall(counts));
    charact result;
    result.count = counts[0].count;
    result.m = counts[0].m;
    for (ll i = 1; i < 25; ++i)
    {
        string r1 = gen(counts[i].m, counts[i].count, counts[i + 1].m, counts[i + 1].count);
        if (r1.size() == 0)
        {
            break;
        }
        string r2 = gen(result.m, result.count, counts[i].m, counts[i].count);
        result.count = r2.size();
        result.m = r2;
    }
    if (result.m.size() != N)
    {
        cout << "No" << endl;
        return;
    }
    cout << result.m << endl;
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