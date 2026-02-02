// ABC353D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * P(x)をxの桁数を表すとしたとき
 * A[i]*i+Σ(K=0=>i-1)(A[k])*P(A[i])
 * をすべてのiについて解けば良い
 * Σの計算に関しては、累積を用いればO(1)になるはず、それ以外の計算はすべてO(1~9)
 * よってO(N)でいけるのでは？
 * # 具体的なロジック
 *
 */
int64_t MOD;

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
            m_data.push_back((m_data[i] + values[i]) % MOD);
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
int64_t calcDigits(int64_t x)
{
    if (x == 0)
    {
        return 1;
    }
    int digits = 1;
    while (0 < x)
    {
        digits *= 10;
        digits %= MOD;
        x /= 10;
    }
    return digits;
}

int main()
{
    MOD = 998244353;
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    PrefixSumManager ps = PrefixSumManager(A);
    int64_t result = 0;
    for (int64_t i = 1; i < N; ++i)
    {
        result += (A[i] * i) % MOD + (ps.GetSum(0, i) * (calcDigits(A[i]) % MOD)) % MOD;
    }
    std::cout << result % MOD << std::endl;
}