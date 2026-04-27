// AWC0056A
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
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct aa
    {

        int64_t B;
        int64_t S;
    };
    std::vector<aa> BS(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> BS[i].B >> BS[i].S;
        --BS[i].B;
    }
    int64_t result = 0;
    for (int64_t j = 0; j < M; ++j)
    {
        result += A[BS[j].B] + BS[j].S;
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