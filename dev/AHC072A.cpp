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
        Iterator(Board<T> &board, const int64_t r, const int64_t c) : m_data(&board), m_r(r), m_c(c)
        {
        }

        /**
         * ボードと位置から作成するコンストラクタ
         * @param board 対応するボード
         * @param r 上から何行目か
         * @param c 左から何列目か
         */
        Iterator(Board<T> &board, const int64_t index) : m_data(&board)
        {
            m_r = index / board.m_width;
            m_c = index % board.m_width;
        }

        /**
         * コピーコンストラクタ
         * @param target コピー元イテレータのイテレータ
         */
        Iterator(const Iterator &rhs) : m_data(rhs.m_data), m_r(rhs.m_r), m_c(rhs.m_c)
        {
        }

        //== 演算子,主要メソッド
        /**
         * コピー代入演算子
         * @param rhs 比較相手のイテレータ
         * @return 同じボードかつ同じ位置かどうか
         */
        Iterator operator=(const Iterator &rhs) const
        {
            return Iterator(rhs);
        }

        /**
         * 参照演算子
         * @param イテレータが指し示す先の参照
         */
        T &operator*()
        {
            return m_data->Get(m_r, m_c);
        }

        /**
         * 参照演算子(const)
         * @param イテレータが指し示す先の参照
         */
        T &operator*() const
        {
            return m_data->Get(m_r, m_c);
        }

        /**
         * 移動
         * @param r 移動差分(縦)
         * @param c 移動差分(横)
         */
        void Move(const int64_t r, const int64_t c)
        {
            m_r += r;
            m_c += c;
        }

        /**
         * 移動先のイテレータを取得
         * @param r 移動差分(縦)
         * @param c 移動差分(横)
         */
        Iterator GetMoved(const int64_t r, const int64_t c) const
        {
            auto itr = *this;
            itr.Move(r, c);
            return itr;
        };

        /**
         * 等価演算子
         * @param rhs 比較相手のイテレータ
         * @return 同じボードかつ同じ位置かどうか
         */
        bool operator==(const Iterator &rhs) const
        {
            return m_data == rhs.m_data && m_r == rhs.m_r && m_c == rhs.m_c;
        }

        /**
         * 不等価演算子
         * @param rhs 比較相手のイテレータ
         * @return 同じボードもしくは同じ位置ではない
         */
        bool operator!=(const Iterator &rhs) const
        {
            return (!(*this == rhs));
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
            return m_data->GetIndex(m_r, m_c);
        }

        /**
         * イテレータの指し示す左上からの縦の距離を返す
         * @return 値
         */
        int64_t GetR() const
        {
            return m_r;
        }

        /**
         * イテレータの指し示す左上からの横の距離を返す
         * @return 値
         */
        int64_t GetC() const
        {
            return m_c;
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
    Board(const Board &rhs) : m_data(rhs.m_data), m_height(rhs.m_height), m_width(rhs.m_width)
    {
    }

    /**
     * コンストラクタ
     * 縦と横を指定してボードを作成
     */
    Board(const int64_t height, const int64_t width) : m_data(height * width), m_height(height), m_width(width)
    {
    }

    /**
     * コンストラクタ
     * 縦と横とデフォルト値を指定してボードを作成
     */
    Board(const int64_t height, const int64_t width, const T value) : m_data(height * width, value), m_height(height), m_width(width)
    {
    }

    //==主要メソッド
    /**
     * ある位置についてその位置を表す一意の値を返す
     * @param r 縦方向の位置
     * @param c 横方向の位置
     */
    int64_t GetIndex(const int64_t r, const int64_t c) const
    {
        return r * m_width + c;
    }

    /**
     * 特定位置のイテレータを取得する
     * @param r 縦方向の位置
     * @param c 横方向の位置
     */
    Iterator GetIterator(const int64_t r, const int64_t c) const
    {
        return Iterator(const_cast<Board<T> &>(*this), r, c);
    }

    /**
     * 特定位置のイテレータを取得する
     * @param index m_data上の位置
     */
    Iterator GetIterator(const int64_t index) const
    {
        return Iterator(const_cast<Board<T> &>(*this), index);
    }

    /**
     * 全ての位置に同じ値を埋める
     * @param value 埋めたい値
     */
    void Fill(const T value)
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
    bool IsInside(const int64_t r, const int64_t c) const
    {
        return (0 <= r && r < m_height) && (0 <= c && c < m_width);
    }

    /**
     * 特定位置がボードの範囲外かどうか
     * @return 範囲外ならtrue
     */
    bool IsOutside(const int64_t r, const int64_t c) const
    {
        return !IsInside(r, c);
    }

    /**
     * 特定位置の参照を取得
     * @param r 縦方向の位置
     * @param c 横方向の位置
     * @return 参照
     */
    T &Get(const int64_t r, const int64_t c)
    {
        return m_data[GetIndex(r, c)];
    }

    /**
     * 特定位置の値を取得
     * @param r 縦方向の位置
     * @param c 横方向の位置
     * @return 値
     */
    const T &Get(const int64_t r, const int64_t c) const
    {
        return Get(r, c);
    }

    /**
     * 特定位置の参照を取得
     * @param index 位置
     * @return 参照
     */
    T &Get(const int64_t index)
    {
        return m_data[index];
    }

    /**
     * 特定位置の値を取得
     * @param index 位置
     * @return 値
     */
    const T &Get(const int64_t index) const
    {
        return Get(index);
    }

    /**
     * ボードのサイズ取得
     * @return 値
     */
    int64_t GetSize() const
    {
        return m_height * m_width;
    }

    /**
     * 添え字演算子
     * @param m_r 左上からの縦方向の位置
     * @param m_c 左上からの横方向の位置
     * @return イテレータが指し示す先の参照
     */
    T &operator[](const int64_t m_r, const int64_t m_c)
    {
        return Get(m_r, m_c);
    }

    /**
     * 添え字演算子
     * @param m_r 左上からの縦方向の位置
     * @param m_c 左上からの横方向の位置
     * @return イテレータが指し示す先の参照
     */
    T &operator[](const int64_t m_r, const int64_t m_c) const
    {
        return Get(m_r, m_c);
    }

    /**
     * 添え字演算子
     * @param m_r 左上からの縦方向の位置
     * @param m_c 左上からの横方向の位置
     * @return イテレータが指し示す先の参照
     */
    T &operator[](const int64_t index)
    {
        return Get(index);
    }

    /**
     * 添え字演算子
     * @return イテレータが指し示す先の参照
     */
    const T &operator[](const int64_t index) const
    {
        return Get(index);
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
     * @return 更新後の入力ストリーム
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
     * @return 更新後の出力ストリーム
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
// 自作ライブラリここまで
// 定数表現
using Iter = Board<char>::Iterator;
const int64_t LRUD_4[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
const char LRUD_4_c[4] = {'L', 'R', 'U', 'D'};
const int MAX_HEIGHT = 8;
const int COLOR_MAX = 12;
// 定数表現ここまで

// 型定義

/**
 * 移動方法を持つ構造体
 */
struct TRACK
{
    int64_t pos;      // トークンの位置を表す
    char direction;   // トークンの位置を表す
    int64_t distance; // 距離
};
/**
 * 答え配列の各命令指示
 */
struct RESULT
{
    ll i;
    ll j;
    ll k;
    char d;
    ll l;
};
// ノードとノードの間にどのノードがいるのかを求める関数
vector<TRACK> GenerateLine(const Board<char> &BOARD, int64_t from, int64_t to)
{
    int64_t N = BOARD.GetSize();
    vector<TRACK> result;
    vector<int64_t> done(BOARD.GetSize());
    done[from] = true;
    std::queue<int64_t> tasks;
    tasks.push(from);
    vector<TRACK> parent(N);
    // 探索
    TRACK posToken; // ゴールノードが入る予定の変数
    auto Search = [&]() -> void
    {
        while (!tasks.empty())
        {
            int64_t task = tasks.front();
            auto iterator = BOARD.GetIterator(task);
            tasks.pop();
            for (int i = 0; i < 4; ++i)
            {
                auto destIter = iterator.GetMoved(LRUD_4[i][0], LRUD_4[i][1]);
                auto destIndex = destIter.GetIndex();
                if (BOARD[destIndex] == '#')
                {
                    continue;
                }
                if (done[destIndex])
                {
                    continue;
                }
                done[destIndex] = true;
                int64_t distance = std::max(abs(LRUD_4[i][0]), abs(LRUD_4[i][1]));
                parent[destIndex] = TRACK{
                    .pos = task,
                    .direction = LRUD_4_c[i],
                    .distance = distance,
                };
                if (destIndex == to)
                {
                    posToken = parent[destIndex];
                    return;
                }
                tasks.push(destIndex);
            }
        }
    };
    Search();
    while (posToken.pos != from)
    {
        result.push_back(posToken);
        auto pos = posToken.pos;
        posToken = parent[pos];
    }
    result.push_back(TRACK{.pos = from});
    std::reverse(all(result));
    return result;
};

// スライム同士の位置関係を表すグラフを構築する
void GenerateGraph(vector<vector<TRACK>> &GRAPH, const Board<char> &BOARD, vector<ll> nodes)
{
    for (ll i = 0; i + 1 < nodes.size(); ++i)
    {
        auto line = GenerateLine(BOARD, nodes[i], nodes[i + 1]);
        for (ll j = 0; j < j + 1 < line.size(); ++j)
        {
            GRAPH[line[i].pos].push_back(line[i + 1]);
            GRAPH[line[i + 1].pos].push_back(line[i]);
        }
    }
};

// スライム同士のグループ分けを行った結果を返す
vector<vector<int64_t>> placementSlimes(vector<int64_t> slimes)
{
    vector<vector<int64_t>> result;
    for (int64_t i = 0; i < slimes.size(); ++i)
    {
        if (i % (MAX_HEIGHT - 1) == 0)
        {
            result.push_back(vector<int64_t>());
        }
        result.back().push_back(slimes[i]);
    }
    return result;
}

vector<RESULT> generateResult(vector<vector<TRACK>> &GRAPH, Board<char> BOARD, vector<bool> &isAlive)
{
    vector<RESULT> result;

    for (const auto &routes : GRAPH)
    {
        for (ll i = 0; i + 1 < routes.size(); ++i)
        {
            const auto currentPos = BOARD.GetIterator(routes[i].pos);
            const ll currentR = currentPos.GetR();
            const ll currentC = currentPos.GetC();

            const auto nextPos = BOARD.GetIterator(routes[i + 1].pos);
            const ll nextR = nextPos.GetR();
            const ll nextC = nextPos.GetC();

            ll k = 0;
            if (isAlive[currentPos.GetIndex()])
            {
                ++k;
            }

            result.push_back(RESULT{
                .i = currentR,
                .j = currentC,
                .k = k,
                .d = routes[i].direction,
                .l = routes[i].distance,
            });
        }
    }
    return result;
}
int64_t eval(const vector<RESULT> &result, ll penalty = 0)
{
    return result.size() + penalty * 1e6;
};

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力受け取り
    const auto N = input<ll>();
    const auto CELLS = N * N;
    const auto K = input<ll>();
    Board<char> BOARD(N, N);
    cin >> BOARD;
    // 巣とスライムのグラフ作成
    vector<vector<int64_t>> slimes(COLOR_MAX); // スライム位置
    vector<int64_t> nests(COLOR_MAX);          // 巣の位置
    vector<bool> isAlive(CELLS, false);        // スライムの色

    // 巣・スライム位置把握
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j)
        {
            auto iter = BOARD.GetIterator(i, j);
            if ('a' <= *iter && *iter <= 'z')
            {
                slimes[*iter - 'a'].push_back(BOARD.GetIterator(i, j).GetIndex());
                isAlive[BOARD.GetIndex(i, j)] = true;
            }
            if ('A' <= *iter && *iter <= 'Z')
            {
                nests[*iter - 'A'] = BOARD.GetIterator(i, j).GetIndex();
            }
        }
    }
    vector<RESULT> result;
    int64_t score = 0;
    while (true)
    {
        // <独立変数>スライムの順序
        // スライムを7個体ごとのグループに分ける
        vector<vector<TRACK>> GRAPH(CELLS);
        for (ll i = 0; i < COLOR_MAX; ++i)
        {
            auto slimeGroups = placementSlimes(slimes[i]);
            // グラフ構築(グラフ)
            for (auto &slimeGroup : slimeGroups)
            {
                slimeGroup.push_back(nests[i]);
                GenerateGraph(GRAPH, BOARD, slimeGroup);
            }
        }
        // 行動命令の作成(巣からスライムに向かってDFS)
        auto currentResult = generateResult(GRAPH, BOARD, isAlive);
        int64_t currentScore = eval(currentResult);
        if (currentScore < score)
        {
            result = currentResult;
            score = currentScore;
        }
    }
    for (auto &r : result)
    {
        cout << r.i << " " << r.j << " " << r.k << " " << r.d << " " << r.l << endl;
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
