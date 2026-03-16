// ABC304C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stack>
#include <set>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
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
/**
 * @brief 条件がtrueのときにYes,そうでないときにNoと出力する
 * @param isYes Yesを吐き出す条件
 * @return isYesの中身
 */
bool YesNo(bool isYes)
{
    if (isYes)
    {
        Yes();
    }
    else
    {
        No();
    }
    return isYes;
}
/**
 * @brief 座標データ構造体
 */
struct POS
{
    int64_t X; //!< x座標
    int64_t Y; //!< y座標
};
int64_t calcDistance(const POS &from, const POS &to)
{
    return (from.X - to.X) * (from.X - to.X) + (from.Y - to.Y) * (from.Y - to.Y);
}
int main()
{
    int64_t N, D;
    std::cin >> N >> D;
    const int64_t LRUD[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    std::vector<POS> PEOPLE(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> PEOPLE[i].X;
        std::cin >> PEOPLE[i].Y;
    }
    std::stack<int64_t> tasks;
    std::set<int64_t> done;
    tasks.push(0);
    done.insert(0);
    int64_t max_d = D * D;
    std::vector<bool> result(N);
    while (!tasks.empty())
    {
        int64_t index = tasks.top();
        tasks.pop();
        result[index] = true;
        for (int64_t i = 0; i < N; ++i)
        {
            if (done.contains(i))
            {
                continue;
            }
            if (calcDistance(PEOPLE[i], PEOPLE[index]) <= max_d)
            {
                done.insert(i);
                tasks.push(i);
            }
        }
    }
    for (bool i : result)
    {
        YesNo(i);
    }
}