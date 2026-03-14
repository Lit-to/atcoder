// TESOK001E
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
    int64_t N, K;
    std::cin >> N >> K;
    int64_t result = 0;
    for (int64_t i = 1; i <= N; ++i)
    {
        for (int64_t j = 1; j <= N; ++j)
        {
            for (int64_t k = 1; k <= N; ++k)
            {
                result += (i + j + k == K);
            }
        }
    }
    std::cout << result << std::endl;
}