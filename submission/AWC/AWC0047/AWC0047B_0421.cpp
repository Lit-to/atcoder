// AWC0047B
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
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> W(N);
    for (int64_t i = 1; i < N; ++i)
    {
        std::cin >> W[i];
    }
    int64_t result = N;
    for (int64_t i = 0; i < N; ++i)
    {
        if (W[i])
        {
            if (0 < M)
            {
                --M;
            }
            else
            {
                result = i;
                break;
            }
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