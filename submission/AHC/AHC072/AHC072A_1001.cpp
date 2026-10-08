// AHC072A
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>
#include <random>
#include <deque>
#include <chrono>
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

#include <random>

/**
 * 乱数生成ラッパ
 * 最初にコンストラクタを読んだら以降はGenerate関数1回でてきとうな整数が返ってくる
 */
class randomGenerator
{
public:
    /**
     * コンストラクタ
     */
    randomGenerator() : m_generator(std::random_device{}()) {}
    /**
     * @brief 値から乱数生成関数
     * @param min 最小値
     * @param max 最大値
     */
    int64_t Generate(int64_t min, int64_t max)
    {
        std::uniform_int_distribution<> dist(min, max);
        return dist(m_generator);
    }
    /**
     * @brief 範囲から乱数生成関数
     * @param range {最小値,最大値}
     */
    template <size_t N>
    int64_t Generate(int64_t (&range)[N])
    {
        return Generate(range[0], range[1]);
    }

public:
    std::mt19937 m_generator; //!< メルセンヌツイスタのジェネレータ
};

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
        return m_data[index];
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
const int MAX_GROUP_SIZE = 7;
const int MIN_GROUP_SIZE = 7;
const int MAX_K = 12;
int K = 12;
Board<char> BOARD(0, 0);
int64_t N;
int64_t CELLS;
const int64_t TIME_LIMIT = 1500;

// 定数表現ここまで

// 型定義

/**
 * 移動方法を持つ構造体
 */
struct TRACK
{
    int64_t pos;      // トークンの位置を表す
    char direction;   // トークンの方向を表す
    int64_t distance; // 距離
    bool isPickup;    // 拾うかどうか
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

/**
 * 最適解回収構造体
 */

struct SLIME_SCORE
{
    ll score = INT64_MAX;
    ll groupSize;
    vector<ll> slimes;
};

struct TENTATIVE
{
    vector<vector<ll>> slimes;
    ll score;
};

// ノードとノードの間にどのノードがいるのかを求める関数
vector<TRACK> GenerateLine(const Board<char> &BOARD, int64_t from, int64_t to, char nestType)
{
    int64_t HW = BOARD.GetSize();
    vector<TRACK> result;
    vector<int64_t> done(HW);
    done[from] = true;
    std::queue<int64_t> tasks;
    tasks.push(from);
    vector<TRACK> parent(HW);
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
                if (destIter.IsOutside())
                {
                    continue;
                }
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
                    .isPickup = false,
                };
                if (destIndex == to || BOARD[destIndex] == nestType)
                {
                    posToken = TRACK{.pos = destIndex}; // ここから先に進むことはない
                    return;
                }
                tasks.push(destIndex);
            }
        }
    };
    Search();
    while (posToken.pos != from)
    {
        auto pos = posToken;
        posToken = parent[pos.pos];
        result.push_back(posToken);
    }
    std::reverse(all(result));
    result[0].isPickup = true;
    return result;
};

vector<TRACK> GenerateGroupTasks(const Board<char> &BOARD, vector<ll> nodes)
{
    vector<TRACK> result;
    for (ll i = 0; i + 1 < nodes.size(); ++i)
    {
        auto line = GenerateLine(BOARD, nodes[i], nodes[i + 1], BOARD[nodes.back()]);
        result.insert(result.end(), all(line));
    }
    return result;
}

// スライム同士のグループ分けを行った結果を返す
vector<vector<int64_t>> PlacementSlimes(vector<int64_t> &slimes, int64_t groupSize)
{
    vector<vector<int64_t>> result;
    for (int64_t i = 0; i < slimes.size(); ++i)
    {
        if (i % (groupSize) == 0)
        {
            result.push_back(vector<int64_t>());
        }
        result.back().push_back(slimes[i]);
    }
    return result;
}

int64_t GetDistance(ll u1, ll v1, ll u2, ll v2)
{
    return std::max(abs(u1 - u1), abs(v1 - v2));
};

