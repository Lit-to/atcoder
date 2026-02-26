// ABC355C
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
    int64_t N, T;
    std::cin >> N >> T;
    std::vector<int64_t> A(T);
    for (int i = 0; i < T; ++i)
    {
        std::cin >> A[i];
        --A[i];
    }
    std::vector<int64_t> row(N);
    std::vector<int64_t> column(N);
    std::vector<int64_t> x(2);

    for (int i = 0; i < T; ++i)
    {
        if (++row[(A[i] / N)] == N)
        {
            std::cout << i + 1 << std::endl;
            return 0;
        }
        if (++column[(A[i] % N)] == N)
        {
            std::cout << i + 1 << std::endl;
            return 0;
        }
        if (A[i] / N == A[i] % N)
        {
            if (++x[0] == N)
            {
                std::cout << i + 1 << std::endl;
                return 0;
            }
        }
        if (A[i] / N + A[i] % N == N - 1)
        {
            if (++x[1] == N)
            {
                std::cout << i + 1 << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1 << std::endl;
}