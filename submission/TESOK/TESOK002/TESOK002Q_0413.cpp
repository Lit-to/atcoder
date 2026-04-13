// TESOK002Q
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
int main()
{
    int64_t A, B;
    std::cin >> A >> B;
    int64_t a = A;
    int64_t X = 1;
    for (int64_t i = 0; i < B; ++i)
    {
        X *= a;
        X %= 1000000007;
    }
    std::cout << X << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================