// ABC311A
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>

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
    std::string S;
    std::cin >> S;
    std::unordered_set<char> done;
    for (int i = 0; i < N; ++i)
    {
        done.insert(S[i]);
        if (done.contains('A') && done.contains('B') && done.contains('C'))
        {
            std::cout << i + 1;
            return 0;
        }
    }
}