// ABC476E
// template
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>

#include <map>
template <class KEY_TYPE, class VALUE_TYPE>
using TreeMap = std::map<KEY_TYPE, VALUE_TYPE>;
#include <unordered_map>
template <class KEY_TYPE, class VALUE_TYPE>
using HashMap = std::unordered_map<KEY_TYPE, VALUE_TYPE>;

#include <set>
template <class VALUE_TYPE>
using TreeSet = std::set<VALUE_TYPE>;
#include <unordered_set>
template <class VALUE_TYPE>
using HashSet = std::unordered_set<VALUE_TYPE>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
T input()
{
    T variable;
    cin >> variable;
    return variable;
}
template <typename T>
std::vector<T> input(int64_t n)
{
    std::vector<T> contents(n);
    for (int64_t i = 0; i < n; ++i)
    {
        contents[i] = input<T>();
    }
    return contents;
}
// 自作ライブラリここから
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

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力スニペ
    // const auto S = input<std::string>();
    //
    const auto N = input<ll>();
    const auto M = input<ll>();
    const auto P = input<ll>(N);
    struct SECTION
    {
        int64_t l; //<! 区間の左端
        int64_t r; //<! 区間の右端
        /**
         * ソート用の比較関数
         */
        bool operator<(const SECTION &target) const
        {
            return l < target.l || l == target.l && r < target.r;
        }
    };
    vector<SECTION> LR(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> LR[i].l >> LR[i].r;
        --LR[i].l;
    }
    vector<ll> bucket(N);
    vector<ll> P_(P);
    for (ll i = 0; i < N; ++i)
    {
        --P_[i];
        bucket[P_[i]] = i;
    }
    SegmentTree<int64_t> mxSeg(P_, -1, [](int64_t u, int64_t v)
                               { return std::max(u, v); });
    SegmentTree<int64_t> mnSeg(P_, 1e6, [](int64_t u, int64_t v)
                               { return std::min(u, v); });
    for (auto &query : LR)
    {
        auto mxVal = mxSeg.getQuery(query.l, query.r);
        auto mnVal = mnSeg.getQuery(query.l, query.r);
        auto mxIndex = bucket[mxVal];
        auto mnIndex = bucket[mnVal];
        mxSeg.updateQuery(mxIndex, mnVal);
        mxSeg.updateQuery(mnIndex, mxVal);
        mnSeg.updateQuery(mxIndex, mnVal);
        mnSeg.updateQuery(mnIndex, mxVal);
        std::swap(bucket[mxVal], bucket[mnVal]);
    }
    vector<ll> p(P_);
    std::sort(all(p), [&](const ll lhs, const ll rhs)
              { return (bucket[lhs] < bucket[rhs]); });
    for (ll i = 0; i < N; ++i)
    {
        cout << p[i] + 1 << " ";
    }
    cout << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t TESTCASES = DEFAULT_TESTCASE;
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

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
