#include <vector>
#include <cstdint>

class BitManager
{
public:
    BitManager(int64_t digits)
    {
        m_max = 1 << digits;
        m_digits = digits;
        m_value = 0;
    }
    std::vector<int> next()
    {
        int64_t value = m_value;
        std::vector<int> result(m_digits);
        for (int64_t i = 0; i < m_digits; ++i)
        {
            result[m_digits - i - 1] = (value & 1);
            value >>= 1;
        }
        ++m_value;
        return result;
    }
    bool isFinished()
    {
        return m_max <= m_value;
    }
    int64_t m_max;
    int64_t m_value;
    int64_t m_digits;
};