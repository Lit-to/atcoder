#include <cstdint>

/**
 * @brief 順列を計算する
 * @param n n 母数
 * @param r r 項目数
 * @return nPrの計算結果
 *
 */
int64_t permutation(int64_t n, int64_t r)
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
int64_t factorial(int64_t n)
{
    return permutation(n, n);
}
/**
 * @brief 組み合わせを計算する
 * @param n 母数
 * @param r 選択数
 * @return nCrの計算結果
 *
 */
int64_t combination(int64_t n, int64_t r)
{
    int64_t result = 1;
    for (int64_t i = 0; i < r; ++i)
    {
        result *= (n - i);
        result /= i + 1;
    }
    return result;
}