// ABC475D
// template
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>

#include <map>
template <class KEY_TYPE, class VALUE_TYPE>
using TreeMap = std::map<KEY_TYPE, VALUE_TYPE>;
#include <unordered_map>
template <class KEY_TYPE, class VALUE_TYPE>
using HashMap = std::unordered_map<KEY_TYPE, VALUE_TYPE>;

#include <set>
template <class VALUE_TYPE>
using TreeSet = std::set<VALUE_TYPE>;
#include <unordered_set>
template <class VALUE_TYPE>
using HashSet = std::unordered_set<VALUE_TYPE>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
T input()
{
    T variable;
    cin >> variable;
    return variable;
}
template <typename T>
std::vector<T> input(int64_t n)
{
    std::vector<T> contents(n);
    for (int64_t i = 0; i < n; ++i)
    {
        contents[i] = input<T>();
    }
    return contents;
}
// 自作ライブラリここから

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力スニペ
    // const auto A = input<ll>(N);
    //
    const auto S = input<std::string>();
    const auto N = S.size();
    vector<ll> primes;
    HashSet<ll> notPrimes;
    const ll INF = 1e7;
    for (ll i = 2; i < INF; ++i)
    {
        if (notPrimes.contains(i))
        {
            continue;
        }
        for (ll j = 2; j < INF; ++j)
        {
            ll num = i * j;
            if (num < INF)
            {
                notPrimes.insert(num);
            }
            else
            {
                break;
            }
        }
    }
    for (ll i = 2; i < INF; ++i)
    {
        if (notPrimes.contains(i))
        {
            continue;
        }
        primes.push_back(i);
    }
    std::string s = S;
    std::reverse(all(s));
    ll result = -1;

    for (auto &prime : primes)
    {
        ll p = prime;
        vector<ll> d;
        while (0 < p)
        {
            d.push_back(p % 10);
            p /= 10;
        }
        auto eval = [&](vector<ll> d)
        {
            vector<vector<ll>> ti;
            if (d.size() != s.size())
            {
                return false;
            }
            for (ll i = 0; i < N; ++i)
            {
                for (ll j = 0; j < N; ++j)
                {
                    if (d[i] == d[j] && s[i] == s[j] || d[i] != d[j] && s[i] != s[j])
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        };
        if (eval(d))
        {
            result = prime;
            break;
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
    int64_t TESTCASES = DEFAULT_TESTCASE;
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

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
