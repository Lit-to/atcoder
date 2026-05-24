// ABC409D
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

std::string rotateString(std::string &s)
{
    ll f = s[0];
    s.push_back(f);
    s.erase(s.begin());
    return s;
}
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N;
    string S;
    cin >> N;
    cin >> S;
    if (N == 1)
    {
        cout << S << endl;
        return;
    }
    ll l = -1;
    for (ll i = 0; i < N - 1; ++i)
    {
        if (S[i] > S[i + 1])
        {
            l = i;
            break;
        }
    }
    if (l == -1)
    {
        cout << S << endl;
        return;
    }
    ll r = l;
    while (r < N && S[l] >= S[r])
    {
        ++r;
    }
    string sep = S.substr(l, r - l);
    cout << S.substr(0, l);
    cout << rotateString(sep);
    cout << S.substr(r);
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