vector<RESULT> GenerateResult(vector<TRACK> line, Board<char> &BOARD, vector<bool> &isActive, vector<int64_t> nests)
{
    vector<RESULT> result;
    auto firstIter = BOARD.GetIterator(line[0].pos);
    isActive[firstIter.GetIndex()] = false;
    for (ll i = 0; i < line.size(); ++i)
    {
        const auto pos = line[i].pos;
        const auto iter = BOARD.GetIterator(line[i].pos);
        ll newSlime = 0;
        ll k = 0;
        if (isActive[iter.GetIndex()])
        {
            ++k;
            if (line[i].isPickup)
            {
                isActive[iter.GetIndex()] = false;
                ++newSlime;
                --k;
            }
        }
        else if (!result.empty() && GetDistance(iter.GetR(), iter.GetC(), result.back().i, result.back().j) <= 1 && result.back().l + 1 <= result.back().k + 1 && result.back().d == line[i].direction)
        {
            ++result.back().l;
            continue;
        }
        auto task = RESULT{
            .i = iter.GetR(),
            .j = iter.GetC(),
            .k = k,
            .d = line[i].direction,
            .l = line[i].distance,
        };
        result.push_back(task);
    }

    return result;
}

int64_t Eval(const vector<RESULT> &result, int64_t penalty = 0)
{
    return result.size() + penalty * 1e6;
};

int64_t UpdateTentative(
    TENTATIVE &tentative,
    const vector<RESULT> &orders,
    const vector<vector<ll>> &slimes)
{
    const ll score = Eval(orders);

    if (score < tentative.score)
    {
        tentative.slimes = slimes;
        tentative.score = score;
    }

    return score;
}

