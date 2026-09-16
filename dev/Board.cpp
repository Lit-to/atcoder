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
        Iterator() : m_data(null), m_pos(0)
        {
        }

        /**
         * ボードと位置から作成するコンストラクタ
         */
        Iterator(Board &board, int64_t pos) : m_data(board), m_pos(pos)
        {
        }

        // コピーコンストラクタ
        Iterator(Iterator &target) : m_data(target.m_data), m_pos(target.m_pos)
        {
        }

        //== 演算子,主要メソッド
        // +演算子(移動せずにコピーを返す)
        Iterator &operator+(Iterator rhs)
        {
            return getRight(rhs.m_pos);
        }

        // -演算子(移動せずにコピーを返す)
        Iterator &operator-(Iterator rhs)
        {
            return getLeft(rhs.m_pos);
        }

        // *演算子(ボードの参照を返す)
        Iterator &operator*()
        {
            return *m_data[m_pos];
        }

        // アロー演算子(ボードの参照を返す)
        Iterator &operator*()
        {
            return m_data[m_pos];
        }

        // +=演算子(差分移動)
        Iterator &operator+=(Iterator &rhs)
        {
            m_pos += rhs.m_pos;
        }

        // -=演算子(差分移動)
        Iterator &operator-=(Iterator &rhs)
        {
            m_pos -= rhs.m_pos;
        }

        Iterator &operator--()
        {
            --m_pos;
            return m_pos;
        }
        Iterator operator--(int)
        {
            int64_t reval = m_pos;
            --m_pos;
            return reval;
        }
        Iterator &operator++()
        {
            m_pos += rhs.m_pos;
        }

        Iterator operator++(int)
        {
            int64_t reval = m_pos;
            ++m_pos;
            return reval;
        }

        // 左に1つ移動
        Iterator &moveL()
        {
            --m_pos;
        }

        // 右に1つ移動
        Iterator &moveR()
        {
            ++m_pos;
        }

        // 上に1つ移動
        Iterator &moveU()
        {
            m_pos -= m_data.m_width;
        }

        // 下に1つ移動
        Iterator &moveD()
        {
            m_pos += m_data.m_width;
        }

        // 等価演算子(同じボード、同じ位置かどうか)
        bool operator=(Iterator &rhs)
        {
            return m_data == rhs.m_data && m_pos == rhs.m_pos;
        }

        // 不等価演算子
        bool operator!=(Iterator &rhs)
        {
            return (!this == rhs);
        }

        // ボードの内側かどうか
        bool isInside()
        {
            return 0 <= m_pos && < m_data->m_height * m_data->m_width;
        }

        // ボードの外側かどうか
        bool isOutside()
        {
            return (!isInside());
        }

        //==移動先コピーイテレータの取得
        // 左
        Iterator getLeft(int64_t distance)
        {
            return Iterator(m_data, m_pos - distance);
        }
        // 右
        Iterator getRight(int64_t distance)
        {
            return Iterator(m_data, m_pos + distance);
        }
        // 上
        Iterator getUpper(int64_t distance)
        {
            return Iterator(m_data, m_pos + m_data.m_width * distance);
        }
        // 下
        Iterator getLower(int64_t distance)
        {
            return Iterator(m_data, m_pos - m_data.m_width * distance);
        }

        //==メンバー変数
        Board m_data;  //<!対応するボード
        int64_t m_pos; //<! 指し示す位置(index/int64_t)
    };

    /**
     * 現在の位置からの差分が入った探索順序を持つイテレータ
     * Iteratorをオーバーライド
     */
    class SearchIterater
    {
        // デフォルトコンストラクタ(なにもしない)
        // コンストラクタ(vector<int64_t>,最初のindex=0)

        //==主要メソッド
        // 次に進む(探索順序を1つ進め、相対位置の参照を返す)
        // 前に戻る(探索順序を1つ戻し、相対位置の参照を返す)
        // 現在が探索順序の先頭かどうか
        // 現在が探索順序の最後かどうか
        // 最初にリセット

        //==探索ルールファクトリ(static)
        // LRUD(順不同パターン)
        // ULDR(反時計回り4パターン)
        // URDL(時計回り4パターン)
        // UUrRDrDLdLLu(時計回り8パターン)
        // ULuLLdDDrRUr(反時計回り8パターン)

        //==メンバ変数
        // 探索順序を表すべくた(現在の位置からの一次元上の相対位置を持つ)
        // 探索順序の現在の位置
        // イテレータ
    };

    //==コンストラクタ
    // コンストラクタ
    // コピーコンストラクタ (ボード) =>(void)

    //==主要メソッド
    // サイズ指定・デフォルト埋めコンストラクタ (サイズ,値)=>(void)
    // 特定位置のイテレータ取得(r,c)=>itr
    // 先頭(左上位置)のイテレータ取得?()=>itr
    // 全部埋め(値)=>void
    // ある位置がボードの内側かどうか(r,c)=>bool
    // ある位置がボードの外側かどうか(r,c)=>bool
    // 特定位置の値取得(r,c)
    // 指定位置の参照取得(r,c)

    //==メンバ変数
    // データ実体
    vector<T> m_data;
    // 縦高さ
    int64_t m_height;
    // 横幅
    int64_t m_width;

    // フレンド登録
    friend Iterator;
    friend SearchIterater;
};
