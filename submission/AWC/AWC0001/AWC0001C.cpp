// AWC0001C
// template
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
    std::vector<int64_t> D(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> D[i];
    }
    std::sort(D.begin(), D.end());

    for (int64_t i = 0; i < K; ++i)
    {
        D[N - K + i] = 0;
    }
    int64_t result = 0;
    for (int64_t i = 0; i < D.size(); ++i)
    {
        result += D[i];
    }
    std::cout << result << std::endl;
}