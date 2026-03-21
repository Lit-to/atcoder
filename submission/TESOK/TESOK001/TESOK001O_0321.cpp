// TESOK001O
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
struct content
{
    int64_t value;
    int64_t index_1;
    int64_t index_2;
    bool operator<(const content &rhs)
    {
        return this->value < rhs.value || this->value == rhs.value && this->index_1 < rhs.index_1;
    }
};

int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::vector<content> contents(N);
    for (int64_t i = 0; i < N; ++i)
    {
        contents[i].value = A[i];
        contents[i].index_1 = i;
    }
    std::sort(contents.begin(), contents.end());
    int64_t num = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        if (i < N - 1 && contents[i].value == contents[i + 1].value)
        {
            contents[i].index_2 = num;
            continue;
        }
        contents[i].index_2 = num;
        ++num;
    }
    for (int64_t i = 0; i < N; ++i)
    {
        std::swap(contents[i].value, contents[i].index_1);
    }
    std::sort(contents.begin(), contents.end());
    for (int64_t i = 0; i < N; ++i)
    {
        std::cout << contents[i].index_2 + 1 << " ";
    }
    std::cout << std::endl;
}