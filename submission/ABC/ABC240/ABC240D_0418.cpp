// ABC240D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stack>
//
int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct CONTENTS
    {
        int64_t num;
        int64_t count;
    };
    std::stack<CONTENTS> s;
    s.push(CONTENTS{.num = -1, .count = 0});
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        if (s.top().num == A[i])
        {
            s.top().count += 1;
            ++result;
            if (s.top().count == A[i])
            {
                result -= s.top().count;
                s.pop();
            }
        }
        else
        {
            s.push(CONTENTS{.num = A[i], .count = 1});
            ++result;
        }
        std::cout << result << std::endl;
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================