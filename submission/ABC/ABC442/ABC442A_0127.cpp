// ABC442A
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

int main()
{
    std::string S;
    std::cin >> S;
    int64_t result = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == 'i')
        {
            ++result;
        }
        else if (S[i] == 'j')
        {
            ++result;
        }
    }
    std::cout << result << std::endl;
}