// ABC449D
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

/*=========================*/

int main()
{
    for (int i = -5; i < 6; ++i)
    {
        for (int j = -5; j < 6; ++j)
        {
            if (std::max(std::abs(i), std::abs(j)) % 2 == 0)
            {
                std::cout << "x";
            }
            else
            {
                std::cout << "o";
            }
        }
        std::cout << std::endl;
    }
}