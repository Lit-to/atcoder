// ABC342C
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
    std::string S;
    std::cin >> S;
    int64_t Q;
    std::cin >> Q;
    struct query
    {
        char c;
        char d;
    };
    std::vector<query> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i].c >> QUERIES[i].d;
    }
    std::vector<char> mapping(26);
    for (int i = 0; i < 26; ++i)
    {
        mapping[i] = 'a' + i;
    }
    for (int64_t i = 0; i < Q; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (mapping[j] == QUERIES[i].c)
            {
                mapping[j] = QUERIES[i].d;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        std::cout << mapping[S[i] - 'a'];
    }
    std::cout << std::endl;
}