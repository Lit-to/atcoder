// ABC450C
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>

#include <map>
template <class KEY_TYPE, class VALUE_TYPE>
using TreeMap = std::map<KEY_TYPE, VALUE_TYPE>;
#include <unordered_map>
template <class KEY_TYPE, class VALUE_TYPE>
using HashMap = std::unordered_map<KEY_TYPE, VALUE_TYPE>;

#include <set>
template <class VALUE_TYPE>
using TreeSet = std::set<VALUE_TYPE>;
#include <unordered_set>
template <class VALUE_TYPE>
using HashSet = std::unordered_set<VALUE_TYPE>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
T input()
{
    T variable;
    cin >> variable;
    return variable;
}
template <typename T>
std::vector<T> input(int64_t n)
{
    std::vector<T> contents(n);
    for (int64_t i = 0; i < n; ++i)
    {
        contents[i] = input<T>();
    }
    return contents;
}
// 自作ライブラリここから
#include <stdexcept>
#include <vector>
#include <iostream>

/**
 * 二次元ボード
 */
template <class T>
class Board
{
public:
    /**
     * イテレータ
     */
    class Iterator
    {
    public:
        //==コンストラクタ
        /**
         * デフォルトコンストラクタ
         */
        Iterator() : m_data(nullptr), m_r(0), m_c(0)
        {
        }

        /**
         * ボードと位置から作成するコンストラクタ
         */
        Iterator(Board<T> &board, int64_t r, int64_t c) : m_data(&board), m_r(r), m_c(c)
        {
        }

        // コピーコンストラクタ
        Iterator(const Iterator &target) : m_data(target.m_data), m_r(target.m_r), m_c(target.m_c) {}

        //== 演算子,主要メソッド
        // *演算子(ボードの参照を返す)
        T &operator*()
        {
            return m_data->getRef(m_r, m_c);
        }

        // <<演算子(出力用)

        void move(int64_t r, int64_t c)
        {
            m_r += r;
            m_c += c;
        }

        Iterator getMoved(int64_t r, int64_t c)
        {
            auto itr = Iterator(*this);
            itr.move(r, c);
            return itr;
        };

        // 左に1つ移動
        void moveL()
        {
            --m_r;
        }

        // 右に1つ移動
        void moveR()
        {
            ++m_r;
        }

        // 上に1つ移動
        void moveU()
        {
            --m_c;
        }

        // 下に1つ移動
        void moveD()
        {
            ++m_c;
        }

        // 等価演算子(同じボード、同じ位置かどうか)
        bool operator==(Iterator &rhs)
        {
            return m_data == rhs.m_data && m_r == rhs.m_r && m_c == rhs.m_c;
        }

        // 不等価演算子
        bool operator!=(Iterator &rhs)
        {
            return (!this == rhs);
        }

        // ボードの内側かどうか
        bool isInside() const
        {
            return m_data->isInside(m_r, m_c);
        }

        // ボードの外側かどうか
        bool isOutside() const
        {
            return (!isInside());
        }

        int64_t getIndex() const
        {
            return m_data.getIndex(m_r, m_c);
        }

        //==メンバー変数
        Board *m_data; //<!対応するボード
        int64_t m_r;   //<! 指し示す位置縦方向の位置(index/int64_t)
        int64_t m_c;   //<! 指し示す位置横方向の位置(index/int64_t)
    };

    //==コンストラクタ
    // コンストラクタ
    Board() : m_data(nullptr), m_height(0), m_width(0)
    {
    }

    // コピーコンストラクタ (ボード) =>(void)
    Board(Board &rhs) : m_data(rhs.m_data), m_height(rhs.m_height), m_width(rhs.m_width)
    {
    }
    // サイズ指定
    Board(int64_t height, int64_t width) : m_data(height * width), m_height(height), m_width(width)
    {
    }

    // サイズ指定・デフォルト埋めコンストラクタ (サイズ,値)=>(void)
    Board(int64_t height, int64_t width, T value) : m_data(height * width, value), m_height(height), m_width(width)
    {
    }

    //==主要メソッド
    // 座標からインデックスの取得
    int64_t getIndex(int64_t r, int64_t c)
    {
        return r * m_width + c;
    }

