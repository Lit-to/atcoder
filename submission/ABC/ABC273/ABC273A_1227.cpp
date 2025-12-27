// ABC273A
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

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

int f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return f(n - 1) * n;
}

int main()
{

    /*入力エリア*/
    int64_t N;
    std::cin >> N;
    std::cout << f(N) << std::endl;
    /*実装エリア */

    return 0;
}