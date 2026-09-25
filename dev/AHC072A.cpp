// AHC072A
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
#include <fstream>
#include <sstream>
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
         * @param board 対応するボード
         * @param r 上から何行目か
         * @param c 左から何列目か
         */
        Iterator(Board<T> &board, int64_t r, int64_t c) : m_data(&board), m_r(r), m_c(c)
        {
        }

        /**
         * コピーコンストラクタ
         * @param target コピー元イテレータのイテレータ
         */
        Iterator(const Iterator &target) : m_data(target.m_data), m_r(target.m_r), m_c(target.m_c) {}

        //== 演算子,主要メソッド

        /**
         * 参照演算子
         * @param イテレータが指し示す先の参照
         */
        T &operator*()
        {
            return m_data->GetRef(m_r, m_c);
        }

        /**
         * 移動
         * @param r 移動差分(縦)
         * @param c 移動差分(横)
         */
        void Move(int64_t r, int64_t c)
        {
            m_r += r;
            m_c += c;
        }

        /**
         * 移動先のイテレータを取得
         * @param r 移動差分(縦)
         * @param c 移動差分(横)
         */
        Iterator GetMoved(int64_t r, int64_t c)
        {
            auto itr = Iterator(*this);
            itr.move(r, c);
            return itr;
        };

        /**
         * 等価演算子
         * @param rhs 比較相手のイテレータ
         * @return 同じボードかつ同じ位置かどうか
         */
        bool operator==(Iterator &rhs)
        {
            return m_data == rhs.m_data && m_r == rhs.m_r && m_c == rhs.m_c;
        }

        /**
         * 不等価演算子
         * @param rhs 比較相手のイテレータ
         * @return 同じボードもしくは同じ位置ではない
         */
        bool operator!=(Iterator &rhs)
        {
            return (!this == rhs);
        }

        /**
         * 自分自身がボードの範囲内かどうか
         * @return 範囲内ならtrue
         */
        bool IsInside() const
        {
            return m_data->IsInside(m_r, m_c);
        }

        /**
         * 自分自身がボードの範囲外かどうか
         * @return 範囲外ならtrue
         */
        bool IsOutside() const
        {
            return (!IsInside());
        }

        /**
         * 自分自身の位置を表す一意の値を返す
         * @return 値
         */
        int64_t GetIndex() const
        {
            return m_data.getIndex(m_r, m_c);
        }

    private:
        //==メンバー変数
        Board *m_data; //<!対応するボード
        int64_t m_r;   //<! 指し示すボードの縦方向の位置(index/int64_t)
        int64_t m_c;   //<! 指し示すボードの横方向の位置(index/int64_t)
    };

    //==コンストラクタ
    /**
     * デフォルトコンストラクタ
     */
    Board() : m_data(nullptr), m_height(0), m_width(0)
    {
    }

    /**
     * コピーコンストラクタ
     */
    Board(Board &rhs) : m_data(rhs.m_data), m_height(rhs.m_height), m_width(rhs.m_width)
    {
    }

    /**
     * コンストラクタ
     * 縦と横を指定してボードを作成
     */
    Board(int64_t height, int64_t width) : m_data(height * width), m_height(height), m_width(width)
    {
    }

    /**
     * コンストラクタ
     * 縦と横とデフォルト値を指定してボードを作成
     */
    Board(int64_t height, int64_t width, T value) : m_data(height * width, value), m_height(height), m_width(width)
    {
    }

    //==主要メソッド
    /**
     * ある位置についてその位置を表す一意の値を返す
     * @param r 縦方向の位置
     * @param c 横方向の位置
     */
    int64_t GetIndex(int64_t r, int64_t c) const
    {
        return r * m_width + c;
    }

    /**
     * 特定位置のイテレータを取得する
     * @param r 縦方向の位置
     * @param c 横方向の位置
     */
    Iterator GetIterator(int64_t r, int64_t c)
    {
        return Iterator(*this, r, c);
    }

    /**
     * 全ての位置に同じ値を埋める
     * @param value 埋めたい値
     */
    void Fill(T value)
    {
        for (int64_t i = 0; i < GetSize(); ++i)
        {
            m_data[i] = value;
        }
    }

    /**
     * 特定位置がボードの範囲内かどうか
     * @return 範囲内ならtrue
     */
    bool IsInside(int64_t r, int64_t c)
    {
        return (0 <= r && r < m_height) && (0 <= c && c < m_width);
    }

    /**
     * 特定位置がボードの範囲外かどうか
     * @return 範囲外ならtrue
     */
    bool IsOutside(int64_t r, int64_t c)
    {
        return !IsInside(r, c);
    }

    /**
     * 特定位置の参照を取得
     * @param r 縦方向の位置
     * @param c 横方向の位置
     * @return 参照
     */
    T &GetRef(int64_t r, int64_t c)
    {
        return m_data[GetIndex(r, c)];
    }

    /**
     * 特定位置の値を取得
     * @param r 縦方向の位置
     * @param c 横方向の位置
     * @return 値
     */
    T GetValue(int64_t r, int64_t c)
    {
        return GetRef(r, c);
    }

    /**
     * ボードのサイズ取得
     */
    int64_t GetSize()
    {
        return m_height * m_width;
    }

    /**
     * 添え字演算子
     * @param イテレータが指し示す先の参照
     */
    T &operator[](int64_t m_r, int64_t m_c)
    {
        return GetRef(m_r, m_c);
    }

    /**
     * デバッグ用文字列生成
     * @return mermaid文字列
     */
    const std::string ToMermaidString() const
    {
        std::ostringstream result;
        result << "```mermaid\n";
        result << "block-beta\n";
        result << "columns " + std::to_string(m_width) + "\n";
        std::string classPatternAStr = "class ";
        std::string classPatternBStr = "class ";
        for (int64_t i = 0; i < m_height; ++i)
        {
            for (int64_t j = 0; j < m_width; ++j)
            {
                result << "   ";
                std::string key = "n" + std::to_string(GetIndex(i, j));
                result << key;
                result << "[\"";
                result << m_data[GetIndex(i, j)];
                result << "\"]\n";
                if ((i + j) % 2 == 0)
                {
                    classPatternAStr += key + ",";
                }
                else
                {
                    classPatternBStr += key + ",";
                }
            }
        }
        result << "classDef patternA fill:#1B2026,color:#E6E6E6,stroke:#30363D,stroke-width:1px\n";
        result << "classDef patternB fill:#303740,color:#E6E6E6,stroke:#30363D,stroke-width:1px\n";
        classPatternAStr.pop_back(); //","を消す
        classPatternBStr.pop_back(); //","を消す
        classPatternAStr += " patternA";
        classPatternBStr += " patternB";

        std::string classDefStr = "";
        std::string resultStr = "";
        result << classPatternAStr + "\n";
        result << classPatternBStr + "\n";
        result << "```";
        return result.str();
    }

    /**
     * デバッグ用 ファイル出力(mermaid形式)
     * @param fileName ファイル名
     */
    void Dump(const std::string &fileName = "out.md") const
    {
        std::ofstream file(fileName);
        file << ToMermaidString() << std::endl;
        file.close();
    }

    /**
     * 入力ストリーム演算子
     * 左上から右下まで順にデータを入力として取り込む
     */
    friend std::istream &operator>>(std::istream &stream, Board<T> &target)
    {
        for (int64_t i = 0; i < target.m_height; ++i)
        {
            for (int64_t j = 0; j < target.m_width; ++j)
            {
                stream >> target.m_data[target.GetIndex(i, j)];
            }
        }
        return stream;
    }

    /**
     * 出力ストリーム演算子
     * 左上から右下まで順に出力する
     */
    friend std::ostream &operator<<(std::ostream &stream, const Board<T> &target)
    {
        for (int64_t i = 0; i < target.m_height; ++i)
        {
            for (int64_t j = 0; j < target.m_width; ++j)
            {
                stream << target.m_data[target.GetIndex(i, j)] << " ";
            }
        }
        return stream;
    }

