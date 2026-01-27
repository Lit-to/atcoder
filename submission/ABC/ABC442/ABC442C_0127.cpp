// ABC442C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int64_t>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t Ai, Bi;
        std::cin >> Ai >> Bi;
        --Ai;
        --Bi;
        GRAPH[Ai].push_back(Bi);
        GRAPH[Bi].push_back(Ai);
    }
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t candidates = N - (GRAPH[i].size() + 1);
        if (candidates < 3)
        {
            std::cout << 0;
        }
        else
        {
            std::cout << (candidates * (candidates - 1) * (candidates - 2)) / 6;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}