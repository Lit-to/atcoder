// ABC352D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <set>

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
    struct item
    {
        int64_t m_index;
        int64_t m_value;
        bool operator<(const item &rhs) const
        {
            return this->m_value < rhs.m_value;
        }
    };
    std::vector<item> ITEMS(N);
    for (int64_t i = 0; i < N; ++i)
    {
        ITEMS[i] = item{.m_index = i, .m_value = P[i]};
    }
    std::sort(ITEMS.begin(), ITEMS.end());
    int64_t result = INT64_MAX;
    std::set<int64_t> set;
    for (int64_t i = 0; i < N; ++i)
    {
        set.insert(ITEMS[i].m_index);
        if (K <= set.size())
        {
            result = std::min(result, *set.rbegin() - *set.begin());
            set.erase(ITEMS[i - K + 1].m_index);
        }
    }
    std::cout << result << std::endl;
}