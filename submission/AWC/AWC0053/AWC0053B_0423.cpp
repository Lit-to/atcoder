// AWC0053B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>
//

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> X(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> X[i];
    }
    std::sort(X.begin(), X.end());
    int64_t mid = X[N / 2];
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        result += std::abs(mid - X[i]);
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