// TESOK001G
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stack>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

// ===================
struct person
{
    int64_t time;
    bool isRight;
    /**
     * ソート用の比較関数
     */
    bool operator<(const person &target) const
    {
        return time < target.time || time == target.time && isRight < target.isRight;
    }
};
int main()
{
    int64_t D, N;
    std::cin >> D >> N;
    int64_t n = 2 * N;
    std::vector<person> QUERIES(n);
    for (int64_t i = 0; i < n; i += 2)
    {
        std::cin >> QUERIES[i].time;
        QUERIES[i].isRight = false;
        std::cin >> QUERIES[i + 1].time;
        --QUERIES[i].time;
        QUERIES[i + 1].isRight = true;
    }
    std::sort(QUERIES.begin(), QUERIES.end());
    std::stack<int64_t> stack;
    int64_t q = 0;
    for (int64_t i = 0; i < D; ++i)
    {
        while (q < n && QUERIES[q].time <= i)
        {
            if (QUERIES[q].isRight == false)
            {
                stack.push(QUERIES[q].time);
            }
            else
            {
                stack.pop();
            }
            ++q;
        }
        std::cout << stack.size() << std::endl;
    }
}