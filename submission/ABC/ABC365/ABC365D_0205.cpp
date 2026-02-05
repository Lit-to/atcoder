// ABC365D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * DP
 * 常にグーを出す高橋Rとパーを出す高橋Pとチョキを出す高橋Sを用意する
 * 以下の遷移を行うDPテーブルを作る
 * 1個前の試合の今の試合の手と違う手のうち勝利数が大きいほうを採用する
 *   +今の試合で勝つかどうかを反映させる
 *
 * # 具体的なロジック
 * 入力を受け取る
 * 縦に3横にN+1個の配列を作る(DP)
 * 対応表:{0:R 1:S 2:P}
 * DP[0~2][0]を0とする
 * DP[i][j]をj番目の試合で手iを出したときにそれまでに勝てる最大値として持つ
 * DP[N]の最大の値を答えとして出す
 */

/*=========================*/
char JANKEN_HAND[3] = {'R', 'S', 'P'};
char LOSER_HAND[3][3] = {{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};

bool matchJanken(char me, char you)
{
    if (me == 'R' && you == 'S')
    {
        return true;
    }
    else if (me == 'P' && you == 'R')
    {
        return true;
    }
    else if (me == 'S' && you == 'P')
    {
        return true;
    }
    return false;
}
std::string S;
char getAokiHand(int64_t i)
{
    return S[i - 1];
}
int main()
{
    int64_t N;
    std::cin >> N;
    std::cin >> S;

    std::vector<std::vector<int64_t>> DP(0);
    for (int64_t i = 0; i < 3; ++i)
    {
        std::vector<int64_t> line(N + 1);
        DP.push_back(line);
    }
    for (int64_t j = 1; j < N + 1; ++j)
    {
        for (int64_t i = 0; i < 3; ++i)
        {
            bool jankenResult = matchJanken(getAokiHand(j), JANKEN_HAND[i]);
            if (jankenResult)
            {
                continue;
            }

            DP[i][j] = std::max<int64_t>(DP[i][j], DP[(i + 1) % 3][j - 1] + matchJanken(JANKEN_HAND[i], getAokiHand(j)));
            DP[i][j] = std::max<int64_t>(DP[i][j], DP[(i + 2) % 3][j - 1] + matchJanken(JANKEN_HAND[i], getAokiHand(j)));
        }
    }
    int64_t result = 0;
    for (int64_t i = 0; i < 3; ++i)
    {
        result = std::max<int64_t>(result, DP[i][N]);
    }
    std::cout << result << std::endl;
}