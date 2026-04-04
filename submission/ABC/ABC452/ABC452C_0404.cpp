// ABC452C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
int main()
{
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> BONES(N, std::vector<int>(2));
    for (int i = 0; i < N; ++i)
    {
        std::cin >> BONES[i][0] >> BONES[i][1];
    }
    int64_t M;
    std::cin >> M;
    std::vector<std::string> S(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> S[i];
    }

    std::vector<std::vector<std::vector<bool>>> isExistChar(10, std::vector<std::vector<bool>>(10, std::vector<bool>(26)));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < (int)(S[i].size()); ++j)
        {
            isExistChar[S[i].size() - 1][j][S[i][j] - 'a'] = true;
        }
    }
    for (int64_t i = 0; i < M; ++i)
    {
        std::string nowS = S[i];
        if (nowS.size() != N)
        {
            std::cout << "No" << std::endl;
            continue;
        }
        for (int j = 0; j < N; ++j)
        {
            int a = BONES[j][0];
            int b = BONES[j][1];
            if (isExistChar[a - 1][b - 1][nowS[j] - 'a'])
            {
                if (j == N - 1)
                {
                    std::cout << "Yes" << std::endl;
                    break;
                }
                continue;
            }
            std::cout << "No" << std::endl;
            break;
        }
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================