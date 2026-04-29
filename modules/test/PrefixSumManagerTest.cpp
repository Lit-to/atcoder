#include <iostream>
#include "../cpp/RandomGenerator.cpp"
#include "../cpp/PrefixSum.cpp"

#include <vector>
#include <cstdint>
/**
 * 愚直_累積和計算クラス
 */
class NonPrefixSumManager
{
public:
    /**
     * コンストラクタ
     * @param values 求めたい値配列
     */
    NonPrefixSumManager(const std::vector<int64_t> &values)
    {
        m_data = values;
    };

    /**
     * 与えられたデータの(l,r)までの総和を求める。
     * -  -  半開区間[0,r)の総和-[0,l)の総和の差を返す
     */
    int64_t GetSum(int64_t leftSection, int64_t rightSection) const
    {
        int64_t result = 0;
        for (int64_t i = leftSection; i < rightSection; ++i)
        {
            result += m_data[i];
        }
        return result;
    };

private:
    std::vector<int64_t> m_data; //!< 累積和として計算済みのデータ
};
using NPSM = NonPrefixSumManager;

int main()
{
    // === テストパラメータ === //
    const int64_t N_MAX = 99999;
    const int64_t V_MAX = 9999999;
    const int64_t V_MIN = -9999999;
    const int64_t TEST_COUNT = 100;
    const int64_t Q_MAX = 999;

    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //
    int64_t test = 0;
    while (test < TEST_COUNT)
    {
        int64_t N = rand.Generate(1, N_MAX);
        std::vector<int64_t> A(N);
        for (int64_t i = 0; i < N; ++i)
        {
            A[i] = rand.Generate(V_MIN, V_MAX);
        }

        PSM ps(A);
        NPSM nps(A);

        int64_t Q = rand.Generate(1, Q_MAX);
        for (int64_t i = 0; i < Q; ++i)
        {
            int64_t l = rand.Generate(1, N - 1);
            int64_t r = rand.Generate(l + 1, N);
            if (ps.GetSum(l, r) != nps.GetSum(l, r))
            {
                std::cout << "<<<<<<NG" << std::endl;
            }
        }
        ++test;
    }
    std::cout << "OK!" << std::endl;
}