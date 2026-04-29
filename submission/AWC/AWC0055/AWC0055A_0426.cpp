// AWC0055A
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
    int64_t N, K;
    std::cin >> N >> K;
    std::vector<int64_t> D(N + 1);
    ++N;
    for (int64_t i = 1; i < N; ++i)
    {
        std::cin >> D[i];
    }
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        if ((i % (K + 1)) != 0)
        {
            result += D[i];
        }
    }
    std::cout << result << std::endl;
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