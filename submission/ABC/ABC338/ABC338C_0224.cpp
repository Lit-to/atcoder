// ABC338C
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

int64_t make(int64_t x, std::vector<int64_t> &A, std::vector<int64_t> &B, std::vector<int64_t> Q)
{
    for (int i = 0; i < Q.size(); ++i)
    {
        Q[i] -= A[i] * x;
        if (Q[i] < 0)
        {
            return 0;
        }
    }
    int64_t bCount = INT64_MAX;
    for (int i = 0; i < Q.size(); ++i)
    {
        if (B[i] == 0)
        {
            continue;
        }
        bCount = std::min(bCount, Q[i] / B[i]);
    }
    return x + bCount;
}
int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> Q(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> Q[i];
    }
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::vector<int64_t> B(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> B[i];
    }
    int64_t result = 0;
    for (int i = 0; i < 2 * 1000000; ++i)
    {
        result = std::max(result, make(i, A, B, Q));
    }
    std::cout << result << std::endl;
}