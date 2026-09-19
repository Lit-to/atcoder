// ABC474C
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
#include <cstdint>
#include <iostream>
template <class T>
class LinkedList
{

public:
    class Iterator
    {
    public:
        // メソッド
        // デフォルトコンストラクタ
        Iterator() : m_pSource(nullptr), m_index(-1)
        {
        }
        Iterator(LinkedList *pSource, int64_t index) : m_pSource(pSource), m_index(index)
        {
        }
        Iterator(const Iterator &rhs) : m_pSource(rhs.m_pSource), m_index(rhs.m_index)
        {
        }
        // ++x
        Iterator &operator++()
        {
            this->m_index = this->m_pSource->m_data[m_index].m_next;
            return *this;
        }
        // --x
        Iterator &operator--()
        {
            this->m_index = this->m_pSource->m_data[m_index].m_prev;
            return *this;
        }
        // x++
        Iterator operator++(int)
        {
            auto temp = *this;
            this->operator++();
            return temp;
        }
        // x--
        Iterator operator--(int)
        {
            auto temp = *this;
            this->operator--();
            return temp;
        }
        // ==
        bool operator==(const Iterator &rhs) const
        {
            return this->m_pSource == rhs.m_pSource && m_index == rhs.m_index;
        }
        // !=
        bool operator!=(const Iterator &rhs) const
        {
            return !operator==(rhs);
        }
        // = コピー代入
        Iterator &operator=(const Iterator &rhs)
        {
            this->m_index = rhs.m_index;
            this->m_pSource = rhs.m_pSource;
            return *this;
        }
        // *演算子
        T &operator*()
        {
            return m_pSource->m_data[m_index].m_value;
        }
        // *演算子
        const T &operator*() const
        {
            return m_pSource->m_data[m_index].m_value;
        }
        // ->演算子
        T *operator->()
        {
            return &operator*();
        }
        // ->演算子
        const T *operator->() const
        {
            return &operator*();
        }
        // 有効かどうか
        bool IsValid() const
        {
            return m_pSource != nullptr && 0 <= m_index;
        }

    public:
        // フィールド
        LinkedList *m_pSource; //!< 元データのポインタ
        int64_t m_index;       //!< インデックスを示す整数
    };

public:
    // コンストラクタ
    LinkedList() : m_sentinel(this, 0), m_gabage(0), m_size(0), m_data()
    {
        m_data.push_back(Node{.m_prev = 0, .m_next = 0, .m_value = T{}});
    }
    LinkedList(const std::vector<T> data) : LinkedList()
    {
        for (auto &i : data)
        {
            PushBack(i);
        }
    }
    LinkedList(int64_t size, T initValue = T{})
    {
        for (int64_t i = 0; i < size; ++i)
        {
            PushBack(initValue);
        }
    }

private:
    int64_t _Reserve()
    {
        if (m_gabage.empty())
        {
            m_data.push_back(Node{});
            return m_data.size() - 1;
        }
        else
        {
            int64_t retVal = m_gabage.back();
            m_gabage.pop_back();
            return retVal;
        }
        return -1;
    }

public:
    // posの前に挿入
    void Insert(const Iterator &pos, const T &elem)
    {
        int64_t newNodeIndex = _Reserve();
        m_data[newNodeIndex] = Node{.m_prev = m_data[pos.m_index].m_prev, .m_next = pos.m_index, .m_value = elem};
        m_data[m_data[pos.m_index].m_prev].m_next = newNodeIndex;
        m_data[pos.m_index].m_prev = newNodeIndex;
        ++m_size;
    }
    // イテレータがさす先の値の削除
    Iterator Erase(Iterator &pos)
    {
        if (m_sentinel == pos)
        {
            std::cerr << "範囲外削除" << std::endl;
            return Iterator();
        }

        m_data[m_data[pos.m_index].m_prev].m_next = m_data[pos.m_index].m_next;
        m_data[m_data[pos.m_index].m_next].m_prev = m_data[pos.m_index].m_prev;
        m_gabage.push_back(pos.m_index);
        --m_size;
        return ++pos;
    }
    void Clear()
    {
        for (auto i = GetBegin(); i != GetEnd(); i = Erase(i))
            ;
    }

    // 先頭イテレータの取得
    T &GetFront()
    {
        return *GetBegin();
    }

    // 末尾の取得
    T &GetBack()
    {
        return *(--GetEnd());
    }

    // 末尾への挿入
    void PushBack(const T &elem)
    {
        Insert(GetEnd(), elem);
    }
    // 末尾からの削除
    void PopBack()
    {
        Erase(--GetEnd());
    }
    // 先頭への挿入
    void PushFront(T &elem)
    {
        Insert(GetBegin(), elem);
    }
    // 先頭からの削除
    void PopFront()
    {
        Erase(GetBegin());
    }

public:
    // 始端の取得 getBegin()
    Iterator GetBegin()
    {
        auto retVal = m_sentinel;
        return ++retVal;
    }
    // 終端の取得 getEnd()
    Iterator GetEnd()
    {
        return m_sentinel;
    }
    // 要素数の取得
    int64_t GetSize()
    {
        return m_size;
    }
    // 空かどうか
    bool IsEmpty()
    {
        return GetSize() != 0;
    }

    // 始端の取得 begin()
    Iterator begin()
    {
        return GetBegin();
    }

    // 終端の取得 end()
    Iterator end()
    {
        return GetEnd();
    }

    struct Node
    {
        int64_t m_prev;
        int64_t m_next;
        T m_value;
    };

private:
    std::vector<Node> m_data;
    std::vector<int64_t> m_gabage;
    Iterator m_sentinel;
    int64_t m_size;
    friend Iterator;
};

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    const auto N = input<ll>();
    const auto Q = input<ll>();
    const auto P = input<ll>(N);
    const auto QUERIES = input<ll>(Q);
    LinkedList<ll> l_list;
    vector<LinkedList<ll>::Iterator> pos(N);
    for (ll i = 0; i < N; ++i)
    {
        ll p = P[i] - 1;
        l_list.PushBack(p);
        pos[p] = --l_list.GetEnd();
    }
    for (auto q : QUERIES)
    {
        --q;
        l_list.Erase(pos[q]);
        l_list.PushBack(q);
        pos[q] = --l_list.GetEnd();
    }
    for (auto i : l_list)
    {
        cout << i + 1 << " ";
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
