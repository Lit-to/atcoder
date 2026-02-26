// ABC318C
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
    int64_t N, D, P;
    std::cin >> N >> D >> P;
    std::vector<int64_t> F(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> F[i];
    }
    std::sort(F.begin(), F.end());
    std::reverse(F.begin(), F.end());
    std::vector<int64_t> DPASS(N / D + 1);
    for (int i = 0; i < N; ++i)
    {
        DPASS[i / D] += F[i];
    }
    int64_t result = 0;
    for (int i = 0; i < DPASS.size(); ++i)
    {
        result += std::min(DPASS[i], P);
    }
    std::cout << result << std::endl;
}