#include <vector>
#include <cstdint>
class UnionFind
{
public:
    /**
     * unionFindのコンストラクタ
     * 初期化を行う
     * @param length 長さ
     */
    UnionFind(int64_t length)
    {
        m_parent.assign(length, -1);
        m_size.assign(length, 1);
    }
    /**
     * unite関数
     * nodeAにnodeBを結合する
     * @param nodeA 結合されるノード番号
     * @param nodeB 結合するノード番号
     */
    void unite(int64_t nodeA, int64_t nodeB)
    {
        int64_t aRoot = root(nodeA);
        int64_t bRoot = root(nodeB);
        if (aRoot == bRoot)
        {
            return;
        }
        int64_t aSize = fetchSize(aRoot);
        int64_t bSize = fetchSize(bRoot);
        if (aSize < bSize)
        {
            std::swap(aRoot, bRoot);
            std::swap(aSize, bSize);
        }
        m_size[aRoot] += bSize;
        m_parent[bRoot] = aRoot;
    }
    /**
     * fetchSize関数
     * ノードの属するグループのサイズを突き止める
     */
    int64_t fetchSize(int64_t node)
    {
        return m_size[root(node)];
    }

    /**
     * root関数
     * nodeの根を突き止める
     * また、根に至るまでの経路をすべて根の子とする
     * @param node ノード番号
     */
    int64_t root(int64_t node)
    {
        if (m_parent[node] == -1)
        {
            return node;
        }
        m_parent[node] = root(m_parent[node]);
        return m_parent[node];
    }

private:
    std::vector<int64_t> m_size;   //! 子のサイズを持つvector
    std::vector<int64_t> m_parent; //! 自分の親の情報を持つvector
};
