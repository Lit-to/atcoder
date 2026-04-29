// AWC0049C
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
    int64_t N, K;
    std::cin >> N >> K;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    int64_t r = 0;
    int64_t s = 0;
    int64_t result = 0;
    for (int64_t l = 0; l < N; ++l)
    {
        while (r < N && s + A[r] <= K)
        {
            s += A[r];
            ++r;
        }
        if (r <= l)
        {
            r = l + 1;
        }
        else
        {
            result += r - l;
            s -= A[l];
        }
    }
    std::cout << result << std::endl;
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