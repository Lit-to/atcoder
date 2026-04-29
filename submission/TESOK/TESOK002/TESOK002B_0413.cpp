// TESOK002B
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
    struct QUERY
    {
        char T;
        int64_t A;
    };
    std::vector<QUERY> QUERIES(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> QUERIES[i].T >> QUERIES[i].A;
    }
    int X = 0;
    for (const QUERY &q : QUERIES)
    {
        if (q.T == '+')
        {
            X += q.A;
        }
        else if (q.T == '-')
        {
            X -= q.A;
        }
        else if (q.T == '*')
        {
            X *= q.A;
        }
        if (X < 0)
        {
            X += 10000;
        }
        X %= 10000;
        std::cout << X << std::endl;
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================