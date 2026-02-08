// ABC330C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>

/**
 *方針メモ欄
 *
 * # お気持ち
 *    全探索
 *    最初に平方数を10^6+100まで全列挙し、vectorに入れておく
 *    で、xを決め打ってyを二探で探す
 *      1.{(x+y)がD未満になる一番大きいインデックスを見つける}
 *      2.{(x+y)がD以上になる一番小さいインデックスを見つける}
 *    1.2.の値が小さいほうを使って答えの最小更新
 * # 具体的なロジック
 *
 */

/*=========================*/
#include <cstdint>
#include <cmath>
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
    int64_t D;
    std::cin >> D;
    std::vector<int64_t> candidates;
    for (int64_t i = 0; i < 1000000 + 1000; ++i)
    {
        candidates.push_back(i * i);
    }
    int64_t N = candidates.size();
    int64_t result = INT64_MAX;
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t C = candidates[i] - D;
        if (0 <= C)
        {
            result = std::min(result, C);
            continue;
        }
        int64_t y_1 = std::floor(std::sqrt(-1 * C));
        int64_t y_2 = std::ceil(std::sqrt(-1 * C));
        result = std::min<int64_t>(result, abs(C + y_1 * y_1));
        result = std::min<int64_t>(result, abs(C + y_2 * y_2));
    }

    std::cout << result << std::endl;
}