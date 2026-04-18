// ABC454C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int64_t>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t a, b;
        std::cin >> a >> b;
        --a;
        --b;
        GRAPH[a].push_back(b);
    }
    std::vector<bool> done(N);
    auto dfs = [&](auto &&self, int64_t node) -> void
    {
        if (done[node])
        {
            return;
        }
        done[node] = true;
        for (int64_t i = 0; i < GRAPH[node].size(); ++i)
        {
            if (done[GRAPH[node][i]])
            {
                continue;
            }
            self(self, GRAPH[node][i]);
        }
    };
    dfs(dfs, 0);
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        result += done[i];
    }
    std::cout << result << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================