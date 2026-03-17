// TESOK001H
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * 二次元累積の組み方がスマートじゃないなぁと悩んでる
 *
 */

/*=========================*/

/**
 * 二次元ボードを使いやすくするためのクラス
 */
template <class T>
class Board
{
public:
    /**
     * @brief 座標情報を持つ構造体
     */
    struct POS
    {
        int64_t X; //!< 横位置
        int64_t Y; //!< 縦位置
    };
    /**
     * @brief 座標構造体からインデックス値に変換する関数
     */
    int64_t ConvertPosToIndex(const Board::POS &pos) const
    {
        return pos.Y * m_width + pos.X;
    }
    /**
     * @brief 座標構造体からインデックス値に変換する関数
     */
    int64_t ConvertPosToIndex(const int64_t y, const int64_t x) const
    {
        return y * m_width + x;
    }
    /**
     * @brief インデックス値から座標構造体に変換する関数
     */
    Board::POS ConvertIndexToPos(const int64_t index) const
    {
        return Board::POS{.X = index % m_width, .Y = index / m_width};
    }
    /**
     * コンストラクタ
     * @brief 縦横でボードを初期化し、各マスをデフォルトコンストラクタ初期化する
     */
    Board(int64_t H, int64_t W)
        : m_height(H), m_width(W), m_size(H * W), m_data(H * W)
    {
    }
    /**
     * @brief 特定のマスの参照を返す
     * []演算子オーバーロード
     */
    T &operator[](const int64_t y, const int64_t x)
    {
        return m_data[ConvertPosToIndex(Board::POS{.X = x, .Y = y})];
    }
    /**
     * @brief 特定のマスのコンスト参照を返す
     * []演算子オーバーロード
     */
    const T &operator[](const int64_t y, const int64_t x) const
    {
        return operator[](y, x);
    }
    /**
     * @brief 特定のマスの参照を返す
     * []演算子オーバーロード
     */
    T &operator[](const int64_t index)
    {
        return m_data[index];
    }
    /**
     * @brief 特定のマスのコンスト参照を返す
     * []演算子オーバーロード
     */
    const T &operator[](const int64_t index) const
    {
        return m_data[index];
    }
    /**
     * @param index 座標を表すインデックス
     * @brief 特定のマスがボード範囲内かどうかを返す
     */
    bool IsInside(const int64_t index) const
    {
        return IsInside(ConvertIndexToPos(index));
    }
    /**
     * @param pos 座標
     * @brief 特定のマスがボード範囲内かどうかを返す
     */
    bool IsInside(const int64_t y, const int64_t x) const
    {
        return (0 <= y && y < m_height) && (0 <= x && x < m_width);
    }
    /**
     * @brief インスタンスを値で埋める
     */
    void Fill(const T &value)
    {
        for (int64_t i = 0; i < m_size; ++i)
        {
            m_data[i] = value;
        }
    }
    /**
     * @brief インスタンスをデフォルトコンストラクタで埋める
     */
    void Clear()
    {
        Fill(T());
    }
    /**
     * @brief 縦を取得する
     */
    int64_t GetHeight() const
    {
        return m_height;
    }
    /**
     * @brief 横を取得する
     */
    int64_t GetWidth() const
    {
        return m_width;
    }
    /**
     * @brief 縦*横の値を取得する
     */
    int64_t GetSize() const
    {
        return m_size;
    }
    /**
     * @brief 標準入力からのファクトリ
     * @details H W H*W回の内容が来る想定
     */
    static Board<T> Input()
    {
        int64_t height;
        int64_t width;
        std::cin >> height;
        std::cin >> width;
        return Board<T>::Input(height, width);
    }
    /**
     * @brief 標準入力からのファクトリ
     * @details H*W回の内容が来る想定
     * @param H 作る高さ
     * @param W 作る幅
     */
    static Board<T> Input(int64_t H, int64_t W)
    {
        Board<T> data = Board(H, W);
        for (int64_t i = 0; i < data.GetSize(); ++i)
        {
            std::cin >> data[i];
        }
        return data;
    }

private:
    std::vector<T> m_data; //!< マス情報
    int64_t m_height;      //!< 高さ
    int64_t m_width;       //!< 幅
    int64_t m_size;        //!< ボードの全体サイズ
};

int main()
{
    // ============================================
    // 入力受け取り
    Board<int> BOARD = Board<int>::Input();
    Board<int> RATERAL_PRESUM(BOARD.GetHeight(), BOARD.GetWidth() + 1);
    Board<int> TWO_DIMENSIONAL_PRESUM(BOARD.GetHeight() + 1, BOARD.GetWidth() + 1);
    int H = BOARD.GetHeight();
    int W = BOARD.GetWidth();

    int64_t Q;
    std::cin >> Q;
    struct QUERY
    {
        int64_t a;
        int64_t b;
        int64_t c;
        int64_t d;
    };
    std::vector<QUERY> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        std::cin >> QUERIES[i].a;
        std::cin >> QUERIES[i].b;
        std::cin >> QUERIES[i].c;
        std::cin >> QUERIES[i].d;
        // 半開区間にしたいので、本来はc,dが+1されるべきだが、のちの都合で手前を1減らす
        --QUERIES[i].a;
        --QUERIES[i].b;
    }

    //=====================================
    /**
     * ※横向きに累積を取るループ
     * 2 0 0 5 1         0 2 2 2 7 8
     * 1 0 3 0 0         0 1 1 4 4 4
     * 0 8 5 0 2   ==>   0 0 8 13 13 15
     * 4 1 0 0 6         0 4 3 5 5 11
     * 0 9 2 7 0         0 0 9 11 18 18
     */

    for (int i = 0; i < H; ++i)
    {
        for (int j = 1; j < W + 1; ++j)
        {
            RATERAL_PRESUM[i, j] = RATERAL_PRESUM[i, j - 1] + BOARD[i, j - 1];
        }
    }
    //=====================================
    /**
     * ※縦向きに累積を取るループ
     *                       0 0 0 0 0 0
     * 0 2 2 2 7 8           0 2 2 2 7 8
     * 0 1 1 4 4 4           0 3 3 6 11 12
     * 0 0 8 13 13 15   ==>  0 3 11 19 24 27
     * 0 4 3 5 5 11          0 7 14 24 29 38
     * 0 0 9 11 18 18        0 7 23 35 47 56
     */

    for (int j = 0; j < W + 1; ++j)
    {
        for (int i = 1; i < H + 1; ++i)
        {
            // TWO_DIMENSIONAL_PRESUM i-1 => 一つ前
            // RATERAL_PRESUM i-1 => オフセット
            TWO_DIMENSIONAL_PRESUM[i, j] = TWO_DIMENSIONAL_PRESUM[i - 1, j] + RATERAL_PRESUM[i - 1, j];
        }
    }
    //================================================
    // クエリをたたく
    for (int64_t i = 0; i < Q; ++i)
    {
        int a, b, c, d;
        a = QUERIES[i].a;
        b = QUERIES[i].b;
        c = QUERIES[i].c;
        d = QUERIES[i].d;
        std::cout << TWO_DIMENSIONAL_PRESUM[c, d] - TWO_DIMENSIONAL_PRESUM[a, d] - TWO_DIMENSIONAL_PRESUM[c, b] + TWO_DIMENSIONAL_PRESUM[a, b] << std::endl;
    }
}