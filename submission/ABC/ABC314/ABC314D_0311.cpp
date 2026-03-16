// ABC314D
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

int main()
{
    int64_t N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    int64_t Q;
    std::cin >> Q;
    struct QUERY
    {
        int64_t t;
        int64_t x;
        char c;
    };
    std::vector<QUERY> queries(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> queries[i].t;
        std::cin >> queries[i].x;
        std::cin >> queries[i].c;
    }
    bool isUpper = false;
    int64_t lastUnificated = -1;
    struct CHARACTERS
    {
        char c;
        int64_t insertedTime;
    };
    std::vector<CHARACTERS> ES(N);
    for (int64_t i = 0; i < N; ++i)
    {
        ES[i].c = S[i];
        ES[i].insertedTime = 0;
    }
    for (int64_t i = 0; i < Q; ++i)
    {
        if (queries[i].t == 1)
        {
            ES[queries[i].x - 1].c = queries[i].c;
            ES[queries[i].x - 1].insertedTime = i;
        }
        else if (queries[i].t == 2)
        {
            isUpper = false;
            lastUnificated = i;
        }
        else if (queries[i].t == 3)
        {
            isUpper = true;
            lastUnificated = i;
        }
    }
    for (int64_t i = 0; i < N; ++i)
    {
        if (lastUnificated < ES[i].insertedTime)
        {
            std::cout << ES[i].c;
        }
        else
        {
            if (isUpper)
            {
                std::cout << (char)std::toupper(ES[i].c);
            }
            else
            {
                std::cout << (char)std::tolower(ES[i].c);
            }
        }
    }
    std::cout << std::endl;
}