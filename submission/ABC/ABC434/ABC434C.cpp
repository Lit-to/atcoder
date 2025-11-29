// ABC434C
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdint.h>

int main()
{

    /*入力エリア*/
    int T;
    std::cin >> T;
    for (int testCase = 0; testCase < T; ++testCase)
    {
        int64_t N, H;
        std::cin >> N >> H;
        std::vector<int64_t> T(N);
        std::vector<int64_t> L(N);
        std::vector<int64_t> U(N);

        for (int64_t i = 0; i < N; ++i)
        {
            std::cin >> T[i];
            std::cin >> L[i];
            std::cin >> U[i];
        }
        int64_t currentL = H;
        int64_t currentU = H;
        int64_t now = 0;
        bool isAnswered = false;
        for (int64_t i = 0; i < N; ++i)
        {
            int64_t duration = T[i] - now;
            int64_t moveRangeU = currentU + duration;
            int64_t moveRangeL = currentL - duration;
            if (U[i] < moveRangeL)
            {
                std::cout << "No" << std::endl;
                isAnswered = true;
                break;
            }
            if (moveRangeU < L[i])
            {
                std::cout << "No" << std::endl;
                isAnswered = true;
                break;
            }
            currentL = std::max(moveRangeL, L[i]);
            currentU = std::min(moveRangeU, U[i]);
            now = T[i];
        }
        if (isAnswered)
        {
            continue;
        }
        std::cout << "Yes" << std::endl;
        continue;
    }
    return 0;
}
