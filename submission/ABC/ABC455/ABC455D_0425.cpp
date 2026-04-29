// ABC455D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N, Q;
    std::cin >> N >> Q;
    struct QUERY
    {
        int64_t C;
        int64_t P;
    };
    std::vector<QUERY> queries(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> queries[i].C >> queries[i].P;
        --queries[i].C;
        --queries[i].P;
    }
    struct card
    {
        int64_t up;
        int64_t down;
    };
    std::vector<card> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        A[i].up = -1;
        A[i].down = -1;
    }
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t c = queries[i].C;
        int64_t p = queries[i].P;
        if (0 <= A[p].up)
        {
            A[A[p].up].down = -1;
        }
        A[p].up = c;
        if (0 <= A[c].down)
        {
            A[A[c].down].up = -1;
        }
        A[c].down = p;
    }
    std::vector<int64_t> result(N);

    for (int64_t i = 0; i < N; ++i)
    {
        if (A[i].down < 0)
        {
            int64_t deck = i;
            int64_t pos = i;
            while (0 <= pos)
            {
                ++result[deck];
                pos = A[pos].up;
            }
        }
    }
    for (int64_t i = 0; i < N; ++i)
    {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    int64_t TESTCASES = 1;

    // std::cin >> TESTCASES;

    for (int64_t i = 0; i < TESTCASES; ++i)
    {
        solve();
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================