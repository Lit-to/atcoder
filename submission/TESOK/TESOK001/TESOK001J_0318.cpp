// TESOK001J
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
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct QUERY
    {
        int64_t L;
        int64_t R;
    };
    int64_t Q;
    std::cin >> Q;
    std::vector<QUERY> queries(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> queries[i].L;
        std::cin >> queries[i].R;
        --queries[i].L;
    }
    std::vector<int64_t> lrMax(N);
    std::vector<int64_t> rlMax(N);
    lrMax[0] = A[0];
    for (int64_t i = 1; i < N; ++i)
    {
        lrMax[i] = std::max(lrMax[i - 1], A[i]);
    }
    rlMax[N - 1] = A[N - 1];
    for (int64_t i = N - 2; 0 <= i; --i)
    {
        rlMax[i] = std::max(rlMax[i + 1], A[i]);
    }
    for (QUERY &i : queries)
    {
        std::cout << std::max(lrMax[i.L - 1], rlMax[i.R]) << std::endl;
    }
}