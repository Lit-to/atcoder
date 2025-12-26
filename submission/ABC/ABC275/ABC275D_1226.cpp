// ABC275D
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <cmath>

/**
 *方針メモ欄
 *
 * # お気持ち
 * f(N)をばか正直に書けるけど、TLE不可避
 * →f(N)を求めた結果は配列にしまっておく
 *
 * # 入力
 * 整数N
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 * 計算済みhashMap chache を作る(キー:N,値がf(N))
 *
 * # 具体的なロジック
 * 関数f(value)を定義
 *  value == 0の場合は1を返す
 *  そうでない場合は
 *   cacheのvalue番目がないときは
 *     cache[value] = f(value/2の切り捨て)+f(value/3の切り捨て)
 *   cache[value]を返す
 * 関数f(N)を実行する
 * # 出力
 * cache[N]
 *
 */

std::unordered_map<int64_t, int64_t> cache;

int64_t f(int64_t value)
{
    if (value == 0)
    {
        return 1;
    }
    else
    {
        if (!cache.contains(value))
        {
            int64_t devide_2 = f(std::floor(value / 2));
            int64_t devide_3 = f(std::floor(value / 3));
            cache[value] = devide_2 + devide_3;
        }
        return cache[value];
    }
}

int main()
{

    /*入力エリア*/
    int64_t N;
    std::cin >> N;

    /*実装エリア */
    std::cout << f(N) << std::endl;

    return 0;
}