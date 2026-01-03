// ABC439C
// template
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

    /*入力エリア
     * std::cin >> N;
     */
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct item
    {
        int64_t index;
        int64_t num;
    };
    std::map<int64_t, std::vector<item>> groups;
    for (int64_t i = 0; i < N; ++i)
    {
        if (A[i] % 7 == 0)
        {
            groups[A[i] / 7].push_back(item{.index = i, .num = 7});
        }
        if (A[i] % 5 == 0)
        {
            groups[A[i] / 5].push_back(item{.index = i, .num = 5});
        }
        if (A[i] % 3 == 0)
        {
            groups[A[i] / 3].push_back(item{.index = i, .num = 3});
        }
    }
    struct item_count
    {
        int64_t three = 0;
        int64_t seven = 0;
    };
    int64_t result = 0;
    for (const auto &g : groups)
    {
        const int64_t key = g.first;
        const std::vector<item> items = g.second;
        item_count leftCount;
        item_count rightCount;
        for (int64_t i = 0; i < items.size(); ++i)
        {
            if (items[i].num == 3)
            {
                ++rightCount.three;
            }
            else if (items[i].num == 7)
            {
                ++rightCount.seven;
            }
        }
        for (int64_t i = 0; i < items.size(); ++i)
        {
            if (items[i].num == 3)
            {
                ++leftCount.three;
                --rightCount.three;
            }
            else if (items[i].num == 7)
            {
                ++leftCount.seven;
                --rightCount.seven;
            }
            else
            {
                result += leftCount.three * leftCount.seven;
                result += rightCount.three * rightCount.seven;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}