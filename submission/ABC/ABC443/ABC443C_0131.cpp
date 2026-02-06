// ABC443C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

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
    int64_t N, T;
    std::cin >> N >> T;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    if (N == 0)
    {
        std::cout << T << std::endl;
        return 0;
    }
    A.push_back(T);
    int64_t time = 0;
    int i = 0;
    int count = 0;
    while (time < T)
    {
        if (A[i] < time)
        {
            ++i;
            continue;
        }
        time += A[i] + 100;
        ++i;
        ++count;
    }
    std::cout << T - (count) * 100 << std::endl;
}