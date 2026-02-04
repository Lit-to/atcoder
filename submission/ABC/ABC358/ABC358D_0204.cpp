// ABC358D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 箱をソートして、二分探索する
 * 二分探索である箱iをもらってうれしくなれる人数xを求める
 * 最後に箱を前から順に見て、箱ひとつに1人を割り振ることが出来るか判定する
 *
 * # 具体的なロジック
 * 入力を受け取る
 * 箱ソート
 * 人間を前から順に見て、箱配列を二探する
 *   二探は箱の一番手前から末尾まで、条件は｢自分の欲しいお菓子の数以上の個数が入った箱かどうか｣
 *     =>自分の欲しい個数以上の一番少ない個数の箱を探す
 *   見つけたらその箱が欲しい人数を管理する配列に1を足す
 * 最後に前から順にある箱が欲しい人数を管理する配列を見る
 *   人数が1以上ならxに足す
 *   xが1以上ならその箱に1割り当てたものと見なして1減らす
 * 一番最後にxが0になれば金額の総和 そうでなければ-1
 */

/*===============================*/

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
bool eval(int64_t x, int64_t want, std::vector<int64_t> &boxes)
{
    return want <= boxes[x];
}

int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    ++N;
    std::vector<int64_t> A(N);
    A[0] = 0;
    for (int64_t i = 1; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::vector<int64_t> B(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> B[i];
    }
    std::sort(A.begin(), A.end());
    std::vector<int64_t> wishList(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t index = search(N, 0, [&](int64_t x)
                               { return eval(x, B[i], A); });
        if (index == N)
        {
            std::cout << -1 << std::endl;
            return 0;
        }
        ++wishList[index];
    }
    int64_t resource = 0;
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        resource += wishList[i];
        if (0 < resource)
        {
            result += A[i];
            --resource;
        }
    }
    if (resource != 0)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    else
    {
        std::cout << result << std::endl;
        return 0;
    }
}