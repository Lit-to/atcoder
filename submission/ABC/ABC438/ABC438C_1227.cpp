// ABC438C
// template
#include <iostream>
#include <string>
#include <vector>
#include <stack>
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

    /*入力エリア*/
    int64_t N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct item
    {
        int64_t value;
        int64_t count;
    };
    std::stack<item> stack;
    for (int64_t i = 0; i < N; ++i)
    {
        if (!stack.empty() && stack.top().value == A[i])
        {
            item &top = stack.top();
            ++top.count;
            if (top.count == 4)
            {
                stack.pop();
            }
        }
        else
        {
            stack.push(item{.value = A[i], .count = 1});
        }
    }
    int64_t count = 0;
    while (!stack.empty())
    {
        count += stack.top().count;
        stack.pop();
    }
    std::cout << count << std::endl;

    /*実装エリア */

    return 0;
}