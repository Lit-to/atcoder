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
     * @brief 範囲[l,r)のクエリ結果を返す
     * @param l 左端
     * @param r 右端
     */
    int64_t getQuery(int l, int r)
    {
        return calcSection(l, r, 1, 0, m_memorySize >> 1);
    }

    /**
     * @brief 更新クエリ
     * @param pos ノード
     * @param value 更新後の値
     */
    void updateQuery(int pos, int64_t value)
    {

        int node = (m_memorySize >> 1) + pos;
        m_data[node] = value;
        updateValue(node >> 1);
    }

private:
    /**
     * @brief (デバッグ用)木の中身を吐き出す
     */
    void out()
    {
        for (int i = 0; i < m_memorySize; ++i)
        {
            std::cout << m_data[i] << ",";
        }
        std::cout << std::endl;
    }
    /**
     * @brief MSBを取得
     * @param 取得したい値
     */
    int getMSB(int value)
    {
        int n = 1;
        while (n < m_dataSize)
        {
            n <<= 1;
        }
        return n;
    }

private:
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

private:
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

private:
    /**
     * @param node 特定のノードの値を子ノードから更新する
     */
    void updateValue(int node)
    {
        if (node < 1)
        {
            return;
        }
        m_data[node] = m_eval(m_data[node * 2], m_data[node * 2 + 1]);
        if (node == 1)
        {
            return;
        }
        updateValue(node / 2);
    }
    std::vector<int64_t> m_data;                     //<! 木の実態
    int m_memorySize;                                //<! 木が確保しているメモリサイズ
    int m_dataSize;                                  //<! 葉のメモリサイズ
    int64_t m_identityElement;                       //<! 単位元
    std::function<int64_t(int64_t, int64_t)> m_eval; //<! 評価関数
};
