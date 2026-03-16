// ABC313C
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
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    int64_t count = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t l = i;
        int64_t r = N - l - 1;
        if (l < r)
        {
            int64_t low_sep = (A[l] + A[r]) / 2;
            int64_t upp_sep = (A[l] + A[r] + 1) / 2;
            count += low_sep - A[l];
            count += A[r] - upp_sep;
            std::cerr << A[l] << " " << A[r] << "=>" << low_sep << " " << upp_sep << std::endl;
        }
        else
        {
            break;
        }
    }
    std::cout << count / 2 << std::endl;
}