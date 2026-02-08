// ABC326C
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
int64_t search(int64_t ok, int64_t ng, Func eval)
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
int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    int64_t count = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t index = search(0, N, [&](int64_t x)
                               { return A[x] < A[i] + M; });
        count = std::max((index + 1) - i, count);
    }
    std::cout << count << std::endl;
}