// ABC213D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<std::vector<int64_t>> GRAPH(N);
    for (int64_t i = 0; i < N - 1; ++i)
    {
        int64_t a, b;
        std::cin >> a >> b;
        GRAPH[a - 1].push_back(b - 1);
        GRAPH[b - 1].push_back(a - 1);
    }
    for (int64_t i = 0; i < N; ++i)
    {
        std::sort(GRAPH[i].begin(), GRAPH[i].end());
    }
    std::vector<bool> done(N);
    auto dfs = [&](auto &&self, int64_t node) -> void
    {
        std::cout << node + 1 << " ";
        if (done[node])
        {
            return;
        }
        done[node] = true;
        for (int64_t &nextTo : GRAPH[node])
        {
            if (done[nextTo])
            {
                continue;
            }
            self(self, nextTo);
            std::cout << node + 1 << " ";
        }
    };
    dfs(dfs, 0);
    std::cout << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================