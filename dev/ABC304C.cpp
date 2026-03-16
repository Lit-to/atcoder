// ABC304C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stack>
#include <set>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
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
        Board<T> data = Board::Input(height, width);
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
 * @brief 座標データ構造体
 */
struct POS
{
    int64_t X; //!< x座標
    int64_t Y; //!< y座標
};

int64_t calcDistance(const POS &from, const POS &to)
{
    return (from.X - to.X) * (from.X - to.X) + (from.Y - to.Y) * (from.Y - to.Y);
}
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
struct task
{
    POS pos;
    POS last;
};

int main()
{
    int64_t N, D;
    std::cin >> N >> D;
    const int64_t LRUD[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    std::vector<POS> PEOPLE(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> PEOPLE[i].X;
        PEOPLE[i].X += 1000;
        std::cin >> PEOPLE[i].Y;
        PEOPLE[i].Y += 1000;
    }
    Board<int64_t> BOARD(2100, 2100);
    BOARD.Fill(-1);
    int64_t max_d = D * D;
    for (int64_t i = 0; i < N; ++i)
    {
        BOARD[PEOPLE[i].X, PEOPLE[i].Y] = i;
    }
    std::stack<task> tasks;
    tasks.push(task{.pos = PEOPLE[0], .last = PEOPLE[0]});
    std::set<int64_t> done;
    std::vector<bool> result(N);
    while (!tasks.empty())
    {
        task t = tasks.top();
        POS p = t.pos;
        POS last = t.last;
        tasks.pop();
        if (BOARD[p.X, p.Y] != -1)
        {
            result[BOARD[p.X, p.Y]] = true;
            last = p;
        }
        for (int i = 0; i < 8; ++i)
        {
            POS next = POS{.X = p.X + LRUD[i][0], .Y = p.Y + LRUD[i][1]};
            int64_t idx = BOARD.ConvertPosToIndex(next.X, next.Y);
            if (BOARD.IsInside(next.X, next.Y) && !done.contains(idx) && calcDistance(last, next) <= max_d)
            {
                tasks.push(task{.pos = next, .last = last});
                done.insert(idx);
            }
        }
    }
    for (int64_t i = 0; i < result.size(); ++i)
    {
        // clang-format off
        if (!Yes(result[i]))No();
        // clang-format on
    }
}