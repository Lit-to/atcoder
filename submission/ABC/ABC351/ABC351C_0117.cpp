// ABC351C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <stack>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

int main()
{
    std::stack<int64_t> stack;
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    for (int64_t i = 0; i < N; ++i)
    {
        while (!stack.empty() && stack.top() == A[i])
        {
            stack.pop();
            A[i]++;
        }
        stack.push(A[i]);
    }
    std::cout << stack.size() << std::endl;
}