vector<RESULT> TryTask(
    const vector<vector<int64_t>> &slimes,
    const vector<int64_t> &nests,
    Board<char> &BOARD)
{
    const ll COLOR_COUNT = slimes.size();
    const ll CELL_COUNT = N * N;

    // ============================================================
    // スライムID
    //
    // orderedIds[color] は、外から渡された処理順そのもの。
    // ============================================================

    struct SLIME
    {
        ll color;
        ll rank;
    };

    vector<SLIME> slimeInfo;
    vector<vector<ll>> orderedIds(COLOR_COUNT);

    for (ll color = 0; color < COLOR_COUNT; ++color)
    {
        for (ll rank = 0; rank < (ll)slimes[color].size(); ++rank)
        {
            ll id = slimeInfo.size();

            slimeInfo.push_back({
                .color = color,
                .rank = rank,
            });

            orderedIds[color].push_back(id);
        }
    }

    const ll SLIME_COUNT = slimeInfo.size();

    // ============================================================
    // 盤面状態
    //
    // towers[cell] : 下 -> 上
    // pos[id]      : 現在位置
    // homed[id]    : 帰巣済み
    // ============================================================

    struct STATE
    {
        vector<vector<ll>> towers;
        vector<ll> pos;
        vector<bool> homed;
    };

    STATE initialState{
        .towers = vector<vector<ll>>(CELL_COUNT),
        .pos = vector<ll>(SLIME_COUNT, -1),
        .homed = vector<bool>(SLIME_COUNT, false),
    };

    {
        ll id = 0;

        for (ll color = 0; color < COLOR_COUNT; ++color)
        {
            for (ll rank = 0; rank < (ll)slimes[color].size(); ++rank)
            {
                const ll cell = slimes[color][rank];

                initialState.towers[cell].push_back(id);
                initialState.pos[id] = cell;

                ++id;
            }
        }
    }

    // ============================================================
    // 巣
    // ============================================================

    vector<ll> nestColor(CELL_COUNT, -1);

    for (ll color = 0; color < COLOR_COUNT; ++color)
    {
        nestColor[nests[color]] = color;
    }

    const ll DR[4] = {
        0,
        0,
        -1,
        1,
    };

    const ll DC[4] = {
        -1,
        1,
        0,
        0,
    };

    const char DIR[4] = {
        'L',
        'R',
        'U',
        'D',
    };

    // ============================================================
    // 帰巣
    // ============================================================

    auto ApplyHome = [&](STATE &state, ll cell)
    {
        const ll color = nestColor[cell];

        if (color == -1)
        {
            return;
        }

        auto &tower = state.towers[cell];

        while (!tower.empty())
        {
            const ll id = tower.back();

            if (slimeInfo[id].color != color)
            {
                break;
            }

            tower.pop_back();

            state.homed[id] = true;
            state.pos[id] = -1;
        }
    };

    // ============================================================
    // 1操作
    // ============================================================

    auto ApplyMove = [&](STATE &state,
                         ll from,
                         ll k,
                         ll direction,
                         ll distance,
                         RESULT &result) -> bool
    {
        if (from < 0 || CELL_COUNT <= from)
        {
            return false;
        }

        auto &sourceTower = state.towers[from];

        const ll height = sourceTower.size();

        if (height == 0)
        {
            return false;
        }

        if (k < 0 || height <= k)
        {
            return false;
        }

        if (distance <= 0 || k + 1 < distance)
        {
            return false;
        }

        const ll fromR = from / N;
        const ll fromC = from % N;

        ll to = -1;

        for (ll step = 1; step <= distance; ++step)
        {
            const ll r =
                fromR + DR[direction] * step;

            const ll c =
                fromC + DC[direction] * step;

            if (r < 0 || N <= r ||
                c < 0 || N <= c)
            {
                return false;
            }

            const ll cell =
                BOARD.GetIndex(r, c);

            if (BOARD[cell] == '#')
            {
                return false;
            }

            to = cell;
        }

        const ll movingCount =
            height - k;

        if ((ll)state.towers[to].size() +
                movingCount >
            MAX_HEIGHT)
        {
            return false;
        }

        vector<ll> moving(
            sourceTower.begin() + k,
            sourceTower.end());

        sourceTower.erase(
            sourceTower.begin() + k,
            sourceTower.end());

        // 宙返り
        reverse(all(moving));

        auto &destTower =
            state.towers[to];

        for (ll id : moving)
        {
            destTower.push_back(id);
            state.pos[id] = to;
        }

        // 両端で帰巣
        ApplyHome(state, from);
        ApplyHome(state, to);

        result = RESULT{
            .i = fromR,
            .j = fromC,
            .k = k,
            .d = DIR[direction],
            .l = distance,
        };

        return true;
    };

    // ============================================================
    // 最短経路
    //
    // from, ..., to のセル列を返す。
    // 塔は障害物ではない。
    // ============================================================

    auto GetShortestPath =
        [&](ll from, ll to) -> vector<ll>
    {
        if (from == to)
        {
            return {from};
        }

        vector<ll> parent(
            CELL_COUNT,
            -1);

        std::queue<ll> q;

        parent[from] = from;
        q.push(from);

        while (!q.empty())
        {
            const ll current =
                q.front();

            q.pop();

            const ll r =
                current / N;

            const ll c =
                current % N;

            for (ll d = 0; d < 4; ++d)
            {
                const ll nr =
                    r + DR[d];

                const ll nc =
                    c + DC[d];

                if (nr < 0 || N <= nr ||
                    nc < 0 || N <= nc)
                {
                    continue;
                }

                const ll next =
                    BOARD.GetIndex(nr, nc);

                if (BOARD[next] == '#')
                {
                    continue;
                }

                if (parent[next] != -1)
                {
                    continue;
                }

                parent[next] = current;

                if (next == to)
                {
                    vector<ll> path;

                    ll p = to;

                    while (p != from)
                    {
                        path.push_back(p);
                        p = parent[p];
                    }

                    path.push_back(from);

                    reverse(all(path));

                    return path;
                }

                q.push(next);
            }
        }

        return {};
    };

    // ============================================================
    // tower 内で slimeId の位置
    // ============================================================

    auto GetTowerIndex =
        [&](const STATE &state,
            ll cell,
            ll slimeId) -> ll
    {
        const auto &tower =
            state.towers[cell];

        for (ll i = 0;
             i < (ll)tower.size();
             ++i)
        {
            if (tower[i] == slimeId)
            {
                return i;
            }
        }

        return -1;
    };

    // ============================================================
    // path の先頭から同方向に何マス続くか
    //
    // path:
    //   [現在位置, 次, 次, ...]
    // ============================================================

    auto GetStraightLength =
        [&](const vector<ll> &path) -> std::pair<ll, ll>
    {
        if (path.size() < 2)
        {
            return {-1, 0};
        }

        const ll from =
            path[0];

        const ll next =
            path[1];

        const ll fr = from / N;
        const ll fc = from % N;

        const ll nr = next / N;
        const ll nc = next % N;

        ll direction = -1;

        for (ll d = 0; d < 4; ++d)
        {
            if (fr + DR[d] == nr &&
                fc + DC[d] == nc)
            {
                direction = d;
                break;
            }
        }

        if (direction == -1)
        {
            return {-1, 0};
        }

        ll length = 1;

        for (ll i = 1;
             i + 1 < (ll)path.size();
             ++i)
        {
            const ll a = path[i];
            const ll b = path[i + 1];

            const ll ar = a / N;
            const ll ac = a % N;

            const ll br = b / N;
            const ll bc = b % N;

            if (ar + DR[direction] != br ||
                ac + DC[direction] != bc)
            {
                break;
            }

            ++length;
        }

        return {
            direction,
            length,
        };
    };

    // ============================================================
    // 最短経路上で次の1操作を決定
    //
    // carrier は絶対に動く側に残す。
    //
    // 最優先:
    //   ・最短経路上
    //   ・ジャンプによって手数を削る
    //
    // 同程度なら、
    //   ・下に残す同色スライムが少ない
    //   ・kが小さい
    // ============================================================

    struct MOVE_CHOICE
    {
        bool found = false;

        ll k = 0;
        ll direction = 0;
        ll distance = 1;

        ll score = INT64_MIN;
    };

    auto ChooseMove =
        [&](const STATE &state,
            ll carrier,
            const vector<ll> &path) -> MOVE_CHOICE
    {
        MOVE_CHOICE best;

        if (path.size() < 2)
        {
            return best;
        }

        const ll from =
            state.pos[carrier];

        if (from == -1)
        {
            return best;
        }

        const auto [direction, straightLength] =
            GetStraightLength(path);

        if (direction == -1)
        {
            return best;
        }

        const auto &tower =
            state.towers[from];

        const ll carrierIndex =
            GetTowerIndex(
                state,
                from,
                carrier);

        if (carrierIndex == -1)
        {
            return best;
        }

        /*
         * carrier を動かすには
         *
         * k <= carrierIndex
         *
         * でなければならない。
         *
         * また
         *
         * l <= k+1
         *
         * なので、
         *
         * 最大ジャンプ距離 =
         * carrierIndex + 1
         */
        const ll maxDistance = std::min(straightLength, carrierIndex + 1);

        for (ll distance = 1;
             distance <= maxDistance;
             ++distance)
        {
            /*
             * この距離を飛ぶためには
             *
             * k >= distance - 1
             */
            for (ll k = distance - 1;
                 k <= carrierIndex;
                 ++k)
            {
                const ll movingCount =
                    tower.size() - k;

                const ll to =
                    path[distance];

                if ((ll)state.towers[to].size() +
                        movingCount >
                    MAX_HEIGHT)
                {
                    continue;
                }

                /*
                 * 下に残される
                 * 「carrierと同じ色」の数。
                 *
                 * これが多いほど後で回収が必要になるため
                 * 若干不利にする。
                 */
                ll leftSameColor = 0;

                for (ll i = 0; i < k; ++i)
                {
                    const ll id =
                        tower[i];

                    if (slimeInfo[id].color ==
                        slimeInfo[carrier].color)
                    {
                        ++leftSameColor;
                    }
                }

                /*
                 * distance-1:
                 *   1マス移動を何回省略できるか。
                 *
                 * leftSameColor:
                 *   後で回収する可能性がある数。
                 *
                 * 同点なら長く飛ぶ方を選ぶ。
                 */
                const ll score =
                    (distance - 1) -
                    leftSameColor;

                if (!best.found ||
                    score > best.score ||
                    (score == best.score &&
                     distance > best.distance) ||
                    (score == best.score &&
                     distance == best.distance &&
                     k < best.k))
                {
                    best = MOVE_CHOICE{
                        .found = true,
                        .k = k,
                        .direction = direction,
                        .distance = distance,
                        .score = score,
                    };
                }
            }
        }

        return best;
    };

    // ============================================================
    // carrier を targetCell まで
    // 「最短経路上だけ」で運ぶ。
    //
    // 毎回 shortest path を取り直す。
    // ============================================================

    auto MoveCarrierTo =
        [&](STATE &state,
            ll carrier,
            ll targetCell,
            vector<RESULT> &operations) -> bool
    {
        ll safety = CELL_COUNT * 4;

        while (!state.homed[carrier] &&
               state.pos[carrier] != targetCell)
        {
            if (--safety < 0)
            {
                return false;
            }

            const ll from =
                state.pos[carrier];

            auto path =
                GetShortestPath(
                    from,
                    targetCell);

            if (path.size() < 2)
            {
                return false;
            }

            const auto choice =
                ChooseMove(
                    state,
                    carrier,
                    path);

            if (!choice.found)
            {
                return false;
            }

            RESULT operation;

            if (!ApplyMove(
                    state,
                    from,
                    choice.k,
                    choice.direction,
                    choice.distance,
                    operation))
            {
                return false;
            }

            operations.push_back(
                operation);
        }

        return true;
    };

    // ============================================================
    // 巣でcarrierの上に別色が乗っている場合、
    // 上だけ隣へ退かしてcarrierを帰巣させる。
    // ============================================================

    auto ExposeCarrierAtNest =
        [&](STATE &state,
            ll carrier,
            vector<RESULT> &operations) -> bool
    {
        if (state.homed[carrier])
        {
            return true;
        }

        const ll cell =
            state.pos[carrier];

        if (cell == -1)
        {
            return true;
        }

        const ll color =
            slimeInfo[carrier].color;

        if (cell != nests[color])
        {
            return false;
        }

        ApplyHome(state, cell);

        if (state.homed[carrier])
        {
            return true;
        }

        const ll carrierIndex =
            GetTowerIndex(
                state,
                cell,
                carrier);

        if (carrierIndex == -1)
        {
            return false;
        }

        const ll height =
            state.towers[cell].size();

        /*
         * carrierより上だけ飛ばす。
         */
        const ll k =
            carrierIndex + 1;

        if (k >= height)
        {
            return false;
        }

        const ll r =
            cell / N;

        const ll c =
            cell % N;

        for (ll d = 0; d < 4; ++d)
        {
            const ll nr =
                r + DR[d];

            const ll nc =
                c + DC[d];

            if (nr < 0 || N <= nr ||
                nc < 0 || N <= nc)
            {
                continue;
            }

            const ll to =
                BOARD.GetIndex(nr, nc);

            if (BOARD[to] == '#')
            {
                continue;
            }

            const ll movingCount =
                height - k;

            if ((ll)state.towers[to].size() +
                    movingCount >
                MAX_HEIGHT)
            {
                continue;
            }

            RESULT operation;

            if (!ApplyMove(
                    state,
                    cell,
                    k,
                    d,
                    1,
                    operation))
            {
                continue;
            }

            operations.push_back(
                operation);

            return state.homed[carrier];
        }

        return false;
    };

    // ============================================================
    // 1色について1回の処理を行う
    //
    // carrier =
    //   指定順の中で最初の未帰巣スライム
    //
    // carrier
    //   ↓
    // 次のスライム
    //   ↓
    // 次のスライム
    //   ↓
    // ...
    //   ↓
    // 巣
    //
    // 各区間は必ず最短路。
    // ============================================================

    struct PLAN
    {
        bool success = false;

        vector<RESULT> operations;

        STATE state;

        ll gained = 0;
    };

    auto CountHomed =
        [&](const STATE &state) -> ll
    {
        ll result = 0;

        for (bool value : state.homed)
        {
            result += value;
        }

        return result;
    };

    auto ProcessColor =
        [&](const STATE &source,
            ll color) -> PLAN
    {
        PLAN failure;

        ll carrier = -1;
        ll carrierRank = -1;

        for (ll rank = 0;
             rank < (ll)orderedIds[color].size();
             ++rank)
        {
            const ll id =
                orderedIds[color][rank];

            if (!source.homed[id])
            {
                carrier = id;
                carrierRank = rank;
                break;
            }
        }

        if (carrier == -1)
        {
            return failure;
        }

        STATE state = source;

        vector<RESULT> operations;

        const ll before =
            CountHomed(state);

        /*
         * 外から渡された順番通りに
         * 残りの同色スライムを通る。
         */
        for (ll rank = carrierRank + 1;
             rank < (ll)orderedIds[color].size();
             ++rank)
        {
            if (state.homed[carrier])
            {
                break;
            }

            const ll target =
                orderedIds[color][rank];

            if (state.homed[target])
            {
                continue;
            }

            /*
             * 既に同じ塔なら訪問済み扱い。
             */
            if (state.pos[target] ==
                state.pos[carrier])
            {
                continue;
            }

            const ll targetCell =
                state.pos[target];

            if (!MoveCarrierTo(
                    state,
                    carrier,
                    targetCell,
                    operations))
            {
                return failure;
            }
        }

        /*
         * 最後に自分の巣へ。
         */
        if (!state.homed[carrier])
        {
            if (!MoveCarrierTo(
                    state,
                    carrier,
                    nests[color],
                    operations))
            {
                return failure;
            }
        }

        /*
         * 別色が上に乗っていて
         * carrierが帰れなかった場合。
         */
        if (!state.homed[carrier])
        {
            if (!ExposeCarrierAtNest(
                    state,
                    carrier,
                    operations))
            {
                return failure;
            }
        }

        if (!state.homed[carrier])
        {
            return failure;
        }

        const ll after =
            CountHomed(state);

        return PLAN{
            .success = true,
            .operations =
                std::move(operations),
            .state =
                std::move(state),
            .gained =
                after - before,
        };
    };

    // ============================================================
    // 全体
    //
    // colorOrder は外から渡さない。
    //
    // 現在の盤面から各色を1回処理してみて、
    // 1帰巣あたりの操作数が良い色を採用する。
    // ============================================================

    STATE current =
        initialState;

    vector<RESULT> answer;

    while (CountHomed(current) <
           SLIME_COUNT)
    {
        bool found = false;

        PLAN bestPlan;

        double bestScore =
            std::numeric_limits<double>::infinity();

        for (ll color = 0;
             color < COLOR_COUNT;
             ++color)
        {
            bool remaining = false;

            for (ll id :
                 orderedIds[color])
            {
                if (!current.homed[id])
                {
                    remaining = true;
                    break;
                }
            }

            if (!remaining)
            {
                continue;
            }

            auto plan =
                ProcessColor(
                    current,
                    color);

            if (!plan.success ||
                plan.operations.empty() ||
                plan.gained <= 0)
            {
                continue;
            }

            const double score =
                (double)plan.operations.size() /
                (double)plan.gained;

            if (!found ||
                score < bestScore ||
                (score == bestScore &&
                 plan.operations.size() <
                     bestPlan.operations.size()))
            {
                found = true;

                bestScore = score;

                bestPlan =
                    std::move(plan);
            }
        }

        if (!found)
        {
            break;
        }

        answer.insert(
            answer.end(),
            bestPlan.operations.begin(),
            bestPlan.operations.end());

        current =
            std::move(bestPlan.state);
    }

    return answer;
}

