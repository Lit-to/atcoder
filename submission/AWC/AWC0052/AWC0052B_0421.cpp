// AWC0052B
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
    int64_t N, K;
    std::cin >> N >> K;
    std::vector<int64_t> CARDS(N);
    for (int64_t i = 0; i < N; ++i)
    {
        CARDS[i] = i + 1;
    }
    int64_t f = N - (K % N) + N;
    int64_t count = f;
    while (count < f + N)
    {
        std::cout << CARDS[count % N] << std::endl;
        ++count;
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