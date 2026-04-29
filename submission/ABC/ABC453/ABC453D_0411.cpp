// ABC453D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <set>
//
#include <stdexcept>
#include <vector>
#include <iostream>

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
        return m_data[ConvertPosToIndex(Board::POS{.X = x, .Y = y})];
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

    std::string Output() const
    {
        std::string result = "";
        for (int64_t i = 0; i < GetHeight(); ++i)
        {
            for (int64_t j = 0; j < GetWidth(); ++j)
            {
                result += std::to_string((*this)[i, j]);
                result += " ";
            }
            result += "\n";
        }
        return result;
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
        return Board::Input(height, width);
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
/**
 * @brief 条件がtrueのときにYesと出力する
 * @details if分岐中にYesを吐き出したい
 * @param isYes Yesを吐き出す条件
 * @return isYesの中身
 */
bool Yes(bool isYes = true)
{
    if (isYes)
    {
        std::cout << "Yes" << std::endl;
    }
    return isYes;
}
/**
 * @brief 条件がtrueのときにNoと出力する
 * @details if分岐中にNoを吐き出したい
 * @param isNo Noを吐き出す条件
 * @return isNoの中身
 */
bool No(bool isNo = true)
{
    if (isNo)
    {
        std::cout << "No" << std::endl;
    }
    return isNo;
}
/**
 * @brief 条件がtrueのときにYes,そうでないときにNoと出力する
 * @param isYes Yesを吐き出す条件
 * @return isYesの中身
 */
bool YesNo(bool isYes)
{
    if (isYes)
    {
        Yes();
    }
    else
    {
        No();
    }
    return isYes;
}
int main()
{
    int64_t H, W;
    std::cin >> H >> W;
    Board<char> BOARD = Board<char>::Input(H, W);
    int64_t start = 0;
    int64_t goal = 0;
    for (int64_t i = 0; i < H * W; ++i)
    {
        if (BOARD[i] == 'S')
        {
            start = i;
            BOARD[i] = '.';
        }
        else if (BOARD[i] == 'G')
        {
            goal = i;
            BOARD[i] = '.';
        }
    }
    // struct NODE
    // {
    //     int64_t posY;
    //     int64_t posX;
    //     int64_t direction;
    //     const bool operator<(NODE &rhs)
    //     {
    //         this->posY<
    //     }
    // };
    // std::set<NODE> done;
    std::vector<std::vector<bool>> done(5, std::vector<bool>(H * W));
    const int64_t LURD[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    std::vector<int64_t> route;
    auto dfs = [&](auto self, int64_t direction, int64_t curPosY, int64_t curPosX) -> bool
    {
        int64_t curPos = BOARD.ConvertPosToIndex(curPosY, curPosX);
        int64_t id = curPos;
        if (curPos == goal)
        {
            route.push_back(direction);
            return true;
        }
        if (done[direction][id])
        {
            return false;
        }
        done[direction][id] = true;

        if (BOARD[curPosY, curPosX] == '#')
        {
            return false;
        }
        if (BOARD[curPosY, curPosX] == '.')
        {
            for (int64_t i = 0; i < 4; ++i)
            {
                int64_t nextY = curPosY + LURD[i][0];
                int64_t nextX = curPosX + LURD[i][1];
                if (!BOARD.IsInside(nextY, nextX))
                {
                    continue;
                }
                if (BOARD[nextY, nextX] != '#')
                {
                    int64_t nextId = BOARD.ConvertPosToIndex(nextY, nextX);
                    if (done[i][nextId])
                    {
                        continue;
                    }

                    bool result = self(self, i, nextY, nextX);
                    if (result)
                    {
                        route.push_back(i);
                        return true;
                    }
                }
            }
        }
        else if (BOARD[curPosY, curPosX] == 'o')
        {
            for (int64_t i = 0; i < 4; ++i)
            {
                if (i != direction)
                {
                    continue;
                }
                int64_t nextY = curPosY + LURD[i][0];
                int64_t nextX = curPosX + LURD[i][1];
                if (!BOARD.IsInside(nextY, nextX))
                {
                    continue;
                }
                if (BOARD[nextY, nextX] != '#')
                {
                    int64_t nextId = BOARD.ConvertPosToIndex(nextY, nextX);
                    if (done[i][nextId])
                    {
                        continue;
                    }
                    bool result = self(self, i, nextY, nextX);
                    if (result)
                    {
                        route.push_back(i);
                        return true;
                    }
                }
            }
        }
        else if (BOARD[curPosY, curPosX] == 'x')
        {
            for (int64_t i = 0; i < 4; ++i)
            {
                if (i == direction)
                {
                    continue;
                }
                int64_t nextY = curPosY + LURD[i][0];
                int64_t nextX = curPosX + LURD[i][1];
                if (!BOARD.IsInside(nextY, nextX))
                {
                    continue;
                }
                if (BOARD[nextY, nextX] != '#')
                {
                    int64_t nextId = BOARD.ConvertPosToIndex(nextY, nextX);
                    if (done[i][nextId])
                    {
                        continue;
                    }
                    bool result = self(self, i, nextY, nextX);
                    if (result)
                    {
                        route.push_back(i);
                        return true;
                    }
                }
            }
        }
        return false;
    };
    Board<char>::POS pos = BOARD.ConvertIndexToPos(start);
    dfs(dfs, 4, pos.Y, pos.X);
    if (No(route.empty()))
    {
        return 0;
    }
    Yes();
    std::reverse(route.begin(), route.end());
    route.pop_back();
    char LURD_CHAR[4] = {'L', 'U', 'R', 'D'};
    for (int64_t &i : route)
    {
        std::cout << LURD_CHAR[i];
    }
    std::cout << std::endl;
}
//======================
/**
 *方針メモ欄
 *
 */
//======================