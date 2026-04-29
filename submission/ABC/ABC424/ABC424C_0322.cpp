// ABC424C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
std::vector<std::vector<int64_t>> GRAPH;
std::vector<bool> done;
void dfs(int64_t node)
{
    for (int64_t &i : GRAPH[node])
    {
        if (!done[i])
        {
            done[i] = true;
            dfs(i);
        }
    }
}

int main()
{
    int64_t N;
    std::cin >> N;
    GRAPH.resize(N);
    std::vector<int64_t> has;
    done.resize(N);
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t a, b;
        std::cin >> a;
        std::cin >> b;
        if (a == 0 && b == 0)
        {
            has.push_back(i);
            continue;
        }
        GRAPH[a - 1].push_back(i);
        GRAPH[b - 1].push_back(i);
    }
    int64_t pos = 0;
    for (int64_t i = 0; i < has.size(); ++i)
    {
        done[has[i]] = true;
        dfs(has[i]);
    }
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        result += done[i];
    }
    std::cout << result << std::endl;
}