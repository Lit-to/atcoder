// ABC360D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>

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
    int64_t N, T;
    std::cin >> N >> T;
    std::string S;
    std::cin >> S;
    std::vector<int64_t> X(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> X[i];
    }
    struct Ant
    {
        int64_t pos;
        int moveTo; // 1 right/0 left
        bool operator<(const Ant &rhs)
        {
            return this->pos < rhs.pos;
        }
    };
    std::vector<Ant> ants(0);
    for (int64_t i = 0; i < N; ++i)
    {
        ants.push_back(Ant{.pos = X[i], .moveTo = S[i] == '1'});
    }
    std::sort(ants.begin(), ants.end());
    std::queue<int64_t> q;
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        if (ants[i].moveTo == 1)
        {
            q.push(ants[i].pos + T);
        }
        else
        {
            while (!q.empty() && q.front() < ants[i].pos - T)
            {
                q.pop();
            }
            result += q.size();
        }
    }
    std::cout << result << std::endl;
}