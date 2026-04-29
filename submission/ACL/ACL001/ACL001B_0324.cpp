// ACL001B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <bit>
#include <functional>
/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
class SegmentTree
{
public:
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
        if (r <= valL || valR <= l)
        {
            return m_identityElement;
        }
        else if (l == valL && r == valR)
        {
            return m_data[node];
        }
        else if ((m_memorySize >> 1) <= node)
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
int main()
{
    int64_t N, Q;
    std::cin >> N >> Q;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    SegmentTree segTree(A, 0, [](int64_t a, int64_t b)
                        { return a + b; });
    for (int64_t i = 0; i < Q; ++i)
    {
        int q;
        std::cin >> q;
        if (q == 0)
        {
            int64_t p, x;
            std::cin >> p >> x;
            int64_t ap = segTree.getQuery(p, p + 1);
            segTree.updateQuery(p, x + ap);
        }
        else if (q == 1)
        {
            int64_t l, r;
            std::cin >> l >> r;
            std::cout << segTree.getQuery(l, r) << std::endl;
        }
    }
}