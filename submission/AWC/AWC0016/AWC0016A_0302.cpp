// AWC0016A
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
template <class T>
typename T::value_type Sum(const T &target)
{
    typename T::value_type now = 0;
    for (auto &i : target)
    {
        now += i;
    }
    return now;
}

int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        std::cin >> B[i];
    }
    std::vector<int64_t> result(0);
    for (int64_t i = 0; i < N; ++i)
    {
        if (B[i] < A[i])
        {
            result.push_back(A[i] - B[i]);
        }
    }
    std::cout << result.size() << " " << Sum(result) << std::endl;
}