// ABC440C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <queue>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */

void solve()
{
    int64_t N, W;
    std::cin >> N >> W;
    std::vector<int64_t> C(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> C[i];
    }
    std::vector<int64_t> group(2 * W);
    for (int64_t i = 0; i < N; ++i)
    {
        group[i % (2 * W)] += C[i];
    }
    std::queue<int64_t> q;
    int64_t result = INT_FAST64_MAX;
    int64_t r = 0;
    for (int64_t i = 0; i < 4 * W; ++i)
    {
        q.push(group[i % (2 * W)]);
        r += group[i % (2 * W)];
        if (W <= q.size())
        {
            result = std::min(r, result);
            r -= q.front();
            q.pop();
        }
    }
    std::cout << result << std::endl;
}
int main()
{
    int64_t T;
    std::cin >> T;
    for (int64_t i = 0; i < T; ++i)
    {
        solve();
    }
}