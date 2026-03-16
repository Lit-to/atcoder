// ABC275A
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
    std::vector<int64_t> bridges(N);
    int64_t mx = 0;
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> bridges[i];
    }
    for (int64_t i = 0; i < N; ++i)
    {
        if (mx < bridges[i])
        {
            mx = bridges[i];
            result = i;
        }
    }
    std::cout << result + 1 << std::endl;
}