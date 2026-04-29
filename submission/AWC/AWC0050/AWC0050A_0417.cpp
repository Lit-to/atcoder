// AWC0050A
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
    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    const int64_t MAX = 1000000000ll;
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        A[i] += MAX;
    }
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> B[i];
        B[i] += MAX;
    }
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        result += std::max(A[i], B[i]) - std::min(A[i], B[i]);
    }
    std::cout << result << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================