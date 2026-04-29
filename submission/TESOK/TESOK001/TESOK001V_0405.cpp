// TESOK001V
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
    std::vector<int64_t> A(N - 1);
    for (int64_t i = 0; i < A.size(); ++i)
    {
        std::cin >> A[i];
        --A[i];
    }
    std::vector<int64_t> B(N - 1);
    for (int64_t i = 0; i < B.size(); ++i)
    {
        std::cin >> B[i];
        --B[i];
    }
    std::vector<int64_t> scores(N, INT64_MIN);
    scores[0] = 0;
    const int64_t ROUTE_A_SCORE = 100;
    const int64_t ROUTE_B_SCORE = 150;
    for (int64_t i = 0; i < A.size(); ++i)
    {
        scores[A[i]] = std::max(scores[i] + ROUTE_A_SCORE, scores[A[i]]);
        scores[B[i]] = std::max(scores[i] + ROUTE_B_SCORE, scores[B[i]]);
    }
    std::cout << scores[scores.size() - 1] << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================