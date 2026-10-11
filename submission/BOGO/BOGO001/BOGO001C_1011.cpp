// BOGO001C
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
    const auto S = input<std::string>();
    const auto N = S.size();
    const auto K = input<ll>();
    auto isPalLast = [&](ll index) -> bool
    {
        return S[index - 2] == S[index];
    };
    auto isPalFirst = [&](ll index) -> bool
    {
        return S[index] == S[index + 2];
    };
    vector<ll> palsFirst(N); // 自分から始まる3文字が回文かどうかを持つ変数
    vector<ll> palsLast(N);  // 自分で終わる3文字が回文かどうかを持つ変数
    for (ll i = 2; i < N; ++i)
    {
        palsLast[i] = isPalLast(i);
    }
    for (ll i = 0; i < N - 2; ++i)
    {
        palsFirst[i] = isPalFirst(i);
    }
    vector<ll> prefixSumLast(N + 1);  // 累積
    vector<ll> prefixSumFirst(N + 1); // 累積
    for (ll i = 0; i < N; ++i)
    {
        prefixSumFirst[i + 1] = palsFirst[i] + prefixSumFirst[i];
        prefixSumLast[i + 1] = palsLast[i] + prefixSumLast[i];
    }
    ll result = 0;
    for (ll i = 0; i < N - 2; ++i)
    {
        if (isPalFirst(i))
        {
            ll right = std::min<ll>(i + K, N);
            ll left = i;
            result += prefixSumLast[right] - prefixSumFirst[left];
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

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
