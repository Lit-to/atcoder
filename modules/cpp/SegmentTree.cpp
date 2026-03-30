#include <vector>
#include <iostream>
#include <bit>
#include <functional>
/**
 * @brief セグメント木
 */
template <class T>
class SegmentTree
{
public:
    /**
     * @brief データを渡して初期化するコンストラクタ
     * @param data 初期化配列
     * @param neutral 単位元
     * @param eval 評価関数
     */
    SegmentTree(const std::vector<T> &data, const T &neutral, const std::function<T(T, T)> &eval)
        : m_dataSize(data.size()), m_neutral(neutral), m_eval(eval)
    {
        int dataBegin = getMSB(m_dataSize);
        m_treeSize = dataBegin << 1;
        m_tree.resize(m_treeSize + 1, neutral);
        for (int64_t i = 0; i < m_dataSize; ++i)
        {
            m_tree[dataBegin + i] = data[i];
        }
        build(1);
    }
    /**
     * @brief すべて単位元で初期化するコンストラクタ
     * @param size 初期化配列のサイズ
     * @param neutral 単位元
     * @param eval 評価関数
     */
    SegmentTree(const T &size, const T &neutral, const std::function<T(T, T)> &eval)
        : SegmentTree(std::vector<T>(size, neutral), neutral, eval)
    {
    }

    /**
     * @brief 範囲[l,r)のクエリ結果を返す
     * @param l 左端
     * @param r 右端
     */
    T getQuery(int l, int r) const
    {
        return calcSection(l, r, 1, 0, m_treeSize >> 1);
    }

    /**
     * @brief 更新クエリ
     * @param pos ノード
     * @param value 更新後の値
     */
    void updateQuery(int pos, const T &value)
    {

        int node = (m_treeSize >> 1) + pos;
        m_tree[node] = value;
        updateValue(node >> 1);
    }

private:
    /**
     * @brief (デバッグ用)木の中身を吐き出す
     */
    void out()
    {
        for (int i = 0; i < m_treeSize; ++i)
        {
            std::cout << m_tree[i] << ",";
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
        while (n < value)
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
    T build(const T &index)
    {
        T value = m_neutral;
        if (m_treeSize / 2 <= index)
        {
            return m_tree[index];
        }
        else
        {
            m_tree[index] = m_eval(build(index * 2), build(index * 2 + 1));
            return m_tree[index];
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
    T calcSection(int l, int r, int node, int nodeL, int nodeR) const
    {
        if (r <= nodeL || nodeR <= l)
        {
            return m_neutral;
        }
        else if (l == nodeL && r == nodeR)
        {
            return m_tree[node];
        }
        else if ((m_treeSize >> 1) <= node)
        {
            return m_neutral;
        }
        else
        {
            int sep = (nodeR + nodeL) / 2;
            int64_t result_l = m_neutral;
            int64_t result_r = m_neutral;
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
        m_tree[node] = m_eval(m_tree[node * 2], m_tree[node * 2 + 1]);
        if (node == 1)
        {
            return;
        }
        updateValue(node / 2);
    }
    std::vector<T> m_tree;         //<! 木の実態
    int m_treeSize;                //<! 木が確保しているメモリサイズ
    int m_dataSize;                //<! 葉のメモリサイズ
    T m_neutral;                   //<! 単位元
    std::function<T(T, T)> m_eval; //<! 評価関数
};
