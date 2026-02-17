template <class T>
class Board
{
public:
    struct pos
    {
        int64_t x;
        int64_t y;
    };

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

    Board(int64_t H, int64_t W)
    {
        m_height = H;
        m_width = W;
        m_size = H * W;
        m_data(m_size);
    }
    int64_t calcPos(Board::pos &pos) const
    {
        return pos.y * m_width + pos.x;
    }
    T GetValue(Board::pos &pos) const
    {
        return m_data[calcPos(pos)];
    }
    T operator[](Board::pos &pos) const
    {
        return GetValue(pos);
    }
    void SetValue(const Board::pos &pos, const T &value) const
    {
        m_data[calcPos(pos)] = value;
    }
    bool IsInside(const Board::pos &pos) const
    {
        return (0 <= pos.y && pos.y < m_height) && (0 <= pos.x && pos.x < m_width);
    }
    void Fill(const T &value)
    {
        for (int64_t i = 0; i < m_size; ++i)
        {
            m_data[i] = value;
        }
    };
    void Empty()
    {
        Fill(T());
    }
    int64_t GetHeight()
    {
        return m_height;
    }
    int64_t GetWidth()
    {
        return m_width;
    }
    int64_t GetSize()
    {
        return m_size;
    }
    void SetPos(int64_t y, int64_t x)
    {
        m_pos = y * m_width + x;
    }
    void MoveNeighbor(int direction) {
        DIRECTION[direction]
    };

private:
    std::vector<T> m_data;
    int64_t m_height;
    int64_t m_width;
    int64_t m_size;
    int64_t m_pos;
};