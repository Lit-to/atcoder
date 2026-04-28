// AWC0057B
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
template <class T>
void v_output(const std::vector<T> &a)
{
    for (int64_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N;
    cin >> N;
    vector<ll> K(N);
    vector<vector<string>> S(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> K[i];
        vector<string> s(K[i]);
        for (ll j = 0; j < K[i]; ++j)
        {
            cin >> s[j];
        }
        S[i] = s;
    }
    ll Q;
    cin >> Q;
    vector<string> T(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> T[i];
    }
    for (string &query : T)
    {
        ll result = 0;
        for (ll i = 0; i < N; ++i)
        {
            for (string &s : S[i])
            {
                ll r = result;
                ll q_s = 0;
                for (ll j = 0; j < s.size(); ++j)
                {
                    if (s[j] == query[q_s])
                    {
                        ++q_s;
                        if (q_s == query.size())
                        {
                            ++result;
                            break;
                        }
                    }
                }
                if (r != result)
                {
                    break;
                }
            }
        }
        cout << result << endl;
    }
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