// template
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

int main()
{

    /*入力エリア*/
    int64_t N;
    std::cin >> N;

    int64_t H;
    int64_t W;
    std::cin >> H >> W;

    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::string S;
    std::cin >> S;

    std::cout << S << std::endl;

    /*実装エリア */

    return 0;
}