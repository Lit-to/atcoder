// ABC384D
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 数列の中からsぴったりとなる区間を見つけたい
 *   ->区間の右端と左端を操作してそのような区間を見つけたい
 * # 具体的なロジック
 * Sは数列の1周期ぶんで割ったあまりとして良い -> sとでもしておく
 * 左:0 右:0として置いておく
 * 和を0として持つ
 * 0~Nまで左を回す
 *   数列の対応する位置の値を和から引く
 *   和がs未満の間:
 *     右をすすめながら数列の対応する位置の値を和に足していく
 *   sと和が等しくなったらyesを出してプログラムを終了
 *
 *
 */

int main()
{
    int64_t N, S;
    std::cin >> N >> S;
    std::vector<int64_t> A(N);
    int64_t sum = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        sum += A[i];
    }
    int64_t s = S % sum;
    int64_t right = 0;
    int64_t total = 0;
    int64_t n = 2 * N;
    for (int64_t left = 0; left < n; ++left)
    {
        if (right <= left)
        {
            right = left;
            total = 0;
        }
        while (right < n && total < s)
        {
            total += A[right % N];
            ++right;
        }
        if (s == total)
        {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        if (right == 2 * n && total < s)
        {
            std::cout << "No" << std::endl;
            return 0;
        }
        total -= A[left % N];
    }
    std::cout << "No" << std::endl;
    return 0;
}