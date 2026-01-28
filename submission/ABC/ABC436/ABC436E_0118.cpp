// ABC436E
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */
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
     * @brief ノードが親ノードかどうかを返す
     * @param node ノード番号
     * @return ノードが親かどうか
     */
    bool IsRoot(int64_t node)
    {
        return m_parent[node] < 0;
    }

private:
    /**
     * @brief nodeの根を突き止める
     * また、根に至るまでの経路をすべて根の子とする
     * @param node ノード番号
     */
    int64_t UpdateRoot(int64_t node)
    {
        if (m_parent[node] == ROOT)
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

int main()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        --A[i];
    }
    UnionFind uf(N);
    for (int i = 0; i < N; ++i)
    {
        uf.Unite(i, A[i]);
    }
    std::vector<int64_t> count;
    for (int64_t i = 0; i < N; ++i)
    {
        if (uf.IsRoot(i))
        {
            count.push_back(uf.GetSize(i));
        }
    }
    int64_t result = 0;
    for (int64_t i = 0; i < count.size(); ++i)
    {
        result += ((count[i] * (count[i] - 1)) / 2);
    }
    std::cout << result << std::endl;
}