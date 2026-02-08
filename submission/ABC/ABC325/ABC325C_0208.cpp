// ABC325C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_set>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/

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
        return m_parent[node] == ROOT;
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

bool IsInner(int64_t i, int64_t j, int64_t h, int64_t w)
{
    return (0 <= i && i < h) && (0 <= j && j < w);
}
int64_t convertOneDigit(int64_t i, int64_t j, int64_t w)
{
    return i * w + j;
}
const int64_t LRUD[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int main()
{
    int64_t H, W;
    std::cin >> H >> W;
    std::vector<std::string> S(H);
    for (int64_t i = 0; i < H; ++i)
    {
        std::cin >> S[i];
    }
    UnionFind uf(H * W);
    std::vector<int64_t> bombs;
    for (int64_t i = 0; i < H; ++i)
    {
        for (int64_t j = 0; j < W; ++j)
        {
            if (S[i][j] != '#')
            {
                continue;
            }
            bombs.push_back(convertOneDigit(i, j, W));
            for (int k = 0; k < 8; ++k)
            {
                if (!IsInner(i + LRUD[k][0], j + LRUD[k][1], H, W))
                {
                    continue;
                }
                if (S[i + LRUD[k][0]][j + LRUD[k][1]] == '#')
                {
                    uf.Unite(convertOneDigit(i, j, W), convertOneDigit(i + LRUD[k][0], j + LRUD[k][1], W));
                }
            }
        }
    }

    std::unordered_set<int64_t> result;
    for (int64_t i = 0; i < bombs.size(); ++i)
    {
        result.insert(uf.GetRoot(bombs[i]));
    }
    std::cout << result.size() << std::endl;
}