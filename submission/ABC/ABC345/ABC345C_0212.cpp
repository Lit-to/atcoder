// ABC345C
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
/**
 * @brief 組み合わせを計算する
 * @param n 母数
 * @param r 選択数
 * @return nCrの計算結果
 *
 */
int64_t Combination(int64_t n, int64_t r)
{
    int64_t result = 1;
    for (int64_t i = 0; i < r; ++i)
    {
        result *= (n - i);
        result /= i + 1;
    }
    return result;
}
int main()
{
    std::string S;
    std::cin >> S;
    int64_t N = S.size();

    int64_t all = Combination(N, 2);
    std::vector<int64_t> count(26, 0);
    for (int64_t i = 0; i < N; ++i)
    {
        count[S[i] - 'a']++;
    }
    bool isDuplicate = false;
    for (int64_t i = 0; i < 26; ++i)
    {
        if (2 <= count[i])
        {
            isDuplicate = true;
        }
        all -= Combination(count[i], 2);
    }
    std::cout << all + isDuplicate << std::endl;
}