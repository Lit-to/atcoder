// ABC337D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <map>
#include <queue>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 左上から右下までの全探索
 * 縦のみ、横のみについて注目して2回同じ試行を行う [O(2*H*W)]
 * キューを使って入った個数出た個数をカウントする
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 * int64_t result = INF;
 * キュー:queue
 * queueにBOARD[i][0]から順に入れていく
 *  入れるものごとに1つずつカウントする(個数を更新する)
 *  queueの中がK個以上で、xが0個のときの.の数をresultに最小更新する
 *  queueの中がK個以上のとき、先頭を抜いて個数を更新する
 * キュー:queue
 * queueにBOARD[0][i]から順に入れていく
 *  入れるものごとに1つずつカウントする(個数を更新する)
 *  queueの中がK個以上で、xが0個のときの.の数をresultに最小更新する
 *  queueの中がK個以上のとき、先頭を抜いて個数を更新する
 * # 出力
 *
 *
 */

int main()
{
    int64_t H, W, K;
    std::cin >> H >> W >> K;
    char BOARD[H][W];
    for (int64_t i = 0; i < H; ++i)
    {
        for (int64_t j = 0; j < W; ++j)
        {
            std::cin >> BOARD[i][j];
        }
    }
    int64_t result = INT_FAST64_MAX;
    for (int64_t i = 0; i < H; ++i)
    {
        std::map<char, int64_t> count;
        std::queue<char> q;
        for (int64_t j = 0; j < W; ++j)
        {
            q.push(BOARD[i][j]);
            ++count[BOARD[i][j]];
            if (K <= q.size())
            {
                if (count['x'] == 0)
                {
                    result = std::min(result, count['.']);
                }
                --count[q.front()];
                q.pop();
            }
        }
    }
    for (int64_t i = 0; i < W; ++i)
    {
        std::queue<char> q;
        std::map<char, int64_t> count;
        for (int64_t j = 0; j < H; ++j)
        {
            q.push(BOARD[j][i]);
            ++count[BOARD[j][i]];
            if (K <= q.size())
            {
                if (count['x'] == 0)
                {
                    result = std::min(result, count['.']);
                }
                --count[q.front()];
                q.pop();
            }
        }
    }
    if (result == INT_FAST64_MAX)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << result << std::endl;
}