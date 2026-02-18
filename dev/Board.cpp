#include <stdexcept>
#include <vector>
#include <iostream>

template <class T>
class Board
{
public:
    struct Pos
    {
        int64_t x;
        int64_t y;
    };
    enum DIRECTION : int
    {
        UP = 0,
        UPPER_RIGHT = 1,
        RIGHT = 2,
        LOWER_RIGHT = 3,
        LOW = 4,
        LOWER_LEFT = 5,
        LEFT = 6,
        UPPER_LEFT = 7,
    };
    int64_t convertPosToIndex(const Board::Pos &pos) const
    {
        return pos.y * m_width + pos.x;
    }
    int64_t convertIndexToPos(const int64_t &index) const
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
    T GetValue(Board::Pos &pos) const
    {
        return m_data[convertPosToIndex(pos)];
    }
    T operator[](Board::Pos &pos) const
    {
        return GetValue(pos);
    }
    void SetValue(const T &value)
    {
        m_data[m_index] = value;
    }
    void SetValue(Board::Pos &pos, const T &value)
    {
        m_data[convertPosToIndex(pos)] = value;
    }
    bool IsInside(int64_t &index) const
    {
        return IsInside(Board::convertIndexToPos(index));
    }
    bool IsInside(Board::Pos &pos) const
    {
        return (0 <= pos.y && pos.y < m_height) && (0 <= pos.x && pos.x < m_width);
    }
    bool IsInside() const
    {
        return IsInside(Board::convertIndexToPos(m_index));
    }
    void Fill(const T &value)
    {
        for (int64_t i = 0; i < m_size; ++i)
        {
            m_data[i] = value;
        }
    }
    void Empty()
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
    Board::Pos GetPos() const
    {
        return convertPosToIndex(m_index);
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
        return convertIndexToPos(m_index);
    }
    Board::Pos MoveNeighbor(int direction)
    {
        if (direction == Board::UP)
        {
            return MoveUp();
        }
        else if (direction == Board::UPPER_RIGHT)
        {
            MoveUp();
            return MoveRight();
        }
        else if (direction == Board::RIGHT)
        {
            return MoveRight();
        }
        else if (direction == Board::LOWER_RIGHT)
        {
            MoveLow();
            return MoveRight();
        }
        else if (direction == Board::LOW)
        {
            return MoveLow();
        }
        else if (direction == Board::LOWER_LEFT)
        {
            MoveLow();
            return MoveLeft();
        }
        else if (direction == Board::LEFT)
        {
            return MoveLeft();
        }
        else if (direction == Board::UPPER_LEFT)
        {
            MoveUp();
            return MoveLeft();
        }
    }
    void MovePos(Board::Pos &pos)
    {
        int64_t argPos = Board::convertPosToIndex(pos);
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
    return 0;
}