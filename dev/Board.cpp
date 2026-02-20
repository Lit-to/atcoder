#include <stdexcept>
#include <vector>
#include <iostream>

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
    Board::POS ConvertIndexToPos(const int64_t index) const
    {
        return Board::POS{.x = index % m_width, .y = index / m_width};
    }
    Board(int64_t H, int64_t W)
        : m_height(H), m_width(W), m_size(H * W), m_data(H * W)
    {
    }
    T &operator[](const Board::POS &pos)
    {
        return m_data[ConvertPosToIndex(pos)];
    }
    const T &operator[](const Board::POS &pos) const
    {
        return m_data[ConvertPosToIndex(pos)];
    }
    bool IsInside(const int64_t index) const
    {
        return IsInside(Board::ConvertIndexToPos(index));
    }
    bool IsInside(const Board::POS &pos) const
    {
        return (0 <= pos.y && pos.y < m_height) && (0 <= pos.x && pos.x < m_width);
    }
    bool IsInside() const
    {
        return IsInside(m_pos);
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
        return ConvertPosToIndex(m_pos);
    }
    const Board::POS &GetPos() const
    {
        return m_pos;
    }
    Board::POS MoveLeft()
    {
        Board::POS newPos{.x = m_pos.x - 1, .y = m_pos.y};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
    Board::POS MoveRight()
    {
        Board::POS newPos{.x = m_pos.x + 1, .y = m_pos.y};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
    Board::POS MoveUp()
    {
        Board::POS newPos{.x = m_pos.x, .y = m_pos.y - 1};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
    Board::POS MoveLow()
    {
        Board::POS newPos{.x = m_pos.x, .y = m_pos.y + 1};
        if (!IsInside(newPos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        return newPos;
    }
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
    void MovePos(const Board::POS pos)
    {
        if (!IsInside(pos))
        {
            throw std::out_of_range("移動先が範囲外です");
        }
        m_pos = pos;
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
    Board::POS m_pos;
};
int main()
{
    return 0;
}