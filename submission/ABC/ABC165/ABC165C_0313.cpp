// ABC165C
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
 * @brief xよりyが大きいときのみ更新する
 * @return xよりyのほうが大きいかどうか
 */
int64_t ChangeMax(int64_t &x, int64_t &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    return false;
}
struct QUERY
{
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t d;
};
int64_t N, M;
std::vector<QUERY> QUERIES;
int64_t eval(std::vector<int64_t> &A)
{
    int64_t result = 0;
    for (int64_t i = 0; i < QUERIES.size(); ++i)
    {
        if (QUERIES[i].c + A[N - QUERIES[i].a - 1] == A[N - QUERIES[i].b - 1])
        {
            result += QUERIES[i].d;
        }
    }
    return result;
}
void dfs(int64_t &result, std::vector<int64_t> &A)
{
    ++A[0];
    int i = 0;
    while (A[i] == M + 1)
    {
        ++i;
        if (i == N)
        {
            std::cout << result << std::endl;
            return;
        }
        ++A[i];
    }
    while (0 < i)
    {
        A[i - 1] = A[i];
        --i;
    }
    int64_t value = eval(A);
    // std::cerr << value << " ";
    ChangeMax(result, value);
    return dfs(result, A);
}
int main()
{
    int64_t Q;
    std::cin >> N >> M >> Q;
    QUERIES.resize(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i].a >> QUERIES[i].b >> QUERIES[i].c >> QUERIES[i].d;
        --QUERIES[i].a;
        --QUERIES[i].b;
    }
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        A[i] = 1;
    }
    A[0] = 0;
    int64_t result = 0;
    dfs(result, A);
}