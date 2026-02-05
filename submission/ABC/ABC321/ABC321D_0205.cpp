// ABC321D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
#include <vector>
#include <cstdint>
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
        m_data.push_back(0);
        for (int64_t i = 0; i < values.size(); ++i)
        {
            m_data.push_back(m_data[i] + values[i]);
        }
    };

    /**
     * 与えられたデータの(l,r)までの総和を求める。
     * -  -  半開区間[0,r)の総和-[0,l)の総和の差を返す
     */
    int64_t GetSum(int64_t leftSection, int64_t rightSection) const
    {
        return m_data.at(rightSection) - m_data.at(leftSection);
    };

private:
    std::vector<int64_t> m_data; //!< 累積和として計算済みのデータ
};

#include <cstdint>
#include <cmath>
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
    int64_t N, M, P;
    std::cin >> N >> M >> P;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::vector<int64_t> B(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> B[i];
    }
    std::sort(A.begin(), A.end());
    PrefixSumManager ps = PrefixSumManager(A);
    int64_t result = 0;
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t index = search(-1, N, [&](int64_t x)
                               { return A[x] + B[i] < P; });
        if (index == -1)
        {
            result += P * N;
            continue;
        }
        result += (P * (N - (index + 1))) + ps.GetSum(0, index + 1) + (B[i] * (index + 1));
    }
    std::cout << result << std::endl;
}
