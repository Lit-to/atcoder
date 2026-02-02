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
int64_t calcDigits(int64_t x)
{
    int digits = 0;
    while (0 < x)
    {
        ++digits;
        x /= 10;
    }
    return digits;
}
int main()
{
    std::cout << calcDigits(20);
}