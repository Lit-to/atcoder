// ABC260C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 関数A :レベルlの赤い宝石1個から得られる青い宝石の数を返す関数を作る
 * 関数B :レベルlの青い宝石1個から得られる青い宝石の数を返す関数を作る
 * 各レベルの計算結果は配列かなんかにしまっておいて、計算済みの時はその結果を流用する
 *
 * # 入力
 * int N レベル
 * int X 赤い宝石>青い宝石にする変換個数
 * int Y 青い宝石>青い宝石にする変換個数
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *  青宝石メモ(10) > -1で初期化
 *
 *
 * # 具体的なロジック
 *
 * 関数A
 *  赤宝石メモ[レベル]にデータがあればそれをそのまま返す
 *  それ以外：
 *      レベルが1だった場合は0個返す
 *      レベルが1より大きい場合は関数A(レベル-1)と関数B(レベル)をX回呼び出す
 *
 * 関数B
 *  青宝石メモ[レベル] にデータあればそれをそのまま返す
 *  それ以外：
 *      レベルが1だった場合は1個返す
 *      レベルが1より大きい場合は関数A(レベル-1)と関数B(レベル-1)をY回呼び出す
 *
 * 関数A(N)を呼ぶ→出力
 *
 *
 * # 出力
 *
 *
 */

std::vector<int64_t> blueJewels(11);
std::vector<int64_t> redJewels(11);
int X, Y;
int64_t countRed(int level);
int64_t countBlue(int level);
int64_t countBlue(int level)
{
    if (blueJewels[level] != -1)
    {
        return blueJewels[level];
    }
    if (level == 1)
    {
        blueJewels[level] = 1;
        return 1;
    }
    else
    {
        int64_t count = 0;
        count += countRed(level - 1);
        for (int i = 0; i < Y; ++i)
        {
            count += countBlue(level - 1);
        }
        blueJewels[level] = count;
        return count;
    }
}
int64_t countRed(int level)
{
    if (redJewels[level] != -1)
    {
        return redJewels[level];
    }
    if (level == 1)
    {
        redJewels[level] = 0;
        return 0;
    }
    else
    {
        int64_t count = 0;
        count += countRed(level - 1);
        for (int i = 0; i < X; ++i)
        {
            count += countBlue(level);
        }
        redJewels[level] = count;
        return count;
    }
}

int main()
{

    /*入力エリア
     * std::cin >> N;
     */
    int N;
    std::cin >> N >> X >> Y;
    for (int i = 0; i < 11; ++i)
    {
        blueJewels[i] = -1;
        redJewels[i] = -1;
    }
    const int64_t result = countRed(N);

    /* 実装エリア
     */
    std::cout << result << std::endl;

    return 0;
}