// ABC262C
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

int64_t floor(int64_t x, int64_t m)
{
    int64_t r = (x % m + m) % m;
    return (x - r) / m;
}

int main()
{
    int64_t A, M, L, R;
    std::cin >> A >> M >> L >> R;
    L -= A;
    R -= A;

    std::cout << floor(R, M) - floor(L - 1, M) << std::endl;
}