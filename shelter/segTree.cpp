#include <vector>
#include <iostream>
#include <bit>
#include <functional>
class SegmentTree
{
public:
    SegmentTree(std::vector<int64_t> data, int64_t identityElement, std::function<int64_t(int64_t, int64_t)> eval)
    {
        m_dataSize = data.size();
        m_memorySize = ((getMSB(m_dataSize) + 1) * 2) << 1;
        m_data.resize(m_memorySize, identityElement);
        m_eval = eval;
        for (int64_t i = 0; i < m_dataSize; ++i)
        {
            m_data[i + m_memorySize / 2] = data[i];
        }
        build(1);
    }
    int64_t build(int64_t index)
    {
        int64_t value = -1;
        if (m_memorySize / 2 <= index)
        {
            return m_data[index];
        }
        else
        {
            m_data[index] = m_eval(build(index * 2), build(index * 2 + 1));
            return m_data[index];
        }
    }
    int64_t getQuery(int l, int r)
    {
    }

public:
    static int getMSB(int value)
    {
        return std::bit_width((unsigned int)value);
    }
    std::vector<int64_t> m_data;
    int m_memorySize;
    int m_dataSize;
    std::function<int64_t(int64_t, int64_t)> m_eval;
};
int main()
{
    std::vector<int64_t> a({2, 3, 45, 26, 42, 2});
    SegmentTree b(a, -1, [](int64_t numa, int64_t numb)
                  { return std::max(numa, numb); });
    return 0;
}
