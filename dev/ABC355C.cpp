// ABC355C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
#include <vector>
#include <cstdint>
#include <string>

/**
 * @brief ランレングス圧縮
 */
class RunLengthCompression
{
public:
    /**
     * @brief 1トークンを表す構造体
     * @details 文字と個数を持つ
     */
    struct TOKEN
    {
        char code;     //! 文字
        int64_t count; //! 文字の連続個数
    };
    /**
     * @brief 文字列から連続部分列の個数と文字を持つ配列に圧縮する。
     * @param target 文字列
     */
    static std::vector<TOKEN> Encode(const std::string &target)
    {
        std::vector<TOKEN> result(0);
        result.push_back(TOKEN{.code = target[0], .count = 1});
        for (int64_t i = 1; i < target.size(); ++i)
        {
            if (result.back().code == target[i])
            {
                ++result.back().count;
            }
            else
            {
                result.push_back(TOKEN{.code = target[i], .count = 1});
            }
        }
        return result;
    }
    /**
     * @brief 圧縮済みのものから元の文字列に戻す。
     * @param target 圧縮済み配列
     */
    static std::string Decode(const std::vector<TOKEN> &target)
    {
        std::string output;
        for (int64_t i = 0; i < target.size(); ++i)
        {
            for (int64_t j = 0; j < target[i].count; ++j)
            {
                output.push_back(target[i].code);
            }
        }
        return output;
    }
};
using RLC = RunLengthCompression;

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
        int64_t x;
        int64_t y;
    };
    /**
     * @brief 方向を表す列挙型
     */
    enum Direction : int
    {
        UP = 0,
        UP_RIGHT = 1,
        RIGHT = 2,
        DOWN_RIGHT = 3,
        DOWN = 4,
        DOWN_LEFT = 5,
        LEFT = 6,
        UP_LEFT = 7,
    };
    /**
     * @brief 座標構造体からインデックス値に変換する関数
     */
    int64_t ConvertPosToIndex(const Board::POS &pos) const
    {
        return pos.y * m_width + pos.x;
    }
    /**
     * @brief インデックス値から座標構造体に変換する関数
     */
    Board::POS ConvertIndexToPos(const int64_t index) const
    {
        return Board::POS{.x = index % m_width, .y = index / m_width};
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
    T &operator[](const Board::POS &pos)
    {
        return m_data[ConvertPosToIndex(pos)];
    }
    /**
     * @brief 特定のマスのコンスト参照を返す
     * []演算子オーバーロード
     */
    const T &operator[](const Board::POS &pos) const
    {
        return m_data[ConvertPosToIndex(pos)];
    }
    /**
     * @param index 座標を表すインデックス
     * @brief 特定のマスがボード範囲内かどうかを返す
     */
    bool IsInside(const int64_t index) const
    {
        return IsInside(Board::ConvertIndexToPos(index));
    }
    /**
     * @param pos 座標
     * @brief 特定のマスがボード範囲内かどうかを返す
     */
    bool IsInside(const Board::POS &pos) const
    {
        return (0 <= pos.y && pos.y < m_height) && (0 <= pos.x && pos.x < m_width);
    }
    /**
     * @brief インスタンスの座標値がボードの範囲内かどうかを返す
     */
    bool IsInside() const
    {
        return IsInside(m_pos);
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
     * 縦を取得する
     */
    int64_t GetHeight() const
    {
        return m_height;
    }
    /**
     * 横を取得する
     */
    int64_t GetWidth() const
    {
        return m_width;
    }
    /**
     * 縦*横の値を取得する
     */
    int64_t GetSize() const
    {
        return m_size;
    }
    /**
     * 現在のインデックス値を取得する
     */
    int64_t GetIndex() const
    {
        return ConvertPosToIndex(m_pos);
    }
    /**
     * 現在の座標を取得する
     */
    const Board::POS &GetPos() const
    {
        return m_pos;
    }
    /**
     * @brief 現在の座標を左に1つ動かす
     * @details 厳密には、x座標を負の方向に1動かす
     */
    Board::POS MoveLeft()
    {
        Board::POS newPos{.x = m_pos.x - 1, .y = m_pos.y};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
    /**
     * @brief 現在の座標を右に1つ動かす
     * @details 厳密には、x座標を正の方向に1動かす
     */
    Board::POS MoveRight()
    {
        Board::POS newPos{.x = m_pos.x + 1, .y = m_pos.y};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
    /**
     * @brief 現在の座標を右に1つ動かす
     * @details 厳密には、x座標を正の方向に1動かす
     */
    Board::POS MoveUp()
    {
        Board::POS newPos{.x = m_pos.x, .y = m_pos.y - 1};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
    /**
     * @brief 現在の座標を下に1つ動かす
     * @details 厳密には、y座標を正の方向に1動かす
     */
    Board::POS MoveLow()
    {
        Board::POS newPos{.x = m_pos.x, .y = m_pos.y + 1};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
    /**
     * @brief 現在の座標を上下左右のどこかに1つ動かす
     * @param direction 方向
     */
    Board::POS MoveNeighbor(int direction)
    {
        switch (direction)
        {
        case Board::UP:
        {
            return MoveUp();
        }
        case Board::UP_RIGHT:
        {
            MoveUp();
            return MoveRight();
        }
        case Board::UP_RIGHT:
        {
            MoveUp();
            return MoveRight();
        }
        case Board::RIGHT:
        {
            return MoveRight();
        }
        case Board::DOWN_RIGHT:
        {
            MoveLow();
            return MoveRight();
        }
        case Board::DOWN:
        {
            return MoveLow();
        }
        case Board::DOWN_LEFT:
        {
            MoveLow();
            return MoveLeft();
        }
        case Board::LEFT:
        {
            return MoveLeft();
        }
        case Board::UP_LEFT:
        {
            MoveUp();
            return MoveLeft();
        }
        }
    }
    /**
     * @brief 現在の座標を特定の座標に移動させる
     * @param pos 移動先
     * @exception 移動先が範囲外の場合例外
     */
    void MovePos(const Board::POS pos)
    {
        if (!IsInside(pos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        m_pos = pos;
    }
    /**
     * @brief 標準入力からのファクトリ
     * @details H W H*W回の内容が来る想定
     */
    static Board<T> input()
    {
        int64_t height;
        int64_t width;
        std::cin >> height;
        std::cin >> width;
        Board<T> data = Board(height, width);
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
    Board::POS m_pos;      //!< 現在の座標
};
int main()
{
}