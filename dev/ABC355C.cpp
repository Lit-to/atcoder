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
template <class T>
class Board
{
public:
    struct POS
    {
        int64_t x;
        int64_t y;
    };
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
    int64_t ConvertPosToIndex(const Board::POS &pos) const
    {
        return pos.y * m_width + pos.x;
    }
    int64_t ConvertIndexToPos(const int64_t &index) const
    {
        return index / m_width + index % m_width;
    }
    Board(int64_t H, int64_t W)
    {
        m_height = H;
        m_width = W;
        m_size = H * W;
        m_data(m_size);
    }
    T GetValue() const
    {
        return m_data[m_index];
    }
    T GetValue(Board::POS &pos) const
    {
        return m_data[ConvertPosToIndex(pos)];
    }
    T operator[](Board::POS &pos) const
    {
        return GetValue(pos);
    }
    void SetValue(const T &value)
    {
        m_data[m_index] = value;
    }
    void SetValue(Board::POS &pos, const T &value)
    {
        m_data[ConvertPosToIndex(pos)] = value;
    }
    bool IsInside(int64_t &index) const
    {
        return IsInside(Board::ConvertIndexToPos(index));
    }
    bool IsInside(Board::POS &pos) const
    {
        return (0 <= pos.y && pos.y < m_height) && (0 <= pos.x && pos.x < m_width);
    }
    bool IsInside() const
    {
        return IsInside(Board::ConvertIndexToPos(m_index));
    }
    void Fill(const T &value)
    {
        for (int64_t i = 0; i < m_size; ++i)
        {
            m_data[i] = value;
        }
    }
    void Clear()
    {
        Fill(T());
    }
    int64_t GetHeight() const
    {
        return m_height;
    }
    int64_t GetWidth() const
    {
        return m_width;
    }
    int64_t GetSize() const
    {
        return m_size;
    }
    int64_t GetIndex() const
    {
        return m_index;
    }
    Board::POS GetPos() const
    {
        return ConvertPosToIndex(m_index);
    }
    int64_t MoveLeft()
    {
        if (!IsInside(m_index - 1))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        --m_index;
        return m_index;
    }
    int64_t MoveRight()
    {
        if (!IsInside(m_index + 1))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        ++m_index;
        return m_index;
    }
    int64_t MoveUp()
    {
        if (!IsInside(m_index - m_width))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        m_index -= m_width;
        return m_index;
    }
    int64_t MoveLow()
    {
        if (!IsInside(m_index + m_width))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        m_index += m_width;
        return ConvertIndexToPos(m_index);
    }
    Board::POS MoveNeighbor(int direction)
    {
        if (direction == Board::UP)
        {
            return MoveUp();
        }
        else if (direction == Board::UP_RIGHT)
        {
            MoveUp();
            return MoveRight();
        }
        else if (direction == Board::RIGHT)
        {
            return MoveRight();
        }
        else if (direction == Board::DOWN_RIGHT)
        {
            MoveLow();
            return MoveRight();
        }
        else if (direction == Board::DOWN)
        {
            return MoveLow();
        }
        else if (direction == Board::DOWN_LEFT)
        {
            MoveLow();
            return MoveLeft();
        }
        else if (direction == Board::LEFT)
        {
            return MoveLeft();
        }
        else if (direction == Board::UP_LEFT)
        {
            MoveUp();
            return MoveLeft();
        }
    }
    void MovePos(Board::POS &pos)
    {
        int64_t argPos = Board::ConvertPosToIndex(pos);
        if (!IsInside(argPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        m_index = argPos;
    }
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
    std::vector<T> m_data;
    int64_t m_height;
    int64_t m_width;
    int64_t m_size;
    int64_t m_index;
};
int main()
{
}