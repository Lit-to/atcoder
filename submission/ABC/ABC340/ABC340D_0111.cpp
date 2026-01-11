// ABC340D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <map>
#include <queue>
#include <unordered_set>

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
    std::priority_queue<EDGE> tasks;
    tasks.push(EDGE{.m_to = 0, .m_cost = 0});
    std::unordered_set<int64_t> done;
    while (!tasks.empty())
    {
        EDGE pos = tasks.top();
        done.insert(pos.m_to);
        tasks.pop();
        if (pos.m_to == N - 1)
        {
            std::cout << pos.m_cost << std::endl;
            return 0;
        }
        for (EDGE i : GRAPH[pos.m_to])
        {
            if (!done.contains(i.m_to))
            {
                tasks.push(EDGE{.m_to = i.m_to, .m_cost = i.m_cost + pos.m_cost});
            }
        }
    }

    return 0;
}