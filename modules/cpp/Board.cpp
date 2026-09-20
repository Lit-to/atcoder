#include <stdexcept>
#include <vector>
#include <iostream>

/**
 * 二次元ボード
 */
template <class T>
class Board
{
public:
    /**
     * イテレータ
     */
    class Iterator
    {
    public:
        //==コンストラクタ
        /**
         * デフォルトコンストラクタ
         */
        Iterator() : m_data(nullptr), m_r(0), m_c(0)
        {
        }

        /**
         * ボードと位置から作成するコンストラクタ
         * @param board 対応するボード
         * @param r 上から何行目か
         * @param c 左から何列目か
         */
        Iterator(Board<T> &board, int64_t r, int64_t c) : m_data(&board), m_r(r), m_c(c)
        {
        }

        /**
         * コピーコンストラクタ
         * @param target コピー元イテレータのイテレータ
         */
        Iterator(const Iterator &target) : m_data(target.m_data), m_r(target.m_r), m_c(target.m_c) {}

        //== 演算子,主要メソッド

        /**
         * 参照演算子
         * @param イテレータが指し示す先の参照
         */
        T &operator*()
        {
            return m_data->getRef(m_r, m_c);
        }

        /**
         * 移動
         * @param r 移動差分(縦)
         * @param c 移動差分(横)
         */
        void move(int64_t r, int64_t c)
        {
            m_r += r;
            m_c += c;
        }

        /**
         * 移動先のイテレータを取得
         * @param r 移動差分(縦)
         * @param c 移動差分(横)
         */
        Iterator getMoved(int64_t r, int64_t c)
        {
            auto itr = Iterator(*this);
            itr.move(r, c);
            return itr;
        };

        /**
         * 等価演算子
         * @param rhs 比較相手のイテレータ
         * @return 同じボードかつ同じ位置かどうか
         */
        bool operator==(Iterator &rhs)
        {
            return m_data == rhs.m_data && m_r == rhs.m_r && m_c == rhs.m_c;
        }

        /**
         * 不等価演算子
         * @param rhs 比較相手のイテレータ
         * @return 同じボードもしくは同じ位置ではない
         */
        bool operator!=(Iterator &rhs)
        {
            return (!this == rhs);
        }

        /**
         * 自分自身がボードの範囲内かどうか
         * @return 範囲内ならtrue
         */
        bool isInside() const
        {
            return m_data->isInside(m_r, m_c);
        }

        /**
         * 自分自身がボードの範囲外かどうか
         * @return 範囲外ならtrue
         */
        bool isOutside() const
        {
            return (!isInside());
        }

        /**
         * 自分自身の位置を表す一意の値を返す
         * @return 値
         */
        int64_t getIndex() const
        {
            return m_data.getIndex(m_r, m_c);
        }

    private:
        //==メンバー変数
        Board *m_data; //<!対応するボード
        int64_t m_r;   //<! 指し示すボードの縦方向の位置(index/int64_t)
        int64_t m_c;   //<! 指し示すボードの横方向の位置(index/int64_t)
    };

    //==コンストラクタ
    /**
     * デフォルトコンストラクタ
     */
    Board() : m_data(nullptr), m_height(0), m_width(0)
    {
    }

    /**
     * コピーコンストラクタ
     */
    Board(Board &rhs) : m_data(rhs.m_data), m_height(rhs.m_height), m_width(rhs.m_width)
    {
    }

    /**
     * コンストラクタ
     * 縦と横を指定してボードを作成
     */
    Board(int64_t height, int64_t width) : m_data(height * width), m_height(height), m_width(width)
    {
    }

    /**
     * コンストラクタ
     * 縦と横とデフォルト値を指定してボードを作成
     */
    Board(int64_t height, int64_t width, T value) : m_data(height * width, value), m_height(height), m_width(width)
    {
    }

    //==主要メソッド
    /**
     * ある位置についてその位置を表す一意の値を返す
     * @param r 縦方向の位置
     * @param c 横方向の位置
     */
    int64_t getIndex(int64_t r, int64_t c)
    {
        return r * m_width + c;
    }

    /**
     * 特定位置のイテレータを取得する
     * @param r 縦方向の位置
     * @param c 横方向の位置
     */
    Iterator getIterator(int64_t r, int64_t c)
    {
        return Iterator(*this, r, c);
    }

    /**
     * 全ての位置に同じ値を埋める
     * @param value 埋めたい値
     */
    void fill(T value)
    {
        for (int64_t i = 0; i < getSize(); ++i)
        {
            m_data[i] = value;
        }
    }

    /**
     * 特定位置がボードの範囲内かどうか
     * @return 範囲内ならtrue
     */
    bool isInside(int64_t r, int64_t c)
    {
        return (0 <= r && r < m_height) && (0 <= c && c < m_width);
    }

    /**
     * 特定位置がボードの範囲外かどうか
     * @return 範囲外ならtrue
     */
    bool isOutside(int64_t r, int64_t c)
    {
        return !isInside(r, c);
    }

    /**
     * 特定位置の参照を取得
     * @param r 縦方向の位置
     * @param c 横方向の位置
     * @return 参照
     */
    T &getRef(int64_t r, int64_t c)
    {
        return m_data[getIndex(r, c)];
    }

    /**
     * 特定位置の値を取得
     * @param r 縦方向の位置
     * @param c 横方向の位置
     * @return 値
     */
    T getValue(int64_t r, int64_t c)
    {
        return getRef(r, c);
    }

    /**
     * ボードのサイズ取得
     */
    int64_t getSize()
    {
        return m_height * m_width;
    }

    /**
     * 添え字演算子
     * @param イテレータが指し示す先の参照
     */
    T &operator[](int64_t m_r, int64_t m_c)
    {
        return getRef(m_r, m_c);
    }

    /**
     * 入力ストリーム演算子
     * 左上から右下まで順にデータを入力として取り込む
     */
    friend std::istream &operator>>(std::istream &stream, Board<T> &target)
    {
        for (int64_t i = 0; i < target.m_height; ++i)
        {
            for (int64_t j = 0; j < target.m_width; ++j)
            {
                stream >> target.m_data[target.getIndex(i, j)];
            }
        }
        return stream;
    }

    /**
     * 出力ストリーム演算子
     * 左上から右下まで順に出力する
     */
    friend std::ostream &operator<<(std::ostream &stream, const Board<T> &target)
    {
        for (int64_t i = 0; i < target.m_height; ++i)
        {
            for (int64_t j = 0; j < target.m_width; ++j)
            {
                stream << target.m_data[target.getIndex(i, j)] << " ";
            }
        }
        return stream;
    }

private:
    //==メンバ変数
    std::vector<T> m_data; //<! データ実体
    int64_t m_height;      //<! 高さ
    int64_t m_width;       //<! 横幅

    // フレンド登録
    friend Iterator;
};