    // 特定位置のイテレータ取得(r,c)=>itr
    Iterator getIterator(int64_t r, int64_t c)
    {
        return Iterator(*this, r, c);
    }

    // 先頭(左上位置)のイテレータ取得?()=>itr
    Iterator getFirst()
    {
        return getIterator(0, 0);
    }

    Iterator getLast()
    {
        return getIterator(m_height - 1, m_width - 1);
    }

    // 全部埋め(値)=>void
    void fill(T value)
    {
        for (int64_t i = 0; i < getSize(); ++i)
        {
            m_data[i] = value;
        }
    }

    // ある位置がボードの内側かどうか(r,c)=>bool
    bool isInside(int64_t r, int64_t c)
    {
        return (0 <= r && r < m_height) && (0 <= c && c < m_width);
    }

    // ある位置がボードの外側かどうか(r,c)=>bool
    bool isOutside(int64_t r, int64_t c)
    {
        return !isInside(r, c);
    }

    // 特定位置の参照取得(r,c)

    T &getRef(int64_t r, int64_t c)
    {
        return m_data[getIndex(r, c)];
    }

    // 指定位置の参照値(r,c)
    T getValue(int64_t r, int64_t c)
    {
        return getRef(r, c);
    }

    // サイズ取得
    int64_t getSize()
    {
        return m_height * m_width;
    }

    // >>演算子(入力受け取り用)
    friend std::istream &operator>>(std::istream &stream, Board<T> &target)
    {
        for (int64_t i = 0; i < target.m_height; ++i)
        {
            for (int64_t j = 0; j < target.m_width; ++j)
            {
                stream >> target.m_data[target.getIndex(i, j)];
            }
        }
        return stream;
    }
    // <<演算子(出力受け取り用)
    friend std::ostream &operator<<(std::ostream &stream, const Board<T> &target)
    {
        for (int64_t i = 0; i < target.m_height; ++i)
        {
            for (int64_t j = 0; j < target.m_width; ++j)
            {
                stream << target.m_data[target.getIndex(i, j)];
            }
        }
        return stream;
    }

    //==メンバ変数
    std::vector<T> m_data; //<! データ実体
    int64_t m_height;      //<! 高さ
    int64_t m_width;       //<! 横幅

    // フレンド登録
    friend Iterator;
};

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力スニペ
    // const auto S = input<std::string>();
    // const auto A = input<ll>(N);
    //
    const auto H = input<ll>();
    const auto W = input<ll>();
    Board<char> BOARD(H, W);
    cin >> BOARD;
    const int64_t LRUD_4[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    /**
     * DFSスニペット
     */
    auto dfs = [&](auto self, Board<char>::Iterator pos) -> void // 引数にノード、戻り値は適度に
    {
        // 訪問済み管理のチェック
        if (BOARD.isOutside(pos.m_r, pos.m_c))
        {
            return;
        }
        if (*pos != '.')
        {
            return;
        }
        // 訪問済み管理の登録
        (*pos) = '#';
        // 行きがけ順に処理したい内容
        for (auto &dest : LRUD_4) // 遷移処理
        {
            self(self, pos.getMoved(dest[0], dest[1]));
        }
        // 帰りがけ順に処理したい内容
    };
    for (ll i = 0; i < H; ++i)
    {
        if (BOARD.getValue(i, 0) == '.')
        {
            dfs(dfs, BOARD.getIterator(i, 0));
        }
        if (BOARD.getValue(i, W - 1) == '.')
        {
            dfs(dfs, BOARD.getIterator(i, W - 1));
        }
    }
    for (ll i = 0; i < W; ++i)
    {
        if (BOARD.getValue(0, i) == '.')
        {
            dfs(dfs, BOARD.getIterator(0, i));
        }
        if (BOARD.getValue(H - 1, i) == '.')
        {
            dfs(dfs, BOARD.getIterator(H - 1, i));
        }
    }
    ll result = 0;
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            if (BOARD.getValue(i, j) == '.')
            {
                ++result;
                dfs(dfs, BOARD.getIterator(i, j));
            }
        }
    }
    cout << result << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t TESTCASES = DEFAULT_TESTCASE;
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

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