private:
    //==メンバ変数
    std::vector<T> m_data; //<! データ実体
    int64_t m_height;      //<! 高さ
    int64_t m_width;       //<! 横幅

    // フレンド登録
    friend Iterator;
};
struct EDGE
{
    int64_t destR; // 隣の行先ノード
    int64_t destC; // そのノードに行くコスト
};
const int64_t LRUD_4[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 経路復元ダイクストラ

    // 入力スニペ
    const auto N = input<ll>();
    const auto CELLS = N * N;
    const auto K = input<ll>();
    Board<char> BOARD(N, N);
    cin >> BOARD;
    vector<vector<EDGE>> GRAPH(N * N);
    vector<vector<Board<char>::Iterator>> slimes(12);
    vector<Board<char>::Iterator> nests(12);
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j)
        {
            ll index = BOARD.GetIndex(i, j);
            if ('a' <= BOARD[i, j] && BOARD[i, j] <= 'z')
            {
                slimes[BOARD[i, j] - 'a'].push_back(BOARD.GetIterator(i, j));
            }
            if ('A' <= BOARD[i, j] && BOARD[i, j] <= 'Z')
            {
                nests[BOARD[i, j] - 'A'] = BOARD.GetIterator(i, j);
            }
            for (auto &d : LRUD_4)
            {
                for (ll k = 1; k < K; ++k)
                {
                    ll destR = i + (d[0] * k);
                    ll destC = j + (d[1] * k);
                    if (BOARD.IsOutside(i + (d[0] * k), j + (d[1] * k)))
                    {
                        continue;
                    }
                    if (BOARD[i, j] == '#')
                    {
                        break;
                    }
                    GRAPH[index].push_back(EDGE{.destR = destR, .destC = destC});
                }
            }
        }
    }
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
