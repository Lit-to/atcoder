/**
 * 累積和計算クラス
 */
template <class T>
class PrefixSumManager
{
public:
    /**
     * コンストラクタ
     * 累積和の事前計算を行う
     * @param values 求めたい値配列
     */
    PrefixSumManager(std::vector<T> &values)
    {
        data.push_back(0);
        for (int64_t i = 0; i < values.size(); ++i)
        {
            data.push_back(data[i] + values[i]);
        }
    };

    /**
     * 与えられたデータの(l,r)までの総和を求める。
     * -  -  半開区間[0,r)の総和-[0,l)の総和の差を返す
     */
    T getSum(T leftSection, T rightSection)
    {
        return data.at(rightSection) - data.at(leftSection);
    };

private:
    std::vector<T> data;
};