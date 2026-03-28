// ABC451C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
//
int main()
{
    int64_t Q;
    std::cin >> Q;
    struct query
    {
        int64_t q;
        int64_t h;
    };
    std::vector<query> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i].q >> QUERIES[i].h;
    }
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;
    int64_t sum = 0;
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t q, h;
        q = QUERIES[i].q;
        h = QUERIES[i].h;
        if (q == 1)
        {
            pq.push(h);
        }
        else
        {
            while (!pq.empty() && pq.top() <= h)
            {
                pq.pop();
            }
        }
        std::cout << pq.size() << std::endl;
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================