// ABC352D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 値とインデックスを共に持たせて値でソートする
 * 前から順にK個ずつ見て先頭と末尾のインデックスの差の最小更新で求まるはず
 * # 具体的なロジック
 *
 * 値とインデックスをペアにもった構造体を作る
 * ソートする
 * 前から順にi番目とi+K番目のインデックスの差を最小更新する
 * 結果が答え
 *
 */

int main()
{
    int64_t N, K;
    std::cin >> N >> K;
    std::vector<int64_t> P(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> P[i];
    }
    struct itemSmall
    {
        int64_t m_index;
        int64_t m_value;
        bool operator<(itemSmall &rhs)
        {
            return this->m_value < rhs.m_value;
        }
    };
    struct itemBig
    {
        int64_t m_index;
        int64_t m_value;
        bool operator<(itemBig &rhs)
        {
            return rhs.m_value < this->m_value;
        }
    };
    std::vector<itemSmall> ITEMS(N);
    for (int64_t i = 0; i < N; ++i)
    {
        ITEMS[i] = itemSmall{.m_index = i, .m_value = P[i]};
    }
    std::sort(ITEMS.begin(), ITEMS.end());
    int64_t result = INT16_MAX;
    // for (int64_t i = 0; i < N; ++i)
    // {
    //     std::cerr << ITEMS[i].m_index << " ";
    // }
    // std::cerr << std::endl;
    std::priority_queue<itemSmall> pqSmall;
    std::priority_queue<itemBig> pqBig;
    for (int64_t i = 0; i < N; ++i)
    {
        pqSmall.push(ITEMS[i]);
        pqBig.push(itemBig{.m_index = ITEMS[i].m_index, .m_value = ITEMS[i].m_value});
    }
    std::cout << result << std::endl;
}