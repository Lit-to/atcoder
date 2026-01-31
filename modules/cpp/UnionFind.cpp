#include <vector>
#include <cstdint>
/**
 * @class UnionFind
 * @brief UnionFindの木を管理するクラス
 */
class UnionFind
{
public:
    /**
     * @brief unionFindのコンストラクタ
     * 初期化を行う
     * @param length 長さ
     */
    UnionFind(int64_t length) : m_parent(length, ROOT), m_size(length, 1)
    {
    }

    /**
     * @brief nodeAにnodeBを結合する
     * @param nodeA 結合対象のノード番号
     * @param nodeB 結合対象のノード番号
     */
    void Unite(int64_t nodeA, int64_t nodeB)
    {
        int64_t aRoot = UpdateRoot(nodeA);
        int64_t bRoot = UpdateRoot(nodeB);
        if (aRoot == bRoot)
        {
            return;
        }
        int64_t aSize = GetSize(aRoot);
        int64_t bSize = GetSize(bRoot);
        if (aSize < bSize)
        {
            std::swap(aRoot, bRoot);
            std::swap(aSize, bSize);
        }
        m_size[aRoot] += bSize;
        m_size[bRoot] = 0;
        m_parent[bRoot] = aRoot;
    }

    /**
     * @brief ノードの属するグループのサイズを求める
     * @param node ノード番号
     */
    int64_t GetSize(int64_t node)
    {
        return m_size[UpdateRoot(node)];
    }

    /**
     * @brief ノードが根かどうかを返す
     * @param node ノード番号
     * @return ノードが根かどうか
     */
    bool IsRoot(int64_t node)
    {
        return m_parent[node] < 0;
    }

    /**
     * @brief ノード同士が同じグループかどうかを求める
     * @param nodeA 調べる対象のノード
     * @param nodeB 調べる対象のノード
     * @return 同じグループかどうか
     */
    bool IsSameRoot(int64_t nodeA, int64_t nodeB)
    {
        return GetRoot(nodeA) == GetRoot(nodeB);
    }

    /**
     * @brief nodeの根を更新し、根を取得する
     * @param 調べたい対象のノード番号
     */
    int64_t GetRoot(int64_t node)
    {
        return UpdateRoot(node);
    }

private:
    /**
     * @brief nodeの根を更新する
     * また、根に至るまでの経路をすべて根の子とする
     * @param node 更新対象のノード番号
     * @return 根のノード番号
     */
    int64_t UpdateRoot(int64_t node)
    {
        if (IsRoot(node))
        {
            return node;
        }
        m_parent[node] = UpdateRoot(m_parent[node]);
        return m_parent[node];
    }

    std::vector<int64_t> m_size;    //! 子のサイズを持つvector
    std::vector<int64_t> m_parent;  //! 自分の親の情報を持つvector
    static constexpr int ROOT = -1; //! そのノードが親であることを示す値
};
