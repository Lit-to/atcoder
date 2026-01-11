// ABC340D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <map>
#include <queue>
#include <set>

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
std::vector<int64_t> costs;
bool eval(int64_t &lhs, int64_t &rhs)
{
    return costs[lhs] < costs[rhs];
}
int main()
{

    int64_t N;
    std::cin >> N;
    struct EDGE
    {
        int64_t m_to;
        int64_t m_cost;
        bool operator<(const EDGE &rhs) const
        {
            return m_cost > rhs.m_cost;
        }
    };
    std::vector<std::vector<EDGE>> GRAPH(N);
    for (int64_t i = 0; i < N - 1; ++i)
    {
        int64_t a, b, x;
        std::cin >> a >> b >> x;
        GRAPH[i].push_back(EDGE{.m_to = i + 1, .m_cost = a});
        GRAPH[i].push_back(EDGE{.m_to = x - 1, .m_cost = b});
    }

    std::priority_queue<int64_t> tasks;
    tasks.push(0);

    while (!tasks.empty())
    {
        EDGE pos = tasks.top();
        if (pos.m_to == N - 1)
        {
            std::cout << pos.m_cost << std::endl;
            return 0;
        }
        tasks.pop();
        for (EDGE i : GRAPH[pos.m_to])
        {
            tasks.push(i.m_to);
        }
    }

    return 0;
}