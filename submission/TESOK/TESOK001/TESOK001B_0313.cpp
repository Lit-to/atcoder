// TESOK001B
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
 * @brief 条件がtrueのときにYesと出力する
 * @details if分岐中にYesを吐き出したい
 * @param isYes Yesを吐き出す条件
 * @return isYesの中身
 */
bool Yes(bool isYes = true)
{
    if (isYes)
    {
        std::cout << "Yes" << std::endl;
    }
    return isYes;
}
/**
 * @brief 条件がtrueのときにNoと出力する
 * @details if分岐中にNoを吐き出したい
 * @param isNo Noを吐き出す条件
 * @return isNoの中身
 */
bool No(bool isNo = true)
{
    if (isNo)
    {
        std::cout << "No" << std::endl;
    }
    return isNo;
}
int main()
{
    int64_t N, X;
    std::cin >> N >> X;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    for (int64_t i = 0; i < N; ++i)
    {
        if (A[i] == X)
        {
            Yes();
            return 0;
        }
    }
    No();
}