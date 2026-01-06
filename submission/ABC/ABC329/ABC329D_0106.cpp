// ABC329D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 二人の人間を突き合せて当選者が誰かを決め打つ評価関数fを作る
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 * f(a,b)を実装する
 * aかbのうち得票が大きいほうか、得票が同じ場合番号が若いほうを返す関数
 * 得票はstd::vectorかなんかでi人目の得票数を持っておく
 *
 *
 *
 *
 * # 出力
 *
 *
 */

/**
 * 評価関数
 */
int64_t eval(int64_t personA, int64_t personB, std::vector<int64_t> &points)
{
    if (points[personA] == points[personB])
    {
        return std::min(personA, personB);
    }
    else if (points[personA] < points[personB])
    {
        return personB;
    }
    else
    {
        return personA;
    }
}

int main()
{

    /*入力エリア
     * std::cin >> N;
     */
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> A(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> A[i];
        --A[i];
    }
    std::vector<int64_t> points(N);
    int64_t winner = 0;
    for (int64_t i = 0; i < M; ++i)
    {
        ++points[A[i]];
        winner = eval(A[i], winner, points);
        std::cout << winner + 1 << std::endl;
    }
    return 0;
}