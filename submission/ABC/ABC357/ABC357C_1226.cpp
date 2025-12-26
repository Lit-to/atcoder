// ABC357C
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdint>

/**
 * -  入力
 *  -  レベルNを受け取る
 *
 * -  方針
 *   -  再帰
 *   -  レベル 左上のマスの位置を受け取って配列に中身を格納する関数makeCarpet
 *   -  関数makeCarpetの中で関数makeCarpetの引数にレベル-1を渡す
 *
 * -  手順
 * 1 入力受け取る
 * 2 レベル1~Kまでのkについての3^kの値を事前に求めて配列borderに入れておく
 * 3 ボードを全部白で初期化する(3^Nx3^N)
 * 4 関数makeCarpet(レベル,0,0)で呼び出す
 *
 * -  関数makeCarpet
 * -  引数(レベル,左上のy,左上のx)
 * -  レベルが0の場合:
 *   -  ボード[y][x]を黒にする
 * -  そうではない場合:
 *   -  y,xを想定する
 *     -  i,jについて0<=i,j<3それぞれについて計算する
 *     -  (y,x) ← (maxValue[レベル]/3)*i+y,(maxValue[レベル]/3)*j+x
 *     -  makeCarpet(level-1,y,x)を呼ぶ
 *     -  ※i==1,j==1の場合はなにもしない
 * -  ボードを全走査して出力する
 */

int64_t maxValue[10];
std::vector<std::vector<char>> BOARD(0);
void makeCarpet(int64_t level, int64_t y, int64_t x)
{
    if (level == 0)
    {
        BOARD[y][x] = '#';
        return;
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            else
            {
                int posY = (maxValue[level] / 3) * i + y;
                int posX = (maxValue[level] / 3) * j + x;
                makeCarpet(level - 1, posY, posX);
            }
        }
    }
}

int main()
{

    /*入力エリア*/
    int64_t N;
    std::cin >> N;

    /*実装エリア */
    for (int i = 0; i < 7; ++i)
    {
        maxValue[i] = std::pow(3, i);
    }
    for (int i = 0; i < maxValue[N]; ++i)
    {
        std::vector<char> line(0);
        for (int j = 0; j < maxValue[N]; ++j)
        {
            line.push_back('.');
        }
        BOARD.push_back(line);
    }
    makeCarpet(N, 0, 0);
    for (int i = 0; i < maxValue[N]; ++i)
    {
        for (int j = 0; j < maxValue[N]; ++j)
        {
            std::cout << BOARD[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}