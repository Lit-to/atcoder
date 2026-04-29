// ABC450D
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
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    //
    std::vector<int64_t> nums(N * 2);
    for (int64_t i = 0; i < N; ++i)
    {
        nums[i] += A[i] % K;
        nums[i + N] += A[i] % K + K;
    }
    std::sort(nums.begin(), nums.end());
    int64_t result = INT64_MAX;
    for (int64_t i = 0; i < N; ++i)
    {
        result = std::min(nums[i + N - 1] - nums[i], result);
    }
    std::cout << result << std::endl;
}