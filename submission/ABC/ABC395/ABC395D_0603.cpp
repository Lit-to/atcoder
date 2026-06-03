// ABC395D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
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
    UnionFind(int64_t length) : m_groupLeaders(length, ROOT), m_sizeList(length, 1), m_rootCount(length)
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
        m_sizeList[aRoot] += bSize;
        m_sizeList[bRoot] = 0;
        m_groupLeaders[bRoot] = aRoot;
        --m_rootCount;
    }

    /**
     * @brief ノードの属するグループのサイズを求める
     * @param node ノード番号
     */
    int64_t GetGroupSize(const int64_t node)
    {
        return m_sizeList[UpdateRoot(node)];
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
        return m_groupLeaders[node] == ROOT;
    }

    /**
     * @brief ノード同士が同じグループかどうかを求める
     * @param nodeA 調べる対象のノード
     * @param nodeB 調べる対象のノード
     * @return 同じグループかどうか
     */
    bool IsSameRoot(const int64_t nodeA, const int64_t nodeB)
    {
        return FetchRoot(nodeA) == FetchRoot(nodeB);
    }

    /**
     * @brief nodeの根を更新し、根を取得する
     * @param 調べたい対象のノード番号
     */
    int64_t FetchRoot(const int64_t node)
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
        m_groupLeaders[node] = UpdateRoot(m_groupLeaders[node]);
        return m_groupLeaders[node];
    }

    std::vector<int64_t> m_groupLeaders; //! 自分の親ノードが誰かの情報を持つ隣接リストvector
    std::vector<int64_t> m_sizeList;     //! そのグループのサイズを持つvector
    int64_t m_rootCount;                 //! 根の数を持つ値
    static constexpr int ROOT = -1;      //! そのノードが根であることを示す値
};

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, Q;
    cin >> N >> Q;
    struct QUERY
    {
        ll q, a, b;
    };
    vector<QUERY> OP(Q);
    for (ll i = 0; i < Q; ++i)
    {
        cin >> OP[i].q;
        ll a, b;
        if (OP[i].q == 1 || OP[i].q == 2)
        {
            cin >> a >> b;
            --b;
        }
        else
        {
            cin >> a;
            b = -1;
        }
        --a;
        OP[i].a = a;
        OP[i].b = b;
    }
    vector<ll> pegion(N);
    vector<ll> labelPegion(N);
    vector<ll> nest(N);
    for (ll i = 0; i < N; ++i)
    {
        pegion[i] = i;      // 鳩iは巣iにいる
        labelPegion[i] = i; // ラベル鳩iは巣iにいる
        nest[i] = i;        // 巣iには鳩iがいる
    }
    for (ll i = 0; i < Q; ++i)
    {
        ll q = OP[i].q;
        ll a = OP[i].a;
        ll b = OP[i].b;
        if (OP[i].q == 1)
        {
            pegion[a] = labelPegion[b];
        }
        else if (OP[i].q == 2)
        {
            std::swap(labelPegion[a], labelPegion[b]);
            std::swap(nest[labelPegion[a]], nest[labelPegion[b]]);
        }
        else if (OP[i].q == 3)
        {
            cout << nest[pegion[a]] + 1 << endl;
        }
    }
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t TESTCASES = 1;

    // std::cin >> TESTCASES;

    for (int64_t i = 0; i < TESTCASES; ++i)
    {
        solve();
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================