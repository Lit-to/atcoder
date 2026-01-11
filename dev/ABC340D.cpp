// ABC340D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <map>

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

    int64_t N;
    std::cin >> N;
    struct EDGE
    {
        int64_t to;
        int64_t cost;
        bool operator<(const EDGE &rhs) const
        {
            return true;
        }
    };
    std::vector<std::vector<EDGE>> GRAPH(N);
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t a, b, x;
        std::cin >> a >> b >> x;
        GRAPH[i].push_back(EDGE{.to = i + 1, .cost = a});
        GRAPH[i].push_back(EDGE{.to = x, .cost = b});
    }

    return 0;
}