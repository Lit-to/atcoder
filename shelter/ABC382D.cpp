// ABC382D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * スタックに次の値を入れて入れられなくなったら関数から帰る再起を構築したいね
 * 再帰関数を｢その桁にある値を入れたときの次の桁を呼び出す関数｣として作る
 * (N桁目になったら出力する)
 *
 * # 入力
 * N 配列の長さ
 * M 配列の最大値
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 * 間隔(10)
 * スタック
 * 答え配列
 * # 具体的なロジック
 * 関数append(当てはめる桁数番目,値)を作る
 *  スタックの末尾に値を入れる
 *  桁数番目がN-1の場合
 *    スタックの中身をコピーして答え配列の末尾に詰める
 *  桁数番目がN未満の場合
 *    iを1~Mまで回す
 *      nextValue = (値+間隔+i)として持つ
 *      nextValueがM以上なら
 *      break
 *      そうでなければ関数append(次の桁,)として呼びだす
 *  最後にスタックの末尾の値を捨てる
 * 関数append(0,回数)を10*N+N回呼び出す
 * 関数appendを呼び出して答え配列の中身を全部出力する
 */

int SEP = 10;
std::vector<int64_t> stack(0);
int64_t N, M;
std::vector<std::vector<int64_t>> result(0);
void append(int64_t digits, int64_t value)
{
    stack.push_back(value);
    if (digits == N - 1)
    {
        result.push_back(stack);
    }
    else
    {
        int i = 0;
        int nextValue = value + SEP + i;
        while (nextValue <= M)
        {
            append(digits + 1, nextValue);
            i += 1;
            nextValue = value + SEP + i;
        }
    }
    stack.pop_back();
}

int main()
{

    /*入力エリア*/
    std::cin >> N >> M;
    for (int64_t i = 1; i < M; ++i)
    {
        append(0, i);
    }
    std::cout << result.size() << std::endl;
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    /*実装エリア */

    return 0;
}