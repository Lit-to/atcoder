// ABC278C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stack>

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
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct QUERY
    {
        int64_t q;
        int64_t x;
        int64_t i;
    };
    int64_t Q;
    std::cin >> Q;
    std::vector<QUERY> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        int q = 0;
        std::cin >> q;
        if (q == 1)
        {
            QUERIES[i].q = q;
            QUERIES[i].i = -1;
            std::cin >> QUERIES[i].x;
        }
        else if (q == 2)
        {
            QUERIES[i].q = q;
            std::cin >> QUERIES[i].i;
            std::cin >> QUERIES[i].x;
            --QUERIES[i].i;
        }
        else
        {
            QUERIES[i].q = q;
            std::cin >> QUERIES[i].i;
            --QUERIES[i].i;
            QUERIES[i].x = -1;
        }
    }
    int64_t base = 0;
    int64_t last = -2;
    struct NUMS
    {
        int64_t index;
        int64_t number;
    };
    std::vector<std::stack<NUMS>> numBox(N);
    for (int i = 0; i < N; ++i)
    {
        numBox[i].push(NUMS{.index = -1, .number = A[i]});
    }
    for (int i = 0; i < Q; ++i)
    {
        if (QUERIES[i].q == 1)
        {
            base = QUERIES[i].x;
            last = i;
        }
        else if (QUERIES[i].q == 2)
        {
            int q_index = QUERIES[i].i;
            if (last < numBox[q_index].top().index)
            {
                numBox[q_index].top().index = i;
                numBox[q_index].top().number += QUERIES[i].x;
            }
            else
            {
                numBox[q_index].push(NUMS{.index = i, .number = QUERIES[i].x});
            }
        }
        else
        {
            int q_index = QUERIES[i].i;
            if (last < numBox[q_index].top().index)
            {
                std::cout << numBox[q_index].top().number + base << std::endl;
            }
            else
            {
                std::cout << base << std::endl;
            }
        }
    }
}