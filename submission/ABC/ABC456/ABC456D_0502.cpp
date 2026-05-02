// ABC456D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
void v_output(const std::vector<T> &a)
{
    for (int64_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
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
     * @brief 特定のマスのコンスト参照を返す
     */
    const T &at(const int64_t y, const int64_t x) const
    {
        return m_data[ConvertPosToIndex(Board::POS{.X = x, .Y = y})];
    }
    /**
     * @brief 特定のマスのコンスト参照を返す
     */
    const T &at(const int64_t index) const
    {
        return m_data[index];
    }
    /**
     * @brief 特定のマスのコンスト参照を返す
     */
    void set(const int64_t y, const int64_t x, const T value)
    {
        m_data[ConvertPosToIndex(Board::POS{.X = x, .Y = y})] = value;
    }
    /**
     * @brief 特定のマスのコンスト参照を返す
     */
    void set(const int64_t index, const T value)
    {
        m_data[index] = value;
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
                result += std::to_string(this->at(i, j));
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
            T value;
            std::cin >> value;
            data.set(i, value);
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
 * 1ケースぶんの処理実行
 */
void solve()
{
    string S;
    cin >> S;
    ll N = S.size() + 1;
    vector<char> s(N);
    s[0] = '@';

    for (ll i = 1; i < N; ++i)
    {
        s[i] = S[i - 1];
    }
    Board<mint> BOARD(3, N);
    for (ll j = 1; j < N; ++j)
    {
        if (s[j] == 'a')
        {
            BOARD.set(0, j, BOARD.at(0, j) + 1);                  // 虚無からaを生やす
            BOARD.set(0, j, BOARD.at(0, j) + BOARD.at(1, j - 1)); // bにaを生やす
            BOARD.set(0, j, BOARD.at(0, j) + BOARD.at(2, j - 1)); // cにaを生やす
            BOARD.set(0, j, BOARD.at(0, j) + BOARD.at(0, j - 1)); // 使わない
            BOARD.set(1, j, BOARD.at(1, j - 1));                  // b cはそのまま
            BOARD.set(2, j, BOARD.at(2, j - 1));                  // b cはそのまま
        }
        else if (s[j] == 'b')
        {
            BOARD.set(1, j, BOARD.at(1, j) + 1);
            BOARD.set(1, j, BOARD.at(1, j) + BOARD.at(2, j - 1));
            BOARD.set(1, j, BOARD.at(1, j) + BOARD.at(0, j - 1));
            BOARD.set(1, j, BOARD.at(1, j) + BOARD.at(1, j - 1));
            BOARD.set(0, j, BOARD.at(0, j - 1));
            BOARD.set(2, j, BOARD.at(2, j - 1));
        }
        else if (s[j] == 'c')
        {
            BOARD.set(2, j, BOARD.at(2, j) + 1);
            BOARD.set(2, j, BOARD.at(2, j) + BOARD.at(0, j - 1));
            BOARD.set(2, j, BOARD.at(2, j) + BOARD.at(1, j - 1));
            BOARD.set(2, j, BOARD.at(2, j) + BOARD.at(2, j - 1));
            BOARD.set(0, j, BOARD.at(0, j - 1));
            BOARD.set(1, j, BOARD.at(1, j - 1));
        }
    }
    // cerr << BOARD.Output() << endl;
    cout << (BOARD.at(0, N - 1) + BOARD.at(1, N - 1) + BOARD.at(2, N - 1)).val() << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t TESTCASES = 1;

    // std::cin >> TESTCASES;

    for (int64_t i = 0; i < TESTCASES; ++i)
    {
        solve();
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================