#include <vector>
#include <iostream>
#include <bit>
#include <functional>
/**
 * @brief セグメント木
 */
class SegmentTree
{
public:
    /**
     * @brief コンストラクタ
     * @param data 初期化配列
     * @param identityElement 単位元
     * @param eval 評価関数
     */
    SegmentTree(std::vector<int64_t> data, int64_t identityElement, std::function<int64_t(int64_t, int64_t)> eval)
    {
        m_dataSize = data.size();
        m_memorySize = getMSB(m_dataSize) << 1;
        m_data.resize(m_memorySize + 1, identityElement);
        m_identityElement = identityElement;
        m_eval = eval;
        int dataBegin = getMSB(m_dataSize);
        for (int64_t i = 0; i < m_dataSize; ++i)
        {
            m_data[dataBegin + i] = data[i];
        }
        build(1);
    }
    /**
     * @brief 木の構築
     * @param 代入するインデックス
     */
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
    /**
     * @brief 再帰でノード区間内を調査する
     * @param l 調べたい区間の左端
     * @param r 調べたい区間の右端
     * @param node 現在調べているノード
     * @param nodeL 現在調べているノードの左端
     * @param nodeR 現在調べているノードの右端
     */
    int64_t calcSection(int l, int r, int node, int nodeL, int nodeR)
    {
        if (r <= nodeL || nodeR <= l)
        {
            return m_identityElement;
        }
        else if (l == nodeL && r == nodeR)
        {
            return m_data[node];
        }
        else if ((m_memorySize >> 1) <= node)
        {
            return m_identityElement;
        }
        else
        {
            int sep = (nodeR + nodeL) / 2;
            int64_t result_l = m_identityElement;
            int64_t result_r = m_identityElement;
            if (!(sep <= l))
            {
                result_l = calcSection(l, std::min(sep, r), node * 2, nodeL, sep);
            }
            if (!(r <= sep))
            {
                result_r = calcSection(std::max(sep, l), r, node * 2 + 1, sep, nodeR);
            }
            return m_eval(result_l, result_r);
        }
    }
    int64_t getQuery(int l, int r)
    {
        return calcSection(l, r, 1, 0, m_memorySize >> 1);
    }

    void updateValue(int pos)
    {
        if (pos < 1)
        {
            return;
        }
        m_data[pos] = m_eval(m_data[pos * 2], m_data[pos * 2 + 1]);
        if (pos == 1)
        {
            return;
        }
        updateValue(pos / 2);
    }
    void updateQuery(int i, int64_t value)
    {

        int pos = (m_memorySize >> 1) + i;
        m_data[pos] = value;
        updateValue(pos >> 1);
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
    int getMSB(int value)
    {
        int n = 1;
        while (n < m_dataSize)
        {
            n <<= 1;
        }
        return n;
    }
    std::vector<int64_t> m_data;
    int m_memorySize;
    int m_dataSize;
    // int m_height;
    int64_t m_identityElement;
    std::function<int64_t(int64_t, int64_t)> m_eval;
};
// int main()
// {
//     std::vector<int64_t> a({36});
//     SegmentTree b(a, -1, [](int64_t numa, int64_t numb)
//                   { return std::max(numa, numb); });
//     b.updateQuery(1, 16);
//     std::cout << b.getQuery(0, 1) << std::endl;
//     b.updateQuery(1, 98);
//     std::cout << b.getQuery(2, 3) << std::endl;
//     b.updateQuery(2, 82);
//     std::cout << b.getQuery(2, 3) << std::endl;
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
