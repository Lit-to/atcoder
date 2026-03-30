// TESOK001Q
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
//
int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    struct node
    {
        int64_t id;
        int64_t cost;
        bool operator<(const node &rhs) const
        {
            return this->cost < rhs.cost;
        }
        bool operator>(const node &rhs) const
        {
            return this->cost > rhs.cost;
        }
    };
    for (int64_t i = 1; i < N; ++i)
    {
        std::cin >> A[i];
    }
    for (int64_t i = 2; i < N; ++i)
    {
        std::cin >> B[i];
    }
    std::vector<std::vector<node>> GRAPH(N);
    for (int64_t i = 0; i < N - 1; ++i)
    {
        GRAPH[i].push_back(node{.id = i + 1, .cost = A[i + 1]});
    }
    for (int64_t i = 0; i < N - 2; ++i)
    {
        GRAPH[i].push_back(node{.id = i + 2, .cost = B[i + 2]});
    }
    std::vector<int64_t> result(N, INT64_MAX);
    std::vector<bool> done(N);
    struct element
    {
        int64_t node;
        int64_t cost;
        int64_t previous;
        bool operator<(const element &rhs) const
        {
            return this->cost < rhs.cost;
        }
        bool operator>(const element &rhs) const
        {
            return this->cost > rhs.cost;
        }
    };
    greater_priority_queue<element> pq;
    pq.push(element{.node = 0, .cost = 0, .previous = -1});
    std::vector<int64_t> result_prev(N);
    while (!pq.empty())
    {
        element task = pq.top();
        pq.pop();
        if (done[task.node])
        {
            continue;
        }
        done[task.node] = true;
        if (task.cost < result[task.node])
        {
            result[task.node] = task.cost;
            result_prev[task.node] = task.previous;
        }
        if (task.node == N - 1)
        {
            continue;
        }
        for (node &i : GRAPH[task.node])
        {
            if (done[i.id])
            {
                continue;
            }
            pq.push(element{.node = i.id, .cost = std::min(result[i.id], task.cost + i.cost), .previous = task.node});
        }
    }
    std::cerr << result[N - 1] << std::endl;
    std::vector<int64_t> route;
    int64_t pos = N - 1;
    while (pos != -1)
    {
        route.push_back(pos);
        pos = result_prev[pos];
    }
    std::reverse(route.begin(), route.end());
    std::cout << route.size() << std::endl;
    for (int64_t i = 0; i < route.size(); ++i)
    {
        std::cout << route[i] + 1 << " ";
    }
    std::cout << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================