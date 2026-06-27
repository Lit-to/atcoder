// ABC464D
// template
#include <iostream>
#include <string>
#include <vector>

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    std::vector<int64_t> X(N); // ペナルティ
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> X[i];
    }
    std::vector<int64_t> Y(N);
    for (int64_t i = 1; i < N; ++i) // i-1日目からi日目にかけてのうれしさボーナス
    {
        std::cin >> Y[i];
    }
    const int64_t INF = 1e18;
    std::vector<std::vector<int64_t>> DP(N + 1, std::vector<int64_t>(2, -1 * INF)); // i日目の天気を晴としたときor雨としたときのうれしさの最大値
    //
    DP[0][0] = 0; // 晴
    DP[0][1] = 0; // 雨
    for (int64_t i = 0; i < N; ++i)
    {
        if (S[i] == 'S') // 本当は晴だった
        {
            DP[i + 1][0] = std::max<int64_t>(DP[i + 1][0], DP[i][0]);        // 昨日晴=>晴の遷移
            DP[i + 1][0] = std::max<int64_t>(DP[i + 1][0], DP[i][1] + Y[i]); // 昨日雨=>晴の遷移
            DP[i + 1][1] = std::max<int64_t>(DP[i + 1][1], DP[i][0] - X[i]); // 昨日晴=>雨の遷移
            DP[i + 1][1] = std::max<int64_t>(DP[i + 1][1], DP[i][1] - X[i]); // 昨日雨=>雨の遷移
        }
        else if (S[i] == 'R') // 本当は雨だった
        {
            DP[i + 1][0] = std::max<int64_t>(DP[i + 1][0], DP[i][0] - X[i]);        // 昨日晴=>晴の遷移
            DP[i + 1][0] = std::max<int64_t>(DP[i + 1][0], DP[i][1] + Y[i] - X[i]); // 昨日雨=>晴の遷移
            DP[i + 1][1] = std::max<int64_t>(DP[i + 1][1], DP[i][0]);               // 昨日晴=>雨の遷移
            DP[i + 1][1] = std::max<int64_t>(DP[i + 1][1], DP[i][1]);               // 昨日雨=>雨の遷移
        }
    }

    std::cout << std::max(DP[N][0], DP[N][1]) << std::endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t TESTCASES = 1;

    std::cin >> TESTCASES;

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