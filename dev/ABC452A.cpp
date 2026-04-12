// ABC452A
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
    std::string S;
    std::cin >> S;
    int64_t headIndex = 0;
    for (int64_t i = 0; i <= N; ++i)
    {
        if (i == N || S[i] != 'o')
        {
            headIndex = i;
            break;
        }
    }
    for (int64_t i = headIndex; i < N; ++i)
    {
        std::cout << S[i];
    }
    std::cout << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================
