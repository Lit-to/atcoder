// AWC0050B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
int main()
{
    int64_t N, K;
    std::cin >> N >> K;
    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i] >> B[i];
    }
    struct FRUITS
    {
        int64_t count;
        int64_t duration;
        /**
         * ソート用の比較関数
         */
        bool operator<(const FRUITS &target) const
        {
            return count < target.count;
        }
    };
    std::vector<FRUITS> f;
    for (int64_t i = 0; i < N; ++i)
    {
        if (A[i] < B[i])
        {
            f.push_back(FRUITS{.count = A[i], .duration = 1});
        }
        else
        {
            f.push_back(FRUITS{.count = B[i], .duration = A[i] / B[i]});
            f.push_back(FRUITS{.count = A[i] % B[i], .duration = 1});
        }
    }
    std::sort(f.begin(), f.end());
    int64_t result = 0;
    int64_t day = 0;
    while (!f.empty() && day < K)
    {
        if (K < day + f.back().duration)
        {
            result += f.back().count * (K - day);
            break;
        }
        result += f.back().count * f.back().duration;
        day += f.back().duration;
        f.pop_back();
    }
    std::cout << result << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================