// ABC075C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> GRAPH(N, std::vector<int>());
    std::vector<std::vector<int>> nodes(M, std::vector<int>());

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        nodes[i].push_back(a);
        nodes[i].push_back(b);
        GRAPH[a].push_back(b);
        GRAPH[b].push_back(a);
    }
    std::vector<bool> done(N);

    int antiFrom;
    int antiTo;
    auto dfs = [&](auto &&self, int node) -> void
    {
        done[node] = true;
        for (int j = 0; j < GRAPH[node].size(); ++j)
        {
            if (done[GRAPH[node][j]])
            {
                continue;
            }
            if (antiFrom == node && antiTo == GRAPH[node][j])
            {
                continue;
            }
            if (antiTo == node && antiFrom == GRAPH[node][j])
            {
                continue;
            }
            self(self, GRAPH[node][j]);
        }
    };
    int64_t count = 0;
    for (int i = 0; i < M; ++i)
    {
        antiFrom = nodes[i][0];
        antiTo = nodes[i][1];
        dfs(dfs, 0);
        bool result = true;
        for (int i = 0; i < N; ++i)
        {
            if (done[i] == false)
            {
                result = false;
            }
            done[i] = false;
        }
        count += result;
    }
    std::cout << M - count << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================