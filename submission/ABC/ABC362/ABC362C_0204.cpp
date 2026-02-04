// ABC362C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 貪欲でやりたい
 * 現在までのXの総和を持っておく
 * -1倍したものがLi<=x<Riに存在すればそれを採用
 * なければ両端のうち足した後絶対値が小さい値を採用
 *
 * # 具体的なロジック
 *
 */

int main()
{
    int64_t N;
    std::cin >> N;
    struct sep
    {
        int64_t l;
        int64_t r;
    };
    std::vector<sep> SEP(N);
    int64_t sumL, sumR;
    sumL = 0;
    sumR = 0;

    for (int64_t i = 0; i < N; ++i)

    {
        std::cin >> SEP[i].l;
        sumL += SEP[i].l;
        std::cin >> SEP[i].r;
        sumR += SEP[i].r;
    }
    if (0 < sumL || sumR < 0)
    {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::vector<int64_t> X(N);
    int64_t sumX = 0;
    for (int i = 0; i < N; ++i)
    {
        X[i] = SEP[i].l;
        sumX += X[i];
    }
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t D = std::min(SEP[i].r - SEP[i].l, -1 * sumX);
        X[i] += D;
        sumX += D;
    }
    std::cout << "Yes" << std::endl;
    for (int64_t i = 0; i < N; ++i)
    {
        std::cout << X[i] << " ";
    }
    std::cout << std::endl;
}