#include <iostream>
#include "../cpp/RandomGenerator.cpp"
#include "../cpp/Dijkstra.cpp"

std::vector<int64_t> dfsDijkstra(std::vector<std::vector<Dijkstra::EDGE>> &GRAPH, int64_t start)
{
    std::vector<int64_t> costs(GRAPH.size(), INT64_MAX / 2);
    std::vector<bool> done(GRAPH.size(), false);

    auto dfs = [&](auto &self, int64_t node, int64_t cost) -> void
    {
        if (cost >= costs[node])
        {
            return;
        }
        costs[node] = cost;
        for (int64_t i = 0; i < (int64_t)GRAPH[node].size(); ++i)
        {
            auto &e = GRAPH[node][i];
            if (done[e.to])
            {
                continue;
            }
            done[e.to] = true;
            self(self, e.to, cost + e.cost);
            done[e.to] = false;
        }
    };

    done[start] = true;
    dfs(dfs, start, 0);

    return costs;
}

int main()
{
    // === テストパラメータ === //
    const int64_t N_MAX = 1000;
    const int64_t M_MAX = N_MAX - 1;
    const int64_t C_MAX = 100;
    const int64_t TEST_COUNT = 100;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //
    int64_t test = 0;
    while (test < TEST_COUNT)
    {
        int64_t N = rand.Generate(1, N_MAX);
        int64_t M = rand.Generate(1, M_MAX);
        std::vector<std::vector<Dijkstra::EDGE>> GRAPH(N);
        for (int64_t i = 0; i < M; ++i)
        {
            int64_t u = rand.Generate(0, N);
            int64_t v = rand.Generate(0, N);
            if (u == v)
            {
                continue;
            }
            GRAPH[u].push_back(Dijkstra::EDGE{.to = v, .cost = rand.Generate(0, C_MAX)});
            GRAPH[v].push_back(Dijkstra::EDGE{.to = u, .cost = rand.Generate(0, C_MAX)});
        }
        Dijkstra dij(GRAPH);

        int64_t Q = rand.Generate(1, 100);
        for (int64_t i = 0; i < Q; ++i)
        {
            int64_t startNode = rand.Generate(0, N);
            std::vector<int64_t> dijResult = dij.calcCosts(startNode);
            std::vector<int64_t> dfsResult = dfsDijkstra(GRAPH, startNode);
            for (int64_t j = 0; j < dfsResult.size(); ++j)
            {
                if (dijResult[j] != dfsResult[j])
                {
                    std::cout << "<<<<<<NG" << std::endl;
                    return 0;
                }
            }
        }

        ++test;
    }
    std::cout << "OK!" << std::endl;
}