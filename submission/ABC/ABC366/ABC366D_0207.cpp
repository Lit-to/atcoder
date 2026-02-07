// ABC366D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/

// std::vector<int64_t> sumLine(std::vector<int64_t> &line)
// {
//     std::vector<int64_t> newLine(line.size());
//     newLine[0] = line[0];
//     for (int64_t i = 1; i < line.size(); ++i)
//     {
//         newLine[i] = newLine[i - 1] + line[i];
//     }
//     return newLine;
// }

int main()
{
    int64_t N;
    std::cin >> N;
    ++N;
    std::vector<std::vector<std::vector<int64_t>>> prefixSum(N, std::vector<std::vector<int64_t>>(N, std::vector<int64_t>(N)));
    for (int64_t i = 1; i < N; ++i)
    {
        for (int64_t j = 1; j < N; ++j)
        {
            for (int64_t k = 1; k < N; ++k)
            {
                std::cin >> prefixSum[i][j][k];
            }
        }
    }
    int64_t Q;
    std::cin >> Q;
    std::vector<std::vector<int64_t>> QUERIES(Q, std::vector<int64_t>(6));
    for (int64_t i = 0; i < Q; ++i)
    {
        for (int64_t j = 0; j < 6; ++j)
        {
            std::cin >> QUERIES[i][j];
        }
    }
    // 前計算 -k
    for (int64_t i = 0; i < N; ++i)
    {
        for (int64_t j = 0; j < N; ++j)
        {
            for (int64_t k = 1; k < N; ++k)
            {
                prefixSum[i][j][k] += prefixSum[i][j][k - 1];
            }
        }
    }

    // 前計算 -j
    for (int64_t i = 0; i < N; ++i)
    {
        for (int64_t j = 1; j < N; ++j)
        {
            for (int64_t k = 0; k < N; ++k)
            {
                prefixSum[i][j][k] += prefixSum[i][j - 1][k];
            }
        }
    }
    // 前計算 -i
    for (int64_t i = 1; i < N; ++i)
    {
        for (int64_t j = 0; j < N; ++j)
        {
            for (int64_t k = 0; k < N; ++k)
            {
                prefixSum[i][j][k] += prefixSum[i - 1][j][k];
            }
        }
    }

    // クエリ処理
    for (int64_t i = 0; i < Q; ++i)
    {
        // 緑
        int64_t L[3] = {QUERIES[i][0],
                        QUERIES[i][2],
                        QUERIES[i][4]};
        int64_t R[3] = {QUERIES[i][1],
                        QUERIES[i][3],
                        QUERIES[i][5]};
        int64_t green = prefixSum[R[0]][R[1]][R[2]];
        // 青
        int64_t blue = 0;
        blue += prefixSum[L[0] - 1][R[1]][R[2]];
        blue += prefixSum[R[0]][L[1] - 1][R[2]];
        blue += prefixSum[R[0]][R[1]][L[2] - 1];
        // 黄
        int64_t yellow = 0;
        yellow += prefixSum[L[0] - 1][L[1] - 1][R[2]];
        yellow += prefixSum[R[0]][L[1] - 1][L[2] - 1];
        yellow += prefixSum[L[0] - 1][R[1]][L[2] - 1];
        // 赤
        int64_t red = prefixSum[L[0] - 1][L[1] - 1][L[2] - 1];
        // 合計
        std::cout << green - blue + yellow - red << std::endl;
    }
}