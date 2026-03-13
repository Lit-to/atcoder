// TESOK001D
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
/**
 * 値と桁数からビット列を生成する。
 * e.g.,(5,3) -> {true,false,true}
 */
std::vector<bool> GenerateBit(int64_t value, const int64_t digits)
{
    std::vector<bool> result(digits);
    for (int64_t i = 0; i < digits; ++i)
    {
        result[digits - i - 1] = (value & 1);
        value >>= 1;
    }
    ++value;
    return result;
}
int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<bool> result = GenerateBit(N, 10);
    for (int64_t i = 0; i < 10; ++i)
    {
        if (result[i])
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }
    std::cout << std::endl;
}