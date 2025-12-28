// ABC340C
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 再帰:
 * xを消したときのコストの総和円を返す関数を考える
 *
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 * hashSet note キー:x 値:コスト
 * # 具体的なロジック
 *関数:
 * * note[x]があればそれを返す
 * なければ
 *  note[x] = 関数(x/2 (floor))+ 関数(x/2 (ceil))
 *  note[x]を返す
 *
 * 関数(N)で呼び出して出力
 *
 *
 * # 出力
 *
 *
 */
//
std::unordered_map<int64_t, int64_t> note;
int64_t divide(int64_t x)
{
    if (x == 1)
    {
        return 0;
    }
    if (!note.contains(x))
    {
        note[x] = x + divide(x / 2) + divide((x + 1) / 2);
    }
    return note[x];
}

int main()
{

    /*入力エリア
     * std::cin >> N;
     */
    int64_t N;
    std::cin >> N;
    std::cout << divide(N) << std::endl;

    /* 実装エリア
    * std::cout << " " << std::endl;

    */

    return 0;
}