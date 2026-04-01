// TESOK001T
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
#include <stdexcept>
#include <vector>
#include <iostream>
#include <limits>

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
 * @brief コンテナの中の最大値を求める
 * @param 求めたいコンテナ(std::vector等)
 */
template <class T>
typename T::value_type Max(const T &target)
{
    typename T::value_type nowMax = std::numeric_limits<typename T::value_type>::min();
    for (auto &i : target)
    {
        if (nowMax < i)
        {
            nowMax = i;
        }
    }
    return nowMax;
}

int main()
{
    std::string S, T, s, t;
    std::cin >> s >> t;
    S = "$";
    T = "$";
    S += s;
    T += t;
    int64_t N = S.size();
    int64_t M = T.size();
    Board<int64_t> DP(N, M);
    for (int64_t i = 0; i < N; ++i)
    {
        for (int64_t j = 0; j < M; ++j)
        {
            if (i == 0 || j == 0)
            {
                continue;
            }
            std::vector<int64_t> candidates;
            if (S[i] == T[j])
            {
                candidates.push_back(1 + DP[i - 1, j - 1]);
            }
            candidates.push_back(DP[i - 1, j]);
            candidates.push_back(DP[i, j - 1]);
            DP[i, j] = Max(candidates);
        }
    }
    // std::cerr << DP.Output() << std::endl;
    std::cout << DP[N - 1, M - 1] << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================