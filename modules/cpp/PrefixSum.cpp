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