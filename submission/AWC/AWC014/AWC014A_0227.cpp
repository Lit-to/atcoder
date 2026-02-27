// AWC014A
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/

int main()
{
    int64_t N, R, T;
    std::cin >> N >> R >> T;
    std::vector<int64_t> P(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> P[i];
    }
    for (int i = 0; i < N; ++i)
    {
        if (P[i] * R <= T)
        {
            std::cout << R << " ";
        }
        else
        {
            std::cout << T / P[i] << " ";
        }
    }
    std::cout << std::endl;
}