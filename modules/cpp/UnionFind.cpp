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
    UnionFind(int64_t length) : m_nodeTree(length, ROOT), m_groupSize(length, 1), m_rootCount(length)
    {
    }

    /**
     * @brief nodeAにnodeBを結合する
     * @param nodeA 結合対象のノード番号
     * @param nodeB 結合対象のノード番号
     */
    void Unite(const int64_t nodeA, const int64_t nodeB)
    {
        int64_t aRoot = UpdateRoot(nodeA);
        int64_t bRoot = UpdateRoot(nodeB);
        if (aRoot == bRoot)
        {
            return;
        }
        int64_t aSize = GetGroupSize(aRoot);
        int64_t bSize = GetGroupSize(bRoot);
        if (aSize < bSize)
        {
            std::swap(aRoot, bRoot);
            std::swap(aSize, bSize);
        }
        m_groupSize[aRoot] += bSize;
        m_groupSize[bRoot] = 0;
        m_nodeTree[bRoot] = aRoot;
        --m_rootCount;
    }

    /**
     * @brief ノードの属するグループのサイズを求める
     * @param node ノード番号
     */
    int64_t GetGroupSize(const int64_t node)
    {
        return m_groupSize[UpdateRoot(node)];
    }
    /**
     * 根の数を数える
     */
    int64_t GetRootCount() const
    {
        return m_rootCount;
    }

    /**
     * @brief ノードが根かどうかを返す
     * @param node ノード番号
     * @return ノードが根かどうか
     */
    bool IsRoot(const int64_t node) const
    {
        return m_nodeTree[node] == ROOT;
    }

    /**
     * @brief ノード同士が同じグループかどうかを求める
     * @param nodeA 調べる対象のノード
     * @param nodeB 調べる対象のノード
     * @return 同じグループかどうか
     */
    bool IsSameRoot(const int64_t nodeA, const int64_t nodeB)
    {
        return GetRoot(nodeA) == GetRoot(nodeB);
    }

    /**
     * @brief nodeの根を更新し、根を取得する
     * @param 調べたい対象のノード番号
     */
    int64_t GetRoot(const int64_t node)
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
    int64_t UpdateRoot(const int64_t node)
    {
        if (IsRoot(node))
        {
            return node;
        }
        m_nodeTree[node] = UpdateRoot(m_nodeTree[node]);
        return m_nodeTree[node];
    }

    std::vector<int64_t> m_nodeTree;  //! 自分の親ノードが誰かの情報を持つ隣接リストvector
    std::vector<int64_t> m_groupSize; //! そのグループのサイズを持つvector
    int64_t m_rootCount;              //! 根の数を持つ値
    static constexpr int ROOT = -1;   //! そのノードが根であることを示す値
};
