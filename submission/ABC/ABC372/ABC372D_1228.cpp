// ABC372D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 全員が解いたか解いてないかの全列挙をしたい
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 * 1~31まで数えていく
 * L 各値をビットシフトして立っているビットとa~eを対応させて点数を入れる
 * 点数,名前文字列のべくたーを作っておく
 * 点数で優先的にソートする
 * 名前を前から順に出力する
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */

int main()
{

    /*入力エリア
     * std::cin >> N;
     */
    int A, B, C, D, E;
    std::cin >> A >> B >> C >> D >> E;
    const int SCORE_BOARD[] = {A, B, C, D, E};
    const char NAME_BOARD[] = {'A', 'B', 'C', 'D', 'E'};
    /* 実装エリア */
    struct scoreItem
    {
        int score;
        std::vector<char> name;
    };
    std::vector<scoreItem> scores(32);
    for (int i = 0; i < 32; ++i)
    {
        int bit = i;
        for (int j = 0; j < 5; ++j)
        {
            if (bit & 1)
            {
                scores[i].score += SCORE_BOARD[j];
                scores[i].name.push_back(NAME_BOARD[j]);
            }
            bit >>= 1;
        }
    }
    std::sort(scores.begin(), scores.end(), [](const scoreItem &a, const scoreItem &b)
              { return b.score < a.score || (b.score == a.score && a.name < b.name); });
    for (int i = 0; i < scores.size() - 1; ++i)
    {
        for (int j = 0; j < scores[i].name.size(); ++j)
        {
            std::cout << scores[i].name[j];
        }
        // std::cout << " " << scores[i].score << std::endl;
        std::cout << std::endl;
    }
    return 0;
}