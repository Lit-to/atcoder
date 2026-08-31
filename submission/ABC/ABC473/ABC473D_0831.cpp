// ABC473D
// clang-format off
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cin;using std::cout;using std::endl;using std::vector;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on

ll calc(vector<ll> &v)
{
    ll result = 0;
    for (ll i = 0; i < v.size(); ++i)
    {
        result += v[i] * (i + 1);
    }
    return result;
}
ll eval(vector<ll> &v, ll k)
{
    return calc(v) == k;
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /*
    // const auto S = input<std::string>();
    // const auto A = input<ll>(10);
    */
    const auto N = input<ll>();
    const auto K = input<ll>();
    vector<vector<ll>> result;
    vector<ll> r(N);
    /**
     * DFSスニペット
     */
    auto dfs = [&](auto self, ll index, ll value, ll sum) -> bool // 引数にノード、戻り値は適度に
    {
        // 行きがけ順に処理したい内容
        r[index] = value;
        sum += value * (index + 1);
        if (K < sum)
        {
            return true;
        }
        if (N - 2 <= index)
        {
            ll last = (K - sum) / N;
            if (0 <= last)
            {
                r[N - 1] = last;
                vector<ll> temp(N);
                std::copy(all(r), temp.begin());
                result.push_back(temp);
            }
            return false;
        }

        for (ll i = 0; i < K + 1; ++i) // 遷移処理
        {
            if (self(self, index + 1, i, sum))
            {
                break;
            };
        }
        // 帰りがけ順に処理したい内容
        return false;
    };
    for (ll i = 0; i < K + 1; ++i)
    {
        dfs(dfs, 0, i, 0);
    }
    for (auto &ans : result)
    {
        for (ll i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
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

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
