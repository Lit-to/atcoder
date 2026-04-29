// ABC270C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stack>
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
    std::stack<int64_t> tasks;
    tasks.push(Y);
    std::stack<int64_t> route;
    std::vector<bool> done(N);
    while (!tasks.empty())
    {
        int64_t pos = tasks.top();
        done[pos] = true;
        if (route.empty() || route.top() != pos)
        {
            route.push(pos);
        }
        if (pos == X)
        {
            break;
        }
        for (int64_t node : GRAPH[pos])
        {
            if (done[node])
            {
                continue;
            }
            done[pos] = true;
            tasks.push(node);
        }
        if (tasks.top() == pos)
        {
            route.pop();
            tasks.pop();
        }
    }
    while (!route.empty())
    {
        std::cout << route.top() + 1 << " ";
        route.pop();
    }
    std::cout << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================