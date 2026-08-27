// ABC424C
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
    struct AB
    {
        ll A;
        ll B;
    };
    vector<AB> skills(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> skills[i].A >> skills[i].B;
        --skills[i].A;
        --skills[i].B;
    }
    vector<vector<ll>> GRAPH(N);
    vector<ll> potential;
    for (ll i = 0; i < N; ++i)
    {
        if (skills[i].A == -1 && skills[i].B == -1)
        {
            potential.push_back(i);
        }
        if (skills[i].A != -1)
        {
            GRAPH[skills[i].A].push_back(i);
        }
        if (skills[i].B != -1)
        {
            GRAPH[skills[i].B].push_back(i);
        }
    }
    vector<bool> done(N);

    /**
     * DFSスニペット
     */
    auto dfs = [&](auto self, ll pos) -> void // 引数にノード、戻り値は適度に
    {
        // 訪問済み管理のチェック
        if (done[pos])
        {
            return;
        }

        // 訪問済み管理の登録
        done[pos] = true;
        // 行きがけ順に処理したい内容

        for (auto &dest : GRAPH[pos]) // 遷移処理
        {
            self(self, dest);
        }
        // 帰りがけ順に処理したい内容
    };
    for (auto &skill : potential)
    {
        dfs(dfs, skill);
    }
    ll result = 0;
    for (ll i = 0; i < N; ++i)
    {
        result += done[i];
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
