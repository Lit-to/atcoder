#include <vector>
#include <cstdint>
#include <iostream>
template <class T>
/**
 * 連結リスト
 */
class LinkedList
{
public:
    /**
     * 連結リストイテレータ
     */
    class Iterator
    {
    public:
        /**
         * デフォルトコンストラクタ
         */
        Iterator() : m_pSource(nullptr), m_index(-1)
        {
        }
        /**
         * 位置を指定したコンストラクタ
         * @param pSource ソースとなるべき双方向リスト
         * @param index 位置
         */
        Iterator(LinkedList *pSource, int64_t index) : m_pSource(pSource), m_index(index)
        {
        }
        /**
         * コピーコンストラクタ
         * @param rhs コピー元
         */
        Iterator(const Iterator &rhs) : m_pSource(rhs.m_pSource), m_index(rhs.m_index)
        {
        }
        /**
         * 前置インクリメント演算子
         * ※次の要素に進める
         */
        Iterator &operator++()
        {
            this->m_index = this->m_pSource->m_data[m_index].m_next;
            return *this;
        }
        /**
         * 前置デクリメント演算子
         * ※前の要素に戻す
         */
        Iterator &operator--()
        {
            this->m_index = this->m_pSource->m_data[m_index].m_prev;
            return *this;
        }
        /**
         * 後置インクリメント演算子
         * ※次の要素に進める
         */
        Iterator operator++(int)
        {
            auto temp = *this;
            this->operator++();
            return temp;
        }
        /**
         * 後置デクリメント演算子
         * ※前の要素に戻す
         */
        Iterator operator--(int)
        {
            auto temp = *this;
            this->operator--();
            return temp;
        }
        /**
         * 等価演算子
         * 同じリストの同じ位置を指しているときにtrueを返す
         * @param rhs 比較先
         */
        bool operator==(const Iterator &rhs) const
        {
            return this->m_pSource == rhs.m_pSource && m_index == rhs.m_index;
        }
        /**
         * 等価演算子
         * 同じソースの同じ位置を指しているとき以外にtrueを返す
         * @param rhs 比較先
         */
        bool operator!=(const Iterator &rhs) const
        {
            return !operator==(rhs);
        }
        /**
         * コピー代入演算子
         * @param rhs 代入元
         */
        Iterator &operator=(const Iterator &rhs)
        {
            this->m_index = rhs.m_index;
            this->m_pSource = rhs.m_pSource;
            return *this;
        }
        /**
         * ポインタ先取得演算子
         */
        T &operator*()
        {
            return m_pSource->m_data[m_index].m_value;
        }
        /**
         * ポインタ先取得演算子(const)
         */
        const T &operator*() const
        {
            return m_pSource->m_data[m_index].m_value;
        }
        /**
         * アロー演算子
         */
        T *operator->()
        {
            return &operator*();
        }
        /**
         * アロー演算子(const)
         */
        const T *operator->() const
        {
            return &operator*();
        }
        /**
         * 自分自身がソースに紐づいているかどうか
         */
        bool IsValid() const
        {
            return m_pSource != nullptr && 0 <= m_index;
        }

        /**
         * データ上の位置を示すインデックスを返す
         */
        int64_t GetIndex() const
        {
            return m_index;
        }

    private:
        // フィールド
        LinkedList *m_pSource; //!< 元データのポインタ
        int64_t m_index;       //!< インデックスを示す整数
    };

public:
    /**
     * デフォルトコンストラクタ
     */
    LinkedList() : m_sentinel(this, 0), m_gabage(0), m_size(0), m_data()
    {
        m_data.push_back(Node{.m_prev = 0, .m_next = 0, .m_value = T{}});
    }
    /**
     * コンストラクタ
     * @details vectorから変換して作成する
     * @param data 変換元
     */
    LinkedList(const std::vector<T> data) : LinkedList()
    {
        for (auto &i : data)
        {
            PushBack(i);
        }
    }
    /**
     * コンストラクタ
     * @details サイズと初期値を指定したコンストラクタ
     * @param size 連結リストのサイズ
     * @param initValue 初期値
     */
    LinkedList(int64_t size, T initValue = T{}) : LinkedList()
    {
        for (int64_t i = 0; i < size; ++i)
        {
            PushBack(initValue);
        }
    }

public:
    /**
     * 特定位置の手前に挿入
     * @param pos 挿入位置を示すイテレータ
     * @param elem 挿入したい値
     */
    void Insert(const Iterator &pos, const T &elem)
    {
        int64_t newNodeIndex = _Reserve();
        m_data[newNodeIndex] = Node{.m_prev = m_data[pos.GetIndex()].m_prev, .m_next = pos.GetIndex(), .m_value = elem};
        m_data[m_data[pos.GetIndex()].m_prev].m_next = newNodeIndex;
        m_data[pos.GetIndex()].m_prev = newNodeIndex;
        ++m_size;
    }
    /**
     * 特定位置の削除
     * @details 即座にメモリを解放するわけではなく、後から挿入するとき用に空きメモリを確保したままにする
     * @param pos 削除したい位置
     * @return 削除した次の位置を表すイテレータ
     */
    Iterator Erase(Iterator pos)
    {
        if (m_sentinel == pos)
        {
            std::cerr << "範囲外削除" << std::endl;
            std::abort();
        }

        m_data[m_data[pos.GetIndex()].m_prev].m_next = m_data[pos.GetIndex()].m_next;
        m_data[m_data[pos.GetIndex()].m_next].m_prev = m_data[pos.GetIndex()].m_prev;
        m_gabage.push_back(pos.GetIndex());
        --m_size;
        return ++pos;
    }

    /**
     * 末尾に指定の値を挿入する
     * @param value 値
     */
    void PushBack(const T &value)
    {
        // auto pos = GetEnd();
        // --pos;
        Insert(GetEnd(), value);
    }

    /**
     * 末尾の要素を削除する
     */
    void PopBack()
    {
        Erase(--GetEnd());
    }

    /**
     * 先頭に指定の値を挿入する
     * @param value 値
     */
    void PushFront(T &elem)
    {
        Insert(GetBegin(), elem);
    }

    /**
     * 先頭の要素を削除する
     */
    void PopFront()
    {
        Erase(GetBegin());
    }

public:
    /**
     * 先頭の参照を取得
     */
    T &GetFront()
    {
        return *GetBegin();
    }

    /**
     * 先頭の参照を取得(const版)
     */
    T &GetFront() const
    {
        return *GetBegin();
    }

    /**
     * 末尾の参照を取得
     */
    T &GetBack()
    {
        return *(--GetEnd());
    }

    /**
     * 末尾の参照を取得(const版)
     */
    T &GetBack() const
    {
        return *(--GetEnd());
    }

    /**
     * 先頭イテレータの取得
     */
    Iterator GetBegin()
    {
        auto retVal = m_sentinel;
        return ++retVal;
    }

    /**
     * 先頭イテレータの取得(const版)
     */
    const Iterator GetBegin() const
    {
        auto retVal = m_sentinel;
        return ++retVal;
    }

    /**
     * 末尾イテレータの取得
     */
    Iterator GetEnd()
    {
        return m_sentinel;
    }

    /**
     * 末尾イテレータの取得(const版)
     */
    const Iterator GetEnd() const
    {
        return m_sentinel;
    }
    /**
     * リストの要素数を取得
     */
    int64_t GetSize() const
    {
        return m_size;
    }

    /**
     * リストに要素が存在するかどうか
     */
    bool IsEmpty() const
    {
        return m_size == 0;
    }

    /**
     * リストの全ての要素を削除する
     */
    void Clear()
    {
        for (auto i = GetBegin(); i != GetEnd(); i = Erase(i))
        {
        }
    }

public:
    /**
     * 標準メソッド
     * 先頭イテレータの取得
     */
    Iterator begin()
    {
        return GetBegin();
    }

    /**
     * 標準メソッド
     * 先頭イテレータの取得(const版)
     */
    Iterator begin() const
    {
        return GetBegin();
    }

    /**
     * 標準メソッド
     * 末尾イテレータの取得
     */
    Iterator end()
    {
        return GetEnd();
    }

    /**
     * 標準メソッド
     * 末尾イテレータの取得(const版)
     */
    Iterator end() const
    {
        return GetEnd();
    }

private:
    /**
     * 要素の確保
     * @details 既に確保済みの空きメモリがある場合はそこから優先的に利用する
     * @return 確保した位置を示すindex
     */
    int64_t _Reserve()
    {
        if (m_gabage.empty())
        {
            auto retVal = m_data.size();
            m_data.push_back(Node{});
            return retVal;
        }
        else
        {
            int64_t retVal = m_gabage.back();
            m_gabage.pop_back();
            return retVal;
        }
        return -1;
    }

private:
    /**
     * 各要素の値と位置関係を示すデータ
     */
    struct Node
    {
        int64_t m_prev; //!< 一つ前の要素のインデックス
        int64_t m_next; //!< 一つ後の要素のインデックス
        T m_value;      //!< 値
    };

private:
    std::vector<Node> m_data;      //!< データの実体
    std::vector<int64_t> m_gabage; //!< 削除済みの要素
    Iterator m_sentinel;           //!< 末尾の次の要素
    int64_t m_size;                //!< データの要素数

    friend Iterator;
};