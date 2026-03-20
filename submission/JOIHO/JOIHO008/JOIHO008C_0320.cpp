// JOIHO008C
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
int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> P(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> P[i];
    }
    std::vector<int64_t> AB;
    for (int64_t i = 0; i < N; ++i)
    {
        AB.push_back(P[i]);
        for (int64_t j = 0; j < N; ++j)
        {
            AB.push_back(P[i] + P[j]);
        }
    }
    std::sort(AB.begin(), AB.end());
    int64_t result = 0;
    for (int64_t i = 0; i < AB.size(); ++i)
    {
        if (M < AB[i])
        {
            break;
        }
        int64_t index = Search(0, AB.size(), [&](int64_t x)
                               { return AB[i] + AB[x] <= M; });
        if (AB[i] + AB[index] <= M)
        {
            result = std::max(AB[index] + AB[i], result);
        }
    }
    std::cout << result << std::endl;
}