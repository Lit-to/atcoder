// ABC314C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <deque>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/

int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::string S;
    std::cin >> S;
    std::vector<int64_t> C(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> C[i];
        --C[i];
    }
    std::vector<std::deque<char>> queues(M);
    for (int64_t i = 0; i < N; ++i)
    {
        queues[C[i]].push_back(S[i]);
    }
    for (int64_t i = 0; i < M; ++i)
    {
        char c = queues[i].back();
        queues[i].push_front(c);
    }
    std::vector<int64_t> indexes(M);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cout << queues[C[i]][indexes[C[i]]];
        ++indexes[C[i]];
    }
    std::cout << std::endl;
}