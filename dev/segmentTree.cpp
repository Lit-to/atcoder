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
        m_height = getMSB(m_dataSize);
        m_memorySize = ((m_height + 1) * 2) << 1;
        m_data.resize(m_memorySize, identityElement);
        m_identityElement = identityElement;
        m_eval = eval;
        for (int64_t i = 0; i < m_dataSize; ++i)
        {
            m_data[i + m_memorySize / 2] = data[i];
        }
        build(1);
    }
    int64_t build(int64_t index)
    {
        int64_t value = m_identityElement;
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
    int64_t calcSection(int l, int r, int node, int valL, int valR)
    {
        if (l == valL && r == valR)
        {
            return m_data[node];
        }
        else if ((m_memorySize >> 1) < node)
        {
            return m_identityElement;
        }
        else
        {
            int sep = (valR + valL) / 2;
            int64_t result_l = m_identityElement;
            int64_t result_r = m_identityElement;
            if (!(sep <= l))
            {
                result_l = calcSection(l, std::min(sep, r), node * 2, valL, sep);
            }
            if (!(r <= sep))
            {
                result_r = calcSection(std::max(sep, l), r, node * 2 + 1, sep, valR);
            }
            return m_eval(result_l, result_r);
        }
    }
    int64_t getQuery(int l, int r)
    {
        return calcSection(l, r, 1, 0, m_memorySize >> 1);
    }

    void updateValue(int pos, int value)
    {
        m_data[pos] = value;
        if (pos == 1)
        {
            return;
        }
        if (pos % 2 == 0)
        {
            updateValue(pos / 2, m_eval(m_data[pos], m_data[pos + 1]));
        }
        else
        {
            updateValue(pos / 2, m_eval(m_data[pos], m_data[pos - 1]));
        }
    }
    void updateQuery(int i, int64_t value)
    {
        int pos = (m_memorySize >> 1) + i;
        updateValue(pos, value);
    }
    void out()
    {
        for (int i = 0; i < m_memorySize; ++i)
        {
            std::cout << m_data[i] << ",";
        }
        std::cout << std::endl;
    }
    std::vector<int64_t> debug_getData()
    {
        return m_data;
    }

public:
    static int getMSB(int value)
    {
        return std::bit_width((unsigned int)value);
    }
    std::vector<int64_t> m_data;
    int m_memorySize;
    int m_dataSize;
    int m_height;
    int64_t m_identityElement;
    std::function<int64_t(int64_t, int64_t)> m_eval;
};
// int main()
// {
//     std::vector<int64_t> a({35, 38, 72, 22, 98, 47, 64});
//     SegmentTree b(a, -1, [](int64_t numa, int64_t numb)
//                   { return std::max(numa, numb); });
//     std::cout << b.getQuery(4, 6) << std::endl;
//     // b.updateQuery(3, 100);
//     // b.updateQuery(4, 101);
//     // b.updateQuery(0, 99);
//     // std::cout << b.getQuery(3, 4) << std::endl;

//     for (int i = 0; i < b.m_memorySize; ++i)
//     {
//         std::cout << b.m_data[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }
