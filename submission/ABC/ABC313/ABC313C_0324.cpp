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
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    int64_t s = Sum(A);
    std::sort(A.begin(), A.end());
    int64_t p = s / N;
    int64_t r = s % N;
    std::vector<int64_t> B(N);
    for (int64_t i = 0; i < N; ++i)
    {
        if (i < N - r)
        {
            B[i] = p;
        }
        else
        {
            B[i] = p + 1;
        }
    }
    int64_t t = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        t += std::abs(A[i] - B[i]);
    }
    std::cout << t / 2 << std::endl;
}