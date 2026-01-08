// ABC334D
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
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */

int main()
{

    /* 入力エリア */
    int64_t N, Q;
    std::cin >> N >> Q;

    /* 実装エリア */
    std::vector<int64_t> R(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> R[i];
    }
    std::vector<int64_t> QUERIES(N);
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i];
    }
    std::vector<int64_t> sleighs(N);
    std::copy(R.begin(), R.end(), sleighs.begin());
    std::sort(sleighs.begin(), sleighs.end());
    for (int i = 0; i < Q; ++i)
    {
        int64_t x = QUERIES[i];
        int64_t count = 0;
        while (0 < x && count < N)
        {
            x -= sleighs[count];
            ++count;
        }
        if (x < 0)
        {
            --count;
        }
        std::cout << count << std::endl;
    }

    return 0;
}