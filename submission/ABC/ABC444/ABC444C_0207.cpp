// ABC444C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_map>

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
    template <class T>
    typename T::value_type sum(const T &target)
    {
        typename T::value_type now = 0;
        for (auto &i : target)
        {
            now += i;
        }
        return now;
    }
};
std::unordered_map<int64_t, int64_t> coderiko;
bool canMakeCoderiko(int64_t l)
{
    for (const std::pair<int64_t, int64_t> &i : coderiko)
    {
        if (i.first == l)
        {
            continue;
        }
        if (!coderiko.contains(l - i.first) || coderiko[i.first] != coderiko[l - i.first])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; ++i)
    {
        ++coderiko[A[i]];
    }
    int64_t sum = litUtility::sum(A);
    std::vector<int64_t> divisors;
    for (int64_t i = 1; i <= N; ++i)
    {
        if (sum % i == 0)
        {
            divisors.push_back(sum / i);
        }
    }
    std::sort(divisors.begin(), divisors.end());
    std::vector<int64_t> result;
    for (int64_t i = 0; i < divisors.size(); ++i)
    {
        if (canMakeCoderiko(divisors[i]))
        {
            result.push_back(divisors[i]);
        }
    }
    for (int64_t &i : result)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}