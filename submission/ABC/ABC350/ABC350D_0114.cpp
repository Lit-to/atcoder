// ABC350D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <unordered_set>

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
        return UpdateRoot(nodeA) == UpdateRoot(nodeB);
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

/**
 *方針メモ欄
 *
 * # お気持ち
 *    どうせU-F
 *    AiとBiをunionする
 *    このときAiの所属するグループのサイズ*Biの所属するグループのサイズを足しこんでいく
 *    すべて足した後が答え
 *
 * # 具体的なロジック
 *
 */
int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    struct edge
    {
        int64_t A;
        int64_t B;
    };
    std::vector<edge> INPUT(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> INPUT[i].A;
        std::cin >> INPUT[i].B;
        --INPUT[i].A;
        --INPUT[i].B;
    }
    UnionFind uf(N);
    for (int64_t i = 0; i < M; ++i)
    {
        uf.Unite(INPUT[i].A, INPUT[i].B);
    }
    std::unordered_set<int64_t> done;
    int64_t result = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        if (done.contains(uf.GetRoot(i)))
        {
            continue;
        }
        int64_t size = uf.GetSize(i);
        result += size * (size - 1) / 2;
        done.insert(uf.GetRoot(i));
    }
    std::cout << result - M << std::endl;
}