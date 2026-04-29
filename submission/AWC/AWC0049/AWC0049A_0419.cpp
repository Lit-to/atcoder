// template
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
    int64_t N, L, P, Q;
    std::cin >> N >> L >> P >> Q;
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t s;
        std::cin >> s;
        if (s <= L)
        {
            std::cout << (s * P) / 100 << std::endl;
        }
        else
        {
            std::cout << (L * P + (s - L) * Q) / 100 << std::endl;
        }
    }
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