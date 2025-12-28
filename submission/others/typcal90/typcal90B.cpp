// typcal90B
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 2^N通りの()の全列挙を目指す
 * 全列挙後、その括弧列が成立してるかどうかをチェックする
 *  L スタックかなんかで確認する
 *
 * # 入力
 * N 長さ
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 * 括弧列チェック関数の定義
 *
 *
 * # 具体的なロジック
 * ・括弧列のチェック関数(文字列)
 *   スタックを用意
 *   スタックに文字列を前から順に詰める
 *   スタックの中身が空でない && 末尾二つを見て()が成立した場合
 *    2個ともpop
 *   最後にスタック空かどうかを返す
 *
 * ・bit全探
 *  答え配列を作る
 *  0~Nまでの全探索
 *   ビットシフトして0になるまで以下pushback
 *      立っているビットを(
 *      立っていないビットを)
 *   できた文字列をチェック関数に投げる
 *   trueなら答え配列に詰める
 *
 *
 *
 *
 * # 出力
 *  答え配列を全部出力
 *
 *
 */

bool checkParenthesis(std::string target)
{
    std::stack<char> stack;
    for (int i = 0; i < target.size(); ++i)
    {
        if (!stack.empty())
        {
            if (stack.top() == '(' && target[i] == ')')
            {
                stack.pop();
                continue;
            }
        }
        stack.push(target[i]);
    }
    return stack.empty();
}

int main()
{

    int64_t N;
    std::cin >> N;
    std::vector<std::string> result;
    int digits = 1;
    for (int i = 0; i < N; ++i)
    {
        digits *= 2;
    }
    for (int i = 0; i < digits; ++i)
    {
        int bit = i;
        std::string parenthesis;
        for (int j = 0; j < N; ++j)
        {
            if (bit & 1)
            {
                parenthesis.push_back('(');
            }
            else
            {
                parenthesis.push_back(')');
            }
            bit >>= 1;
        }
        if (checkParenthesis(parenthesis))
        {
            result.push_back(parenthesis);
        }
    }
    std::sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}