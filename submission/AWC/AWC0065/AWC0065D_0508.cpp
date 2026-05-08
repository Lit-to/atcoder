// AWC0065D
// template
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
#include <iostream>
#include <cmath>
#include <limits>

/**
 * @brief りっとーアルゴリズム便利ツール詰め合わせ
 * @details 状態を持たない関数のうち、ひとまとめにするほど規模の大きくないこまごまとした関数を置く
 */
namespace LitAlgorithm
{
    /**
     * 二分探索関数
     * 評価関数evalがtrueになる範囲とfalseになる範囲の境界値を求める
     * @param ok trueになる片極端
     * @param ng falseになる片極端
     * @param eval 評価関数
     */
    template <class Func>
    int64_t Search(int64_t ok, int64_t ng, Func eval)
    {
        while (1 < std::abs(ok - ng))
        {
            int64_t mid = (ok + ng) / 2;
            if (eval(mid))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        return ok;
    }
    /**
     * 値と桁数からビット列を生成する。
     * e.g.,(5,3) -> {true,false,true}
     */
    std::vector<bool> GenerateBit(int64_t value, const int64_t digits)
    {
        std::vector<bool> result(digits);
        for (int64_t i = 0; i < digits; ++i)
        {
            result[digits - i - 1] = (value & 1);
            value >>= 1;
        }
        ++value;
        return result;
    }
    /**
     * @brief 条件がtrueのときにYesと出力する
     * @details if分岐中にYesを吐き出したい
     * @param isYes Yesを吐き出す条件
     * @return isYesの中身
     */
    bool Yes(bool isYes = true)
    {
        if (isYes)
        {
            std::cout << "Yes" << std::endl;
        }
        return isYes;
    }
    /**
     * @brief 条件がtrueのときにNoと出力する
     * @details if分岐中にNoを吐き出したい
     * @param isNo Noを吐き出す条件
     * @return isNoの中身
     */
    bool No(bool isNo = true)
    {
        if (isNo)
        {
            std::cout << "No" << std::endl;
        }
        return isNo;
    }
    /**
     * @brief 条件がtrueのときにYes,そうでないときにNoと出力する
     * @param isYes Yesを吐き出す条件
     * @return isYesの中身
     */
    bool YesNo(bool isYes)
    {
        if (isYes)
        {
            Yes();
        }
        else
        {
            No();
        }
        return isYes;
    }
    /**
     * vectorの中身を前から順に空白区切りで吐き出す
     * @param first 開始イテレータ
     * @param last 終了イテレータ
     */
    template <class T>
    void Output(const T &first, const T &last)
    {
        for (auto it = first; it != last; ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    /**
     * vectorの中身を前から順に空白区切りで吐き出す
     * @param data コンテナ
     */
    template <class T>
    void Output(const T &data)
    {
        Output(data.begin(), data.end());
    }
    template <class T>
    /**
     * vectorの中身を前から順に取り込む
     * @param first 開始イテレータ
     * @param last 終了イテレータ
     */
    void Input(T first, T last)
    {
        for (auto it = first; it != last; ++it)
        {
            std::cin >> *it;
        }
    }
    /**
     * vectorの中身を前から順に取り込む
     * @param data コンテナ
     */
    template <class T>
    void Input(T &data)
    {
        Input(data.begin(), data.end());
    }

}
namespace LitA = LitAlgorithm;

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

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, K, D;
    cin >> N >> K >> D;
    vector<ll> H(N);
    LitA::Input(H);
    SegmentTree<ll> minV(H, INT64_MAX, [&](ll l, ll r)
                         { return std::min(l, r); });
    SegmentTree<ll> maxV(H, INT64_MIN, [&](ll l, ll r)
                         { return std::max(l, r); });
    ll result = 0;
    ll ir = 0;
    for (ll il = 0; il < N; ++il)
    {
        while (ir < N && maxV.getQuery(il, ir + 1) - minV.getQuery(il, ir + 1) <= D)
        {
            ++ir;
        }
        result = max(result, ir - il);
    }

    if (result < K)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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