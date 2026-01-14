// ABC346D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 010...か101...のどちらからか始まる文字列
 * どこかで11 00
 * 最後に..101か ...010になる文字列を作ってコストを計算したい
 * →先にすべてを010...もしくは101...としたときのコストを累積和として前計算する
 * どの時点で11 もしくは 00としたらコストが最小となるかを前から順に見て求める
 *
 * # 具体的なロジック
 *
 * 実コスト配列costPlanA
 * Sを1文字目から順に見て
 * i%2==0 のときで、0のとき or
 * i%2==1 のときで、1のとき
 * costPlanA[i]をCiにする
 *
 * 実コスト配列costPlanB
 * Sを1文字目から順に見て
 * i%2==0 のときで、1のとき
 * i%2==1 のときで、0のとき or
 * costPlanB[i]をCiにする
 *
 * psCostA<-costPlanAを前から順に累積和にする
 * costPlanBを反転
 * psCostB<-costPlanBを前から順に累積和にする
 * result = MAX
 * 1~N回繰り返す->i
 *   以下の和を計算する
 *   - psCostA[0:0,0:i]累積
 *   - psCostB[0:0,0:N-i]累積
 *   resultを和と最小更新をする
 * resultを出力
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
    const int64_t INF = 1LL << 60;
    int64_t N;
    std::string S;
    std::cin >> N;
    std::cin >> S;
    std::vector<int64_t> C(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> C[i];
    }
    std::vector<int64_t> costPlanA(N);
    std::vector<int64_t> costPlanB(N);
    std::vector<int64_t> costPlanC(N);
    std::vector<int64_t> costPlanD(N);
    for (int64_t i = 0; i < N; ++i)
    {
        if (i % 2 == 0 && S.at(i) == '0')
        {
            costPlanA[i] = C[i];
        }
        else if (i % 2 == 1 && S.at(i) == '1')
        {
            costPlanA[i] = C[i];
        }
    }
    for (int64_t i = 0; i < N; ++i)
    {
        if (i % 2 == 0 && S.at(i) == '1')
        {
            costPlanB[i] = C[i];
        }
        else if (i % 2 == 1 && S.at(i) == '0')
        {
            costPlanB[i] = C[i];
        }
    }
    for (int64_t i = 0; i < N; ++i)
    {
        if (i % 2 == 1 && S.at(i) == '0')
        {
            costPlanD[i] = C[i];
        }
        else if (i % 2 == 1 && S.at(i) == '0')
        {
            costPlanD[i] = C[i];
        }
    }
    PrefixSumManager psCostA = PrefixSumManager(costPlanA);
    std::reverse(costPlanB.begin(), costPlanB.end());
    PrefixSumManager psCostB = PrefixSumManager(costPlanB);
    int64_t result = INF;
    for (int64_t i = 1; i < N; ++i)
    {
        int64_t temp = psCostA.GetSum(0, i) + psCostB.GetSum(0, N - i);
        result = std::min(result, temp);
    }
    std::reverse(costPlanB.begin(), costPlanB.end());
    std::reverse(costPlanA.begin(), costPlanA.end());
    PrefixSumManager psCostC = PrefixSumManager(costPlanB);
    PrefixSumManager psCostD = PrefixSumManager(costPlanA);
    for (int64_t i = 1; i < N; ++i)
    {
        int64_t temp = psCostC.GetSum(0, i) + psCostD.GetSum(0, N - i);
        result = std::min(result, temp);
    }
    std::cout << result << std::endl;
}