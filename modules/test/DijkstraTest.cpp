#include <cstdint>
#include <iostream>
#include <vector>
#include "../../dev/Dijkstra.cpp"
int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int64_t>> GRAPH(N);
    std::vector<int64_t> costs(M);

    for (int64_t i = 0; i < M; ++i)
    {
        int64_t a, b, x;
        std::cin >> a >> b >> x;
        GRAPH[a].push_back(b);
        costs[b] = x;
    }
    std::vector<int64_t> result = calctaskCost(0ll, GRAPH, costs);
    for (int64_t i = 0; i < result.size(); ++i)
    {
        {
            std::cout << i << " : " << result[i] << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}