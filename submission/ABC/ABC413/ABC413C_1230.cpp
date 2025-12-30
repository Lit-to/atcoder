// ABC413C
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdint>

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
    int64_t Q;
    std::cin >> Q;
    std::vector<std::vector<int64_t>> QUERIES(Q);
    for (int i = 0; i < Q; ++i)
    {
        int64_t q;
        std::cin >> q;
        if (q == 1)
        {
            int c, x;
            std::cin >> c >> x;
            QUERIES[i].push_back(q);
            QUERIES[i].push_back(c);
            QUERIES[i].push_back(x);
        }
        else
        {
            int k;
            std::cin >> k;
            QUERIES[i].push_back(q);
            QUERIES[i].push_back(k);
        }
    }

    std::deque<std::vector<int64_t>> queue(0);
    for (int i = 0; i < Q; ++i)
    {
        if (QUERIES[i][0] == 1)
        {
            std::vector<int64_t> item(0);
            item.push_back(QUERIES[i][2]);
            item.push_back(QUERIES[i][1]);
            queue.push_back(item);
        }
        else
        {
            int64_t k = QUERIES[i][1];
            int64_t ans = 0;
            while (0 < k)
            {
                std::vector<int64_t> item = queue.front();
                if (item[1] <= k)
                {
                    ans += item[0] * item[1];
                    k -= item[1];
                    queue.pop_front();
                }
                else
                {
                    ans += item[0] * k;
                    item[1] -= k;
                    queue.pop_front();
                    queue.push_front(item);
                    break;
                }
            }
            std::cout << ans << std::endl;
        }
    }
    /* 実装エリア
    * std::cout << " " << std::endl;

    */

    return 0;
}