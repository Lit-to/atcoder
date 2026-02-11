// ABC336C
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
    int64_t n = N - 1;
    std::vector<int64_t> digits;
    if (N == 1)
    {
        std::cout << 0 << std::endl;
    }
    while (0 < n)
    {
        digits.push_back(n % 5);
        n = n / 5;
    }
    std::reverse(digits.begin(), digits.end());
    for (int64_t i : digits)
    {
        std::cout << i * 2;
    }
    std::cout << std::endl;
}