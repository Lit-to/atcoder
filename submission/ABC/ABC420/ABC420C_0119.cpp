// ABC420C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

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
    int64_t N, Q;
    std::cin >> N >> Q;
    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> B[i];
    }
    struct CXV
    {
        char Ci;
        int64_t Xi;
        int64_t Vi;
    };

    std::vector<CXV> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t X, V;
        char C;
        std::cin >> C >> X >> V;
        QUERIES[i] = CXV{.Ci = C, .Xi = X - 1, .Vi = V};
    }
    //
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        result += std::min(A[i], B[i]);
    }
    for (int64_t i = 0; i < Q; ++i)
    {
        CXV item = QUERIES[i];
        int64_t oldValueA = A[item.Xi];
        int64_t oldValueB = B[item.Xi];
        if (item.Ci == 'A')
        {
            A[item.Xi] = item.Vi;
        }
        else if (item.Ci == 'B')
        {
            B[item.Xi] = item.Vi;
        }
        result += (std::min(A[item.Xi], B[item.Xi]) - std::min(oldValueA, oldValueB));
        std::cout << result << std::endl;
    }
}