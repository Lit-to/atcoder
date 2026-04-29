// TESOK001L
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
/**
 * 二分探索関数
 * 評価関数evalがtrueになる範囲とfalseになる範囲の境界値を求める
 * @param ok trueになる片極端
 * @param ng falseになる片極端
 * @param eval 評価関数
 */
template <class Func>
int64_t Search(int64_t ok, int64_t ng, Func eval)
{
    while (1 < std::abs(ok - ng))
    {
        int64_t mid = (ok + ng) / 2;
        if (eval(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    return ok;
}
std::vector<int64_t> A;
int64_t count(int64_t seconds)
{
    int64_t result = 0;
    for (int64_t i = 0; i < A.size(); ++i)
    {
        result += seconds / A[i];
    }
    return result;
}

int main()
{
    int64_t N, K;
    std::cin >> N >> K;
    A.resize(N);

    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    int64_t result = 0;
    int64_t index = Search(10000000001, 0, [&](int64_t x)
                           { return K <= count(x); });
    std::cout << index << std::endl;
}