// ABC441C
// template
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

int main()
{
    int64_t N, K, X;
    std::cin >> N >> K >> X;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    int64_t cups = 0;
    while (K < A.size())
    {
        ++cups;
        A.pop_back();
    }
    int64_t x = 0;
    while (!A.empty() && x < X)
    {
        ++cups;
        x += A.back();
        A.pop_back();
    }
    if (X <= x)
    {
        std::cout << cups << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
}