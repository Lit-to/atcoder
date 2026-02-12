// ABC443C
// template
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

int main()
{
    int64_t N, T;
    std::cin >> N >> T;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    if (N == 0)
    {
        std::cout << T << std::endl;
        return 0;
    }
    int64_t open = 0;
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        if (open < A[i])
        {
            result += A[i] - open;
            open = A[i] + 100;
        }
    }
    if (open < T)
    {
        result += T - open;
    }

    std::cout << result << std::endl;
}