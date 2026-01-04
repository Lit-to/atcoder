// ABC185C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
/**
 *方針メモ欄
 *
 * # お気持ち
 * 切る場所全列挙
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * permutationの実装を軽くしたい
 *
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
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
int64_t factorial(int64_t n)
{
    return permutation(n, n);
}
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
int main()
{
    int64_t N;
    std::cin >> N;
    std::cout << combination(N - 1, 11) << std::endl;

    return 0;
}