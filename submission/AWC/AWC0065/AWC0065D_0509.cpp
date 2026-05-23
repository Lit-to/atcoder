// AWC0065D
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
    ll N, M;
    cin >> N >> M;
    struct CAMP
    {
        ll X;
        ll Y;
        ll C;
    };
    struct STORE
    {
        ll P;
        ll Q;
        ll K;
    };
    vector<CAMP> STORES(N);
    vector<STORE> CAMPS(M);
    for (ll i = 0; i < N; ++i)
    {
        cin >> STORES[i].X >> STORES[i].Y >> STORES[i].C;
    }
    for (ll i = 0; i < M; ++i)
    {
        cin >> CAMPS[i].P >> CAMPS[i].Q >> CAMPS[i].K;
    }
    for (ll i = 0; i < N; ++i)
    {
        ll x = STORES[i].X;
        ll y = STORES[i].Y;
        STORES[i].X = (x + y);
        STORES[i].Y = (x - y);
    }
    for (ll i = 0; i < M; ++i)
    {
        ll x = CAMPS[i].P;
        ll y = CAMPS[i].Q;
        CAMPS[i].P = (x + y);
        CAMPS[i].Q = (x - y);
    }
    const ll OFFSET = 1200;
    ll H = 2500;
    ll W = 2500;
    vector<vector<ll>> BOARD(H, vector<ll>(W));
    for (ll i = 0; i < N; ++i)
    {
        ll y = STORES[i].Y;
        ll x = STORES[i].X;
        BOARD[y + OFFSET][x] += STORES[i].C;
    }
    Board<ll> PRESUM(H + 1, W + 1);
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            PRESUM.set(i + 1, j + 1, BOARD[i][j]);
        }
    }
    for (ll i = 0; i < H + 1; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            PRESUM.set(i, j + 1, PRESUM.at(i, j + 1) + PRESUM.at(i, j));
        }
    }
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W + 1; ++j)
        {
            PRESUM.set(i + 1, j, PRESUM.at(i + 1, j) + PRESUM.at(i, j));
        }
    }
    auto query = [&](ll ly, ll lx, ll ry, ll rx) -> ll
    {
        ly += OFFSET;
        ry += OFFSET + 1;
        rx++;
        lx = std::max<ll>(0, lx);
        ly = std::max<ll>(0, ly);
        rx = std::min<ll>(W, rx);
        ry = std::min<ll>(H, ry);
        return PRESUM.at(ry, rx) - PRESUM.at(ry, lx) - PRESUM.at(ly, rx) + PRESUM.at(ly, lx);
    };
    for (ll i = 0; i < M; ++i)
    {
        ll lx = CAMPS[i].P - CAMPS[i].K;
        ll ly = CAMPS[i].Q - CAMPS[i].K;
        ll rx = CAMPS[i].P + CAMPS[i].K;
        ll ry = CAMPS[i].Q + CAMPS[i].K;
        // for (ll j = ly; j < ry + 1; ++j)
        // {
        //     for (ll k = lx; k < rx + 1; ++k)
        //     {
        //         cerr << PRESUM.at(OFFSET + j, k) << " ";
        //     }
        //     cerr << endl;
        // }
        ll result = query(ly, lx, ry, rx);
        cout << result << endl;
    }
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