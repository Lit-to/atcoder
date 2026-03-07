// ABC363C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
/**
 * @brief 順列を計算する
 * @param n n 母数
 * @param r r 項目数
 * @return nPrの計算結果
 *
 */
int64_t Permutation(int64_t n, int64_t r)
{
    int64_t result = 1;
    for (int64_t i = 0; i < r; ++i)
    {
        result *= (n - i);
    }
    return result;
}
/**
 * @brief 階乗を計算する
 * @param n 値
 * @return n!の計算結果
 *
 */
int64_t Factorial(int64_t n)
{
    return Permutation(n, n);
}
/**
 * @brief 組み合わせを計算する
 * @param n 母数
 * @param r 選択数
 * @return nCrの計算結果
 *
 */
int64_t Combination(int64_t n, int64_t r)
{
    int64_t result = 1;
    for (int64_t i = 0; i < r; ++i)
    {
        result *= (n - i);
        result /= i + 1;
    }
    return result;
}
bool isPallindrome(std::string a, int begin, int end)
{
    int count = 0;
    int size = end - begin;
    for (int i = 0; i < size / 2; ++i)
    {
        if (a[begin + i] != a[end - 1 - i])
        {
            return false;
        }
        ++count;
    }
    return true;
}
bool hasPallindrome(std::string a, int k)
{
    for (int i = 0; i + k <= a.size(); ++i)
    {
        if (isPallindrome(a, i, i + k))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int64_t N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;
    std::unordered_set<std::string> done;
    int64_t max = Combination(N, 2);
    std::sort(S.begin(), S.end());
    int64_t result = 0;
    int64_t count = 0;
    while (count <= Factorial(N))
    {
        if (!done.contains(S) && !hasPallindrome(S, K))
        {
            ++result;
        }
        done.insert(S);
        ++count;
        std::next_permutation(S.begin(), S.end());
    }
    std::cout << result << std::endl;
}