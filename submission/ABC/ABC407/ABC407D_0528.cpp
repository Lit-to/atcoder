// ABC407D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
// using namespace std;
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
    ll H, W;
    std::cin >> H >> W;
    std::vector<std::vector<ll>> BOARD(H, std::vector<ll>(W));
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            std::cin >> BOARD[i][j];
        }
    }
    std::vector<std::vector<bool>> isCovered(H, std::vector<bool>(W));
    ll result = 0;
    auto dfs = [&](auto self, std::vector<std::vector<bool>> &isCovered, ll i, ll j) -> void
    {
        if (j == W)
        {
            j = 0;
            ++i;
        }
        if (i == H)
        {
            ll now = 0;
            for (ll i = 0; i < H; ++i)
            {
                for (ll j = 0; j < W; ++j)
                {
                    if (!isCovered[i][j])
                    {
                        now ^= BOARD[i][j];
                    }
                }
            }
            result = std::max(result, now);
            return;
        }
        if (isCovered[i][j])
        {
            self(self, isCovered, i, j + 1);
        }
        else
        {
            self(self, isCovered, i, j + 1);
            if (j + 1 < W && !isCovered[i][j + 1])
            {
                isCovered[i][j] = true;
                isCovered[i][j + 1] = true;
                self(self, isCovered, i, j + 1);
                isCovered[i][j] = false;
                isCovered[i][j + 1] = false;
            }
            if (i + 1 < H && !isCovered[i + 1][j])
            {
                isCovered[i][j] = true;
                isCovered[i + 1][j] = true;
                self(self, isCovered, i, j + 1);
                isCovered[i][j] = false;
                isCovered[i + 1][j] = false;
            }
        }
    };
    dfs(dfs, isCovered, 0, 0);
    std::cout << result << std::endl;
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