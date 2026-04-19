// AWC0048C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
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
        return m_data[rightSection] - m_data[leftSection];
    };

private:
    std::vector<int64_t> m_data; //!< 累積和として計算済みのデータ
};
using PSM = PrefixSumManager;
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> H(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> H[i];
    }
    struct damage
    {
        int64_t l;
        int64_t r;
        int64_t d;
    };
    std::vector<damage> LRD(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> LRD[i].l;
        std::cin >> LRD[i].r;
        --LRD[i].l;
        std::cin >> LRD[i].d;
    }
    std::vector<int64_t> damages(N + 1);
    for (int64_t i = 0; i < M; ++i)
    {
        damages[LRD[i].l] -= LRD[i].d;
        damages[LRD[i].r] += LRD[i].d;
    }
    PSM psm(damages);
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        result += (0 < (psm.GetSum(0, i + 1) + H[i]));
    }
    std::cout << result << std::endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    int64_t TESTCASES = 1;

    // std::cin >> TESTCASES;

    for (int64_t i = 0; i < TESTCASES; ++i)
    {
        solve();
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================