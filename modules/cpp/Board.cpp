#include <stdexcept>
#include <vector>
#include <iostream>

/**
 * 二次元ボード
 */
template <class T>
class Board
{
    /**
     * イテレータ
     */
    class Iterator
    {

        //==コンストラクタ
        /**
         * デフォルトコンストラクタ
         */
        Iterator() : m_data(nullptr), m_r(0), m_c(0)
        {
        }

        /**
         * ボードと位置から作成するコンストラクタ
         */
        Iterator(Board &board, int64_t r, int64_t c) : m_data(&board), m_r(r), m_c(c)
        {
        }

        // コピーコンストラクタ
        Iterator(const Iterator &target) : m_data(target.m_data), m_r(target.m_r), m_c(target.m_c)
        {
        }

        //== 演算子,主要メソッド
        // *演算子(ボードの参照を返す)
        Iterator &operator*()
        {
            return *m_data[m_data->getIndex(m_r, m_c)];
        }

        void move(int64_t r, int64_t c)
        {
            m_r += r;
            m_c += c;
        }

        // 左に1つ移動
        void &moveL()
        {
            --m_r;
        }

        // 右に1つ移動
        void &moveR()
        {
            ++m_r;
        }

        // 上に1つ移動
        void &moveU()
        {
            --m_c;
        }

        // 下に1つ移動
        void &moveD()
        {
            ++m_c;
        }

        // 等価演算子(同じボード、同じ位置かどうか)
        bool operator=(Iterator &rhs)
        {
            return m_data == rhs.m_data && m_r == rhs.m_r && m_c == rhs.m_c;
        }

        // 不等価演算子
        bool operator!=(Iterator &rhs)
        {
            return (!this == rhs);
        }

        // ボードの内側かどうか
        bool isInside() const
        {
            return m_data->isInside(m_r, m_c);
        }

        // ボードの外側かどうか
        bool isOutside() const
        {
            return (!isInside());
        }

        int64_t getIndex() const
        {
            return m_data.getIndex(m_r, m_c);
        }

        //==メンバー変数
        Board *m_data; //<!対応するボード
        int64_t m_r;   //<! 指し示す位置縦方向の位置(index/int64_t)
        int64_t m_c;   //<! 指し示す位置横方向の位置(index/int64_t)
    };

    //==コンストラクタ
    // コンストラクタ
    Board<T>() : m_data(null), m_height(0), m_width(0)
    {
    }

    // コピーコンストラクタ (ボード) =>(void)
    Board<T>(Board &rhs) : m_data(rhs.m_data) : m_height(rhs.m_height), m_width(rhs.m_width)
    {
    }
    // サイズ指定
    Board<T>(int64_t height, int64_t width) : m_data(height * width), m_height(height), m_width(width)
    {
    }

    // サイズ指定・デフォルト埋めコンストラクタ (サイズ,値)=>(void)
    Board<T>(int64_t height, int64_t width, T value) : m_data(height * width, value), m_height(height), m_width(width)
    {
    }

    //==主要メソッド
    // 座標からインデックスの取得
    int64_t getIndex(int64_t r, int64_t c)
    {
        return r * m_width + c;
    }

    // 特定位置のイテレータ取得(r,c)=>itr
    Iterator getIterator(int64_t r, int64_t c)
    {
        return Iterator(this, r, c);
    }

    // 先頭(左上位置)のイテレータ取得?()=>itr
    Iterator getFirst()
    {
        return getIterator(0, 0);
    }

    // 全部埋め(値)=>void
    void fill(T value)
    {
        for (int64_t i = 0; i < getSize(); ++i)
        {
            m_data[i] = value;
        }
    }

    // ある位置がボードの内側かどうか(r,c)=>bool
    bool isInside(int64_t r, int64_t c)
    {
        int64_t pos = r * m_width + c;
        return 0 <= pos && pos < getSize();
    }

    // ある位置がボードの外側かどうか(r,c)=>bool
    bool isOutside(int64_t r, int64_t c)
    {
        return !isInside();
    }

    // 特定位置の値取得(r,c)

    T &getRef(int64_t r, int64_t c)
    {
        return m_data[getIndex(r, c)];
    }

    // 指定位置の参照取得(r,c)
    T &getValue(int64_t r, int64_t c)
    {
        return *getRef(r, c);
    }

    // サイズ取得
    int64_t getSize()
    {
        return m_height * m_width;
    }

    // 位置取得
    int64_t getIndex(int64_t r, int64_t c)
    {
        return r * m_width + c;
    }

    //==メンバ変数
    vector<T> m_data; //<! データ実体
    int64_t m_height; //<! 高さ
    int64_t m_width;  //<! 横幅

    // フレンド登録
    friend Iterator;
};
