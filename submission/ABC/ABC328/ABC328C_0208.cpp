// ABC328C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

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
int main()
{
    int64_t N, Q;
    std::cin >> N >> Q;
    std::string S;
    std::cin >> S;
    std::vector<int64_t> queries_l(Q);
    std::vector<int64_t> queries_r(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> queries_l[i];
        std::cin >> queries_r[i];
        --queries_l[i];
        --queries_r[i];
    }
    std::vector<int64_t> matchVector;
    for (int64_t i = 0; i < N - 1; ++i)
    {
        matchVector.push_back(S[i] == S[i + 1]);
    }
    matchVector.push_back(0);
    PrefixSumManager ps(matchVector);
    for (int i = 0; i < Q; ++i)
    {
        //
        std::cout << ps.GetSum(queries_l[i], queries_r[i] + 1) - matchVector[queries_r[i]] << std::endl;
    }
}