void rotate(vector<ll> &v, ll l, ll r)
{
    if (l < r)
    {
        std::rotate(v.begin() + l, v.begin() + l + 1, v.begin() + r + 1);
    }
    else if (r < l)
    {
        std::rotate(v.begin() + r, v.begin() + l, v.begin() + l + 1);
    }
};

void ShuffleSlimes(
    vector<vector<ll>> &slimes,
    randomGenerator &rand)
{
    const ll color = rand.Generate(0, K - 1);
    const ll n = slimes[color].size();

    if (n < 2)
    {
        return;
    }

    const ll q = rand.Generate(0, 3);

    if (q >= 2)
    {
        // [l, r] の範囲を回転
        const ll l = rand.Generate(0, n - 2);
        const ll r = rand.Generate(l + 1, n - 1);

        rotate(slimes[color], l, r);
    }
    else if (q == 1)
    {
        // 2要素を交換
        ll a = rand.Generate(0, n - 1);
        ll b = rand.Generate(0, n - 1);

        while (a == b)
        {
            b = rand.Generate(0, n - 1);
        }

        std::swap(slimes[color][a], slimes[color][b]);
    }
    else
    {
        // 一部分だけreverse
        const ll l = rand.Generate(0, n - 2);
        const ll r = rand.Generate(l + 1, n - 1);

        std::reverse(
            slimes[color].begin() + l,
            slimes[color].begin() + r + 1);
    }
}
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    auto rand = randomGenerator();

    // 入力
    N = input<ll>();
    CELLS = N * N;
    K = input<ll>();

    BOARD = Board<char>(N, N);
    cin >> BOARD;

    // ========================================
    // スライム・巣の位置
    // ========================================

    vector<vector<ll>> slimes(K);
    vector<ll> nests(K);

    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j)
        {
            auto iter = BOARD.GetIterator(i, j);
            const char cell = *iter;

            if ('a' <= cell && cell <= 'z')
            {
                slimes[cell - 'a'].push_back(iter.GetIndex());
            }
            else if ('A' <= cell && cell <= 'Z')
            {
                nests[cell - 'A'] = iter.GetIndex();
            }
        }
    }

    // ========================================
    // 初期解
    // ========================================

    auto initialResult = TryTask(slimes, nests, BOARD);

    TENTATIVE tentative{
        .slimes = slimes,
        .score = Eval(initialResult),
    };

    // 最良のRESULTも保持しておく
    vector<RESULT> bestResult = std::move(initialResult);

    // ========================================
    // 山登り
    // ========================================

    const auto start = std::chrono::steady_clock::now();

    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    // while (elapsed < TIME_LIMIT)
    {

        // 現在の最良解から候補を作る
        auto candidateSlimes = tentative.slimes;

        // 1色の処理順だけ変更
        ShuffleSlimes(candidateSlimes, rand);

        // 候補から実際の操作列を生成
        auto candidateResult = TryTask(candidateSlimes, nests, BOARD);

        const ll candidateScore = Eval(candidateResult);

        // 改善した場合だけ採用
        if (candidateScore < tentative.score)
        {
            tentative.slimes = std::move(candidateSlimes);
            tentative.score = candidateScore;

            bestResult = std::move(candidateResult);
        }
        now = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    }

    // ========================================
    // 出力
    // ========================================

    for (const auto &r : bestResult)
    {
        cout << r.i << " " << r.j << " " << r.k << " " << r.d << " " << r.l << '\n';
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
