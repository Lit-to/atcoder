// ABC311C
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

std::vector<int64_t> dfs(int64_t pos, const std::vector<int64_t> &GRAPH, std::vector<bool> &done)
{
    std::vector<int64_t> result;
    if (done[GRAPH[pos]])
    {
        std::vector<int64_t> result;
        result.push_back(GRAPH[pos]);
        return result;
    }
    done[GRAPH[pos]] = true;
    result = dfs(GRAPH[pos], GRAPH, done);
    if (result[0] != GRAPH[pos])
    {
        result.push_back(GRAPH[pos]);
        return result;
    }
    std::cout << result.size() << std::endl;
    for (int64_t i = result.size() - 1; 0 <= i; --i)
    {
        std::cout << result[i] + 1 << " ";
    }
    std::cout << std::endl;
    exit(0);
    return result;
}

int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        --A[i];
    }
    std::vector<bool> done(N);
    dfs(0, A, done);
}