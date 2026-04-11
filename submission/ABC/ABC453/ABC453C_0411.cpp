// ABC453C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
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
    int N;
    std::cin >> N;
    std::vector<int64_t> L(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> L[i];
    }
    int64_t bitNum = 1 << N;
    int64_t result = 0;
    while (-1 < bitNum)
    {
        int64_t takahashi = 0;
        int64_t candidate = 0;
        std::vector<bool> bits = GenerateBit(bitNum, N);
        for (int j = 0; j < N; ++j)
        {
            int64_t t = takahashi;
            if (bits[j])
            {
                takahashi += L[j];
            }
            else
            {
                takahashi -= L[j];
            }
            candidate += ((t < 0 && 0 <= takahashi) || takahashi < 0 && 0 <= t);
        }
        result = std::max(result, candidate);
        --bitNum;
    }
    std::cout << result << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================