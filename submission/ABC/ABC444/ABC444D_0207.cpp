// ABC444D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <limits>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
namespace litUtility
{
    template <class T>
    typename T::value_type max(const T &target)
    {
        typename T::value_type nowMax = std::numeric_limits<typename T::value_type>::min();
        for (auto &i : target)
        {
            if (nowMax < i)
            {
                nowMax = i;
            }
        }
        return nowMax;
    }

    template <class T>
    typename T::value_type min(const T &target)
    {
        typename T::value_type nowMin = std::numeric_limits<typename T::value_type>::max();
        for (auto &i : target)
        {
            if (i < nowMin)
            {
                nowMin = i;
            }
        }
        return nowMin;
    }
};
int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::vector<int64_t> oneCount(litUtility::max(A) + 1);
    for (int64_t i = 0; i < N; ++i)
    {
        ++oneCount[A[i]];
    }
    for (int64_t i = oneCount.size() - 1; 1 < i; --i)
    {
        oneCount[i - 1] += oneCount[i];
    }
    int64_t nextDigit = 0;
    for (int64_t i = 1; i < oneCount.size(); ++i)
    {
        oneCount[i] += nextDigit;
        nextDigit = oneCount[i] / 10;
        oneCount[i] %= 10;
    }
    if (0 < nextDigit)
    {
        std::cout << nextDigit;
    }
    for (int64_t i = oneCount.size() - 1; 1 <= i; --i)
    {
        std::cout << oneCount[i];
    }
    std::cout << std::endl;
}