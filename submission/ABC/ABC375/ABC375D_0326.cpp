// ABC375D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//

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
    std::string S;
    std::cin >> S;
    int64_t N = S.size();
    std::vector<std::vector<int64_t>> chars(26, std::vector<int64_t>(N));
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (S[j] == i)
            {
                chars[i - 'A'][j] = 1;
            }
        }
    }

    std::vector<PrefixSumManager> psfs;
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        PrefixSumManager t(chars[i - 'A']);
        psfs.push_back(t);
    }
    int64_t s = 0;
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        for (int64_t j = 0; j < N; ++j)
        {
            s += psfs[i - 'A'].GetSum(0, j) * psfs[i - 'A'].GetSum(j + 1, N);
        }
    }
    std::cout << s << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================
