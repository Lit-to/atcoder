// ABC0048B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> H(N);
    std::vector<int64_t> D(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> H[i];
    }
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> D[i];
    }
    std::vector<bool> TILES(N, true);
    for (int64_t i = 0; i < N; ++i)
    {
        if (H[i] == 0 || D[i] == 0)
        {
            TILES[i] = false;
        }
    }
    std::vector<int64_t> DP(N, INT64_MAX);
    for (int64_t i = 0; i < N; ++i)
    {
        if (i == 0)
        {
            DP[i] = TILES[i];
        }
        else if (i == 1)
        {
            DP[i] = DP[i - 1] + TILES[i];
        }
        else
        {
            DP[i] = std::min<int64_t>(DP[i - 2] + TILES[i], DP[i - 1] + TILES[i]);
        }
    }
    std::cout << DP[N - 1] << std::endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
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