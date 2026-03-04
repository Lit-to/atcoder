// ABC279A
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
    std::string S;
    std::cin >> S;
    int N = S.size();
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] == 'w')
        {
            result += 2;
        }
        else if (S[i] == 'v')
        {
            ++result;
        }
    }
    std::cout << result << std::endl;
}