// ABC258C
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
    int64_t N, Q;
    std::cin >> N >> Q;
    std::string S;
    std::cin >> S;
    struct QUERY
    {
        int64_t t;
        int64_t x;
    };
    std::vector<QUERY> queries(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t t, x;
        std::cin >> t >> x;
        // --x;
        queries[i] = QUERY{.t = t, .x = x};
    }
    int64_t head = 0;
    // std::reverse(S.begin(), S.end());
    for (const QUERY &q : queries)
    {
        int64_t t = q.t;
        int64_t x = q.x;
        if (t == 1)
        {
            // head += x;
            // head %= N;
            head -= x;
            if (head < 0)
            {
                head += N;
            }
        }
        else
        {
            std::cout << S[(head + (x - 1)) % N] << std::endl;
        }
    }
}