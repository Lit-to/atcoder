// ABC270C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
//
int main()
{

    int64_t N, X, Y;
    std::cin >> N >> X >> Y;
    --X;
    --Y;

    std::vector<std::vector<int64_t>> GRAPH(N, std::vector<int64_t>());
    for (int64_t i = 0; i < N - 1; ++i)
    {
        int64_t u, v;
        std::cin >> u >> v;
        GRAPH[v - 1].push_back(u - 1);
        GRAPH[u - 1].push_back(v - 1);
    }
    struct task
    {
        int64_t node;
        int64_t from;
    };
    std::queue<task> tasks;
    tasks.push(task{.node = Y, .from = -2});
    std::vector<int64_t> done(N, -1);
    while (!tasks.empty())
    {
        task pos = tasks.front();
        tasks.pop();
        done[pos.node] = pos.from;
        if (pos.node == X)
        {
            break;
        }
        for (int64_t node : GRAPH[pos.node])
        {
            if (done[node] != -1)
            {
                continue;
            }
            done[node] = pos.node;
            tasks.push(task{.node = node, .from = pos.node});
        }
    }
    int64_t to = X;
    while (done[to] != -2)
    {
        std::cout << to + 1 << " ";
        to = done[to];
    }
    std::cout << Y + 1 << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================

/**
8 6 7
3 1
2 5
1 5
4 1
2 6
5 7
1 8

=> 6 2 5 7

 */
