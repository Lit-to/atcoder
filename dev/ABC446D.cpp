// ABC446D
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
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    int64_t result = INT64_MAX;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    int right = 0;
    for (int left = 0; left < N; ++left)
    {
        if (right <= left)
        {
            right = left + 1;
        }
        while (A[right - 1] + 1 == A[right])
        {
            ++right;
        }
        result = std::min<int64_t>(result, right - left);
    }
    std::cout << result << std::endl;
}