// ABC325D
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

    /*入力エリア
     * std::cin >> N;
     */
    int N;
    std::cin >> N;
    struct item
    {
        int64_t open;
        int64_t close;
        int64_t index;
    };
    std::vector<item> TD(N);
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t open, close;
        std::cin >> open;
        std::cin >> close;
        close += open;
        TD[i] = item{.open = open, .close = close, .index = i};
    };
    std::sort(TD.begin(), TD.end(), [](const item &lhs, const item &rhs)
              { return (lhs.open < rhs.open || (lhs.open == rhs.open && lhs.close < rhs.close)); });
    std::vector<int64_t> result;
    int64_t last = -1;

    return 0;
}