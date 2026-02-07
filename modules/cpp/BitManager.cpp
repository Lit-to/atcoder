#include <vector>
#include <cstdint>

/**
 * @class
 * @brief ビットマネージャー
 */
class BitManager
{
public:
    /**
     * @brief コンストラクタ
     * @param ビット列桁数
     */
    BitManager(int64_t digits)
    {
        m_max = 1 << digits;
        m_digits = digits;
        m_value = 0;
    }
    /**
     * 次のビット列を取得する
     * @return ビット列
     */
    std::vector<bool> next()
    {
        int64_t value = m_value;
        std::vector<bool> result(m_digits);
        for (int64_t i = 0; i < m_digits; ++i)
        {
            result[m_digits - i - 1] = (value & 1);
            value >>= 1;
        }
        ++m_value;
        return result;
    }
    /**
     * 終了済みかどうかを取得する
     * @return 終了済みかどうか
     */
    bool isFinished()
    {
        return m_max <= m_value;
    }
    int64_t m_max;    //! 桁数最大値
    int64_t m_value;  //! 現在の値
    int64_t m_digits; //! 桁数
};