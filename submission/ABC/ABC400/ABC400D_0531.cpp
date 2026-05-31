// ABC400D
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
        POS p = ConvertIndexToPos(index);
        return this->IsInside(p.Y, p.X);
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
                result += std::to_string(this[i, j]);
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
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll H, W;
    cin >> H >> W;
    auto BOARD = Board<char>::Input(H, W);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    --A;
    --B;
    --C;
    --D;
    /**
     * @brief グラフの辺情報
     */
    struct EDGE
    {
        int64_t destination; // 隣の行先ノード
        int64_t cost;        // そのノードに行くコスト

        bool operator>(const EDGE &target) const
        {
            return cost > target.cost;
        }
    };
    vector<vector<EDGE>> GRAPH(H * W);
    const int64_t LRUD[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            for (ll d = 0; d < 4; ++d)
            {
                ll pos = BOARD.ConvertPosToIndex({j, i});
                ll pos1 = BOARD.ConvertPosToIndex({j + LRUD[d][1], i + LRUD[d][0]});
                if (BOARD.IsInside(i + LRUD[d][0], j + LRUD[d][1]))
                {
                    GRAPH[pos].push_back(EDGE{.destination = pos1, .cost = BOARD[pos1] == '#'});
                }
                ll pos2 = BOARD.ConvertPosToIndex({j + LRUD[d][1] + LRUD[d][1], i + LRUD[d][0] + LRUD[d][0]});
                if (BOARD.IsInside(i + LRUD[d][0] + LRUD[d][0], j + LRUD[d][1] + LRUD[d][1]))
                {
                    GRAPH[pos].push_back(EDGE{.destination = pos2, .cost = (BOARD[pos1] == '#' || BOARD[pos2] == '#')});
                }
            }
        }
    }
    ll T = BOARD.ConvertPosToIndex({B, A});
    ll F = BOARD.ConvertPosToIndex({D, C});
    vector<ll> costs(H * W, (ll)(10e9));
    greater_priority_queue<EDGE> tasks;
    tasks.push(EDGE{.destination = T, .cost = 0});
    costs[T] = 0;
    while (!tasks.empty())
    {
        EDGE p = tasks.top();
        tasks.pop();
        if (costs[p.destination] < p.cost)
        {
            continue;
        }
        for (EDGE &d : GRAPH[p.destination])
        {
            ll newCost = p.cost + d.cost;
            if (costs[d.destination] <= newCost)
            {
                continue;
            }
            costs[d.destination] = newCost;
            tasks.push(EDGE{.destination = d.destination, .cost = newCost});
        }
    }
    cout << costs[F] << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
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