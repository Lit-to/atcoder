// ABC084D
// clang-format off
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::cin;using std::cout;using std::endl;using std::vector;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on
// bool isPrime(ll num)
// {
//     for (ll i = 2; i * i <= num; ++i)
//     {
//         if (num % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /*
    // const auto S = input<std::string>();
    // const auto A = input<ll>(10);
    */
    // const auto N = 20;
    const auto N = 1e5 + 1;
    std::unordered_set<ll> scopes;
    std::unordered_set<ll> primes;
    vector<bool> isNotPrime(N);
    for (ll i = 2; i < N; ++i)
    {
        if (isNotPrime[i] == true)
        {
            continue;
        }
        for (ll j = i; i * j < N; ++j)
        {
            isNotPrime[i * j] = true;
        }
    }
    for (ll i = 2; i < N; ++i)
    {

        if (!isNotPrime[i])
        {
            primes.insert(i);
            if (i % 2 == 1 && primes.contains((i + 1) / 2))
            {
                scopes.insert(i);
            }
        }
    }
    vector<ll> scopeCount(N);
    for (auto &score : scopes)
    {
        ++scopeCount[score];
    }

    vector<ll> preSum(N + 1);
    for (ll i = 0; i < N; ++i)
    {
        preSum[i + 1] = preSum[i] + scopeCount[i];
    }
    const auto Q = input<ll>();
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
    vector<SECTION> sections(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> sections[i].l >> sections[i].r;
        --sections[i].l;
    }
    for (auto &section : sections)
    {
        ll result = preSum[section.r + 1] - preSum[section.l];
        cout << result << endl;
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