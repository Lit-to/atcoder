// ABC284D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>
//
int main()
{
    int64_t T;
    std::cin >> T;
    const int64_t N_MAX = 30000000ll;
    for (int64_t _ = 0; _ < T; ++_)
    {
        int64_t N;
        std::cin >> N;
        for (int64_t i = 2; i < N_MAX; ++i)
        {
            if (N % i == 0)
            {
                int64_t a = N / i;
                if (a % i == 0)
                {
                    std::cout << i << " " << a / i << std::endl;
                }
                else
                {
                    std::cout << (int64_t)std::sqrt(a) << " " << i << std::endl;
                }
                break;
            }
        }
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================