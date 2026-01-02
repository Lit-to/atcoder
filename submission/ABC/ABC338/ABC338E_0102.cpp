// ABC338E
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
 * たぶんstack
 *
 *
 * # 入力
 * N int64_t
 * A,B int64_t
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 * スタックを作る
 *
 * # 具体的なロジック
 * 組み合わせのうち、A,BをA<Bものとして初期化する
 * A優先でソートする
 * 全ABを回しながら以下を行う
 *   stackの中がAより大きくなるまでpop
 *   Bを順番にスタックに入れていく
 *
 * Bがスタックの末尾よりも大きかったらYes
 * 小さければ入れていく
 * 最後まで入ればNo
 * # 出力
 *
 *
 */

struct input
{
    int64_t A;
    int64_t B;
    bool operator<(const input target)
    {
        return A < target.A || A == target.A && B < target.B;
    }
};

int main()
{

    /*入力エリア
     * std::cin >> N;
     */
    int64_t N;
    std::cin >> N;
    std::vector<input> LINES(N);
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t a, b;
        std::cin >> a;
        std::cin >> b;
        LINES[i].A = std::min(a, b);
        LINES[i].B = std::max(a, b);
    }

    /* 実装エリア
     */
    std::stack<int64_t> stack;
    std::sort(LINES.begin(), LINES.end());
    bool isOk = false;
    for (int64_t i = 0; i < N; ++i)
    {
        while (!stack.empty() && stack.top() < LINES[i].A)
        {
            stack.pop();
        }
        if (stack.empty())
        {
            stack.push(LINES[i].B);
            continue;
        }
        else
        {
            if (LINES[i].B < stack.top())
            {
                stack.push(LINES[i].B);
            }
            else
            {
                isOk = true;
                break;
            }
        }
    }
    if (isOk)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}