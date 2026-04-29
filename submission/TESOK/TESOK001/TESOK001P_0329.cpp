// TESOK001P
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
    greater_priority_queue<node> pq;
    pq.push(node{.id = 0, .cost = 0});
    std::vector<int64_t> result(N, INT64_MAX);
    std::vector<bool> done(N);
    while (!pq.empty())
    {
        node task = pq.top();
        pq.pop();
        if (done[task.id])
        {
            continue;
        }
        done[task.id] = true;
        result[task.id] = std::min(result[task.id], task.cost);
        if (task.id == N - 1)
        {
            continue;
        }
        for (node &i : GRAPH[task.id])
        {
            if (done[i.id])
            {
                continue;
            }
            pq.push(node{.id = i.id, .cost = std::min(result[i.id], task.cost + i.cost)});
        }
    }
    std::cout << result[N - 1] << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================