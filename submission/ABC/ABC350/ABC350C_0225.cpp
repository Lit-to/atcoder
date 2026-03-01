// ABC350C
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

int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        --A[i];
        // std::cerr << A[i];
    }
    int count = 0;
    struct token
    {
        int i;
        int j;
    };
    std::vector<token> results;
    for (int i = 0; i < N; ++i)
    {
        int index = i;
        while (A[index] != index)
        {
            ++count;
            results.push_back(token{.i = std::min(index, A[index]), .j = std::max(index, A[index])});
            std::swap(A[index], A[A[index]]);
            index = A[index];
        }
    }
    std::cout << count << std::endl;
    for (int i = 0; i < count; ++i)
    {
        std::cout << 1 + results[i].i << " " << 1 + results[i].j << std::endl;
    }
}