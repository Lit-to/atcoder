// AWC0049B
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
    int64_t S, T, K;
    std::cin >> S >> T >> K;
    ++K;
    for (int64_t i = 0; i < K; ++i)
    {
        if (T < S)
        {
            std::cout << -1 << std::endl;
            return;
        }
        else if (S == T)
        {
            std::cout << i << std::endl;
            return;
        }
        S *= 2;
    }
    std::cout << -1 << std::endl;
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