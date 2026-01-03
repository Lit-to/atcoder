// ABC159D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <map>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
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
    for (int64_t i = n; n - r < i; --i)
    {
        result *= i;
    }
    return result;
}
int64_t permutation(int64_t n)
{
    return permutation(n, n);
}
int64_t combination(int64_t n, int64_t r)
{
    return permutation(n, r) / permutation(r);
}
int main()
{

    int64_t N;
    /*入力エリア
     */
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::map<int64_t, int64_t> map;
    for (int64_t i = 0; i < N; ++i)
    {
        if (!map.contains(A[i]))
        {
            map[A[i]] = 0;
        }
        ++map[A[i]];
    }
    int64_t result = 0;
    for (int64_t i = 1; i <= N; ++i)
    {
        result += combination(map[i], 2);
    }
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t temp = result;
        result -= combination(map[A[i]], 2);
        result += combination(map[A[i]] - 1, 2);
        std::cout << result << std::endl;
        result = temp;
    }

    /* 実装エリア
    * std::cout << " " << std::endl;

    */

    return 0;
}