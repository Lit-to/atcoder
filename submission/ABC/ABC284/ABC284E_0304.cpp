// ABC284E
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
int64_t count;
void dfs(int64_t node, std::vector<std::vector<int64_t>> &GRAPH, std::unordered_set<int64_t> &done)
{
    ++count;
    for (int64_t i = 0; i < GRAPH[node].size(); ++i)
    {
        if (done.contains(GRAPH[node][i]))
        {
            continue;
        }
        if (1000000 <= count)
        {
            std::cout << count << std::endl;
            exit(0);
        }
        done.insert(GRAPH[node][i]);
        dfs(GRAPH[node][i], GRAPH, done);
        done.erase(GRAPH[node][i]);
    }
}

int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int64_t>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v;
        std::cin >> u;
        std::cin >> v;
        GRAPH[v - 1].push_back(u - 1);
        GRAPH[u - 1].push_back(v - 1);
    }
    count = 0;
    // for (int64_t i = 0; i < N; ++i)
    // {
    std::unordered_set<int64_t> done;
    done.insert(0);
    dfs(0, GRAPH, done);
    done.erase(0);
    // }
    std::cout << count << std::endl;
    // }
}