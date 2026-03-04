// ABC277C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
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

int64_t dfs(int64_t floor, std::unordered_map<int64_t, std::vector<int64_t>> &GRAPH, std::unordered_set<int64_t> &done)
{
    int64_t result = floor;
    for (int64_t i = 0; i < GRAPH[floor].size(); ++i)
    {
        int64_t to = GRAPH[floor][i];
        if (done.contains(to))
        {
            continue;
        }
        done.insert(to);
        result = std::max(result, dfs(to, GRAPH, done));
        // done.erase(to);
    }
    return result;
}

int main()
{
    int N;
    std::cin >> N;
    std::unordered_map<int64_t, std::vector<int64_t>> GRAPH;
    for (int i = 0; i < N; ++i)
    {
        int64_t a, b;
        std::cin >> a >> b;
        GRAPH[a - 1].push_back(b - 1);
        GRAPH[b - 1].push_back(a - 1);
    }
    std::unordered_set<int64_t> done;
    std::cout << dfs(0, GRAPH, done) + 1 << std::endl;
}