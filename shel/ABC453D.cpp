// ABC453D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
#include <stdexcept>
#include <vector>
#include <iostream>
#include <queue>
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
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
int main()
{
    int64_t H, W;
    std::cin >> H >> W;
    Board<char> BOARD = Board<char>::Input(H, W);
    Board<std::vector<int>> distanceBoard(H, W);
    for (int64_t i = 0; i < H * W; ++i)
    {
        distanceBoard[i] = std::vector<int>(4);
    }
    int64_t START = 0;
    int64_t GOAL = 0;
    const int64_t LRUD[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    for (int64_t i = 0; i < H; ++i)
    {
        for (int64_t j = 0; j < W; ++j)
        {
            if (BOARD[i, j] == 'S')
            {
                START = BOARD.ConvertPosToIndex(i, j);
                BOARD[i, j] = '.';
            }
            else if (BOARD[i, j] == 'G')
            {
                GOAL = BOARD.ConvertPosToIndex(i, j);
                BOARD[i, j] = '.';
            }
            if (BOARD[i, j] == '#')
            {
                for (int k = 0; k < 4; ++k)
                {
                    distanceBoard[i, j][k] = -1;
                }
            }
            else //(BOARD[i, j] == '.' || BOARD[i, j] == 'o' || BOARD[i, j] == 'x')
            {
                for (int k = 0; k < 4; ++k)
                {
                    int64_t newPosY = i + LRUD[k][0];
                    int64_t newPosX = j + LRUD[k][1];
                    if (!BOARD.IsInside(newPosY, newPosX))
                    {
                        distanceBoard[i, j][k] = -1;
                        continue;
                    }
                    if (BOARD[newPosY, newPosX] == 'o' || BOARD[newPosY, newPosX] == 'x')
                    {
                        distanceBoard[newPosY, newPosX][k] = distanceBoard[i, j][k] + 1;
                    }
                }
            }
        }
    }
    /**
     * @brief 半開区間を表す構造体
     */
    struct NODE
    {
        int64_t pos;    //<! ノード番号
        int64_t weight; //<! 重み(距離)
        /**
         * ソート用の比較関数
         */
        bool operator>(const NODE &target) const
        {
            return weight > target.weight;
        }
    };
    std::vector<std::vector<NODE>> GRAPH(H * W);
    for (int64_t i = 0; i < H; ++i)
    {
        for (int64_t j = 0; j < W; ++j)
        {
            if (BOARD[i, j] == '#')
            {
                continue;
            }
            else // if (BOARD[i, j] == '.')
            {
                for (int k = 0; k < 4; ++k)
                {
                    int newPosY = i + LRUD[k][0];
                    int newPosX = j + LRUD[k][1];
                    if (!BOARD.IsInside(newPosY, newPosX))
                    {
                        continue;
                    }
                    NODE nextTo = NODE{.pos = BOARD.ConvertPosToIndex(i, j), .weight = distanceBoard[i, j][(k + 2) % 4]};
                    int64_t kp = BOARD.ConvertPosToIndex(newPosY, newPosX);
                    GRAPH[kp].push_back(nextTo);
                }
            }
        }
    }

    greater_priority_queue<NODE> tasks;
    tasks.push(NODE{.pos = START, .weight = 0});
    while (!tasks.empty())
    {
        NODE task = tasks.top();
        Board<std::vector<int>>::POS p = distanceBoard.ConvertIndexToPos(task.pos);
        int posX = p.X;
        int posY = p.Y;
        for (int i = 0; i < 4; ++i)
        {
            int newPosY = posY + LRUD[i][0];
            int newPosX = posX + LRUD[i][1];
        }
    }
    // std::cerr << distanceBoard.Output() << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================