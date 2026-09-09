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
     *
     */
    LinkedList(int64_t size, T initValue = T{})
    {
        for (int64_t i = 0; i < size; ++i)
        {
            PushBack(initValue);
        }
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
    void Clear()
    {
        for (auto i = GetBegin(); i != GetEnd(); i = Erase(i))
            ;
    }

public:
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

private:
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