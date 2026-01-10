// ABC334D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>
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

/**
 * 累積和計算クラス
 */
class PrefixSumManager
{
public:
    /**
     * コンストラクタ
     * 累積和の事前計算を行う
     * @param values 求めたい値配列
     */
    PrefixSumManager(const std::vector<int64_t> &values)
    {
        this->data.push_back(0);
        for (int64_t i = 0; i < values.size(); ++i)
        {
            this->data.push_back(this->data[i] + values[i]);
        }
    };

    /**
     * 与えられたデータの(l,r)までの総和を求める。
     * -  -  半開区間[0,r)の総和-[0,l)の総和の差を返す
     */
    const int64_t GetSum(int64_t leftSection, int64_t rightSection)
    {
        return this->data.at(rightSection) - this->data.at(leftSection);
    };

private:
    std::vector<int64_t> data; //!< 累積和として計算済みのデータ
};

/**
 * 二分探索関数
 * 評価関数evalがtrueになる範囲とfalseになる範囲の境界値を求める
 * @param ok trueになる片極端
 * @param ng falseになる片極端
 * @param eval 評価関数
 */
template <class Func>
int64_t search(int64_t ok, int64_t ng, Func eval)
{
    while (1 < std::abs(ok - ng))
    {
        int64_t mid = (ok + ng) / 2;
        if (eval(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    return ok;
}

int main()
{

    /* 入力エリア */
    int64_t N, Q;
    std::cin >> N >> Q;

    /* 実装エリア */
    std::vector<int64_t> R(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> R[i];
    }
    std::vector<int64_t> QUERIES(Q);
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i];
    }
    std::vector<int64_t> sleighs(R.begin(), R.end());
    std::copy(R.begin(), R.end(), sleighs.begin());
    std::sort(sleighs.begin(), sleighs.end());

    PrefixSumManager prefixSum(sleighs);
    for (int i = 0; i < Q; ++i)
    {
        int64_t result = search(0, N + 1, [&](int64_t x)
                                { return prefixSum.GetSum(0, x) <= QUERIES[i]; });
        std::cout << result << std::endl;
    }
    return 0;
}