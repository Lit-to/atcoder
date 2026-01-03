// ABC439C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
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
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> pw(0);
    for (int i = 0; i < 3200; ++i)
    {
        pw.push_back(i * i);
    };
    std::unordered_map<int64_t, int64_t> count;
    for (int i = 1; i < 3200; ++i)
    {
        for (int j = i + 1; j < 3200; ++j)
        {
            int64_t n = pw[i] + pw[j];
            if (N < n)
            {
                break;
            }
            ++count[n];
        }
    }
    std::vector<int64_t> result(0);
    for (auto &item : count)
    {
        const int64_t key = item.first;
        const int64_t value = item.second;
        if (value == 1)
        {
            result.push_back(key);
        }
    }

    std::sort(result.begin(), result.end());
    std::cout << result.size() << std::endl;
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}