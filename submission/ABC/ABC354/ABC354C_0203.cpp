// ABC354C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 * カードをコストが安い順に並べる
 * 理想では、強さが弱い順に並ぶことなので、前のカードより弱いカードが来たら捨てるということを繰り返す
 *
 * # 具体的なロジック
 * 入力を受け取る
 * 構造体として、強さとコストとインデックスを持つ
 * コストを優先にソートする
 * 同一のコストは強さが弱い順になるようにする
 * コストが安い順順に前から見る
 * 現在のコストの最大値と強さの最大値を持つ
 * 弱い現在の強さの最大値より弱いカードが来たら捨てる
 * それ以外のカードのみ拾う
 *
 */

int main()
{
    int64_t N;
    std::cin >> N;
    struct item
    {
        int64_t m_strength;
        int64_t m_cost;
        int64_t m_index;
        bool operator<(const item &rhs) const
        {
            return m_cost < rhs.m_cost || m_cost == rhs.m_cost && m_strength < rhs.m_strength;
        };
    };
    std::vector<item> ITEMS(N);
    for (int64_t i = 0; i < N; ++i)
    {
        ITEMS[i].m_index = i;
        int64_t a, b;
        std::cin >> ITEMS[i].m_strength >> ITEMS[i].m_cost;
    }
    std::sort(ITEMS.begin(), ITEMS.end());
    int64_t lastStrength;
    std::vector<int64_t> result(0);
    for (int64_t i = 0; i < N; ++i)
    {
        if (ITEMS[i].m_strength < lastStrength)
        {
            continue;
        }
        result.push_back(ITEMS[i].m_index);
        lastStrength = ITEMS[i].m_strength;
    }
    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for (int64_t i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] + 1 << " ";
    }
    std::cout << std::endl;
}