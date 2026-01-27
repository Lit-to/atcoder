// ABC442B
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
    int64_t Q;
    std::cin >> Q;
    std::vector<int64_t> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i];
    }
    int volume = 0;
    int ZERO = 0;
    int isPaused = 0;
    for (int64_t i = 0; i < Q; ++i)
    {
        if (QUERIES[i] == 1)
        {
            ++volume;
        }
        else if (QUERIES[i] == 2)
        {
            --volume;
            volume = std::max(volume, ZERO);
        }
        else if (QUERIES[i] == 3)
        {
            ++isPaused;
        }
        if (isPaused % 2 == 1 && 3 <= volume)
        {
            std::cout << "Yes";
        }
        else
        {
            std::cout << "No";
        }
        std::cout << std::endl;
    }
}