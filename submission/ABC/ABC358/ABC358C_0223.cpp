// ABC358C
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
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> S[i];
    }
    std::vector<int> bitS(N);
    for (int i = 0; i < N; ++i)
    {
        int b = 0;
        for (int j = 0; j < M; ++j)
        {
            b |= (S[i][j] == 'o') << j;
        }
        bitS[i] = b;
    }
    int result = 100;
    int temp = (1 << (M + 1)) - 1;
    for (int i = 0; i < (1 << N); ++i)
    {
        std::vector<bool> bitArray = GenerateBit(i, N);
        int popcorn = 0;
        int count = 0;
        for (int j = 0; j < N; ++j)
        {
            if (bitArray[j])
            {
                count++;
                popcorn |= bitS[j];
            }
        }
        if (popcorn == (1 << M) - 1)
        {
            result = std::min<int64_t>(count, result);
        }
    }
    std::cout << result << std::endl;
}