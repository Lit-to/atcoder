// ABC204C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <set>
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
std::set<int64_t> done;
int64_t result;
void dfs(int64_t &pos)
{
    done.insert(pos);
    ++result;
    for (int64_t i = 0; i < GRAPH[pos].size(); ++i)
    {
        if (!done.contains(GRAPH[pos][i]))
        {
            dfs(GRAPH[pos][i]);
        }
    }
}
int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    GRAPH.resize(N);
    result = 0;
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t a, b;
        std::cin >> a >> b;
        --a;
        --b;
        GRAPH[a].push_back(b);
    }
    if (M == 0)
    {
        std::cout << N << std::endl;
        return 0;
    }
    for (int64_t i = 0; i < N; ++i)
    {
        dfs(i);
        done.clear();
    }
    std::cout << result << std::endl;
}