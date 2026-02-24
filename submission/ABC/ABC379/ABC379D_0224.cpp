// ABC379D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>

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
    int64_t Q;
    std::cin >> Q;
    struct query
    {
        int64_t q;
        int64_t value;
    };

    std::vector<query> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i].q;
        if (QUERIES[i].q == 1)
        {
            QUERIES[i].value = -1;
        }
        else
        {
            std::cin >> QUERIES[i].value;
        }
    }
    std::queue<int64_t> plant;
    int64_t day = 0;
    for (int i = 0; i < Q; ++i)
    {
        if (QUERIES[i].q == 1)
        {
            plant.push(day);
        }
        else if (QUERIES[i].q == 2)
        {
            day += QUERIES[i].value;
        }
        else if (QUERIES[i].q == 3)
        {
            int count = 0;
            while (!plant.empty() && plant.front() <= day - QUERIES[i].value)
            {
                plant.pop();
                ++count;
            }
            std::cout << count << std::endl;
        }
    }
}