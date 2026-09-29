// AHC072A
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>
#include <random>
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
HashMap<char, int> LRUD_4_i{{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};
const int MAX_HEIGHT = 8;
const int MAX_GROUP_SIZE = 7;
const int MAX_K = 12;
int K = 12;
Board<char> BOARD(0, 0);
int64_t N;
int64_t CELLS;
const int64_t TIME_LIMIT = 1950;
std::mt19937 randomGenerator(std::random_device{}());

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
    ll i;   // 位置y
    ll j;   // 位置x
    ll k;   // k何匹残すか
    char d; // 方向LRUD
    ll l;   // 移動距離
};

/**
 * 解答
 */
struct SCORE_RESULT
{
    vector<ll> score;
    vector<RESULT> result;
};

struct SLIME_GROUP
{
    ll nest;
    vector<ll> contents;
};

/**
 * 最適解回収構造体
 */

struct SLIME_SCORE
{
    ll score = INT64_MAX;
    vector<ll> result;
};

/**
 * トークン
 */
struct TOKEN
{
    Iter pos;
    int64_t height;
    vector<char> contents;
    bool isNest;
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
vector<SLIME_GROUP> PlacementSlimes(vector<vector<int64_t>> &slimes, vector<int64_t> nests, int64_t groupSize = MAX_GROUP_SIZE)
{
    vector<SLIME_GROUP> result;
    for (ll i = 0; i < K; ++i)
    {
        for (int64_t j = 0; j < slimes[i].size(); ++j)
        {
            if (j % (groupSize) == 0)
            {
                result.push_back(SLIME_GROUP{
                    .nest = i,
                    .contents = vector<ll>(),
                });
            }
            result.back().contents.push_back(slimes[i][j]);
        }
    }
    return result;
}

int64_t GetDistance(ll u1, ll v1, ll u2, ll v2)
{
    return std::max(abs(u1 - u1), abs(v1 - v2));
};

vector<RESULT> GenerateResult(vector<TRACK> line, Board<int64_t> &activeSlimes, vector<TOKEN> &tokens, Board<char> &BOARD)
{
    vector<RESULT> result;

    for (ll i = 0; i < line.size(); ++i)
    {
        const auto &track = line[i];

        const auto iter = BOARD.GetIterator(track.pos);
        const ll r = iter.GetR();
        const ll c = iter.GetC();

        ll k = 0;

        // このマスにいる TOKEN
        const ll tokenIndex = activeSlimes[r, c];

        if (0 <= tokenIndex)
        {
            const auto &token = tokens[tokenIndex];

            // 回収対象なら回収する
            if (track.isPickup)
            {
                k = 0;
                activeSlimes[r, c] = -1;
            }
            else
            {
                // 拾わないので、全部このマスに残す
                k = token.contents.size();
            }
        }

        ll distance = track.distance;

        if (!track.isPickup)
        {
            auto dy = LRUD_4[LRUD_4_i[track.direction]][0];
            auto dx = LRUD_4[LRUD_4_i[track.direction]][1];
            const auto below = iter.GetMoved(1, 0);
            if (below.IsInside())
            {
                const ll belowIndex = activeSlimes[below.GetR(), below.GetC()];

                if (belowIndex >= 0)
                {
                    const auto &belowToken = tokens[belowIndex];
                    ll bonus = belowToken.contents.size();

                    /*
                     * ジャンプで飛ばすマスを確認する。
                     *
                     * ・lineの経路上に存在すること
                     * ・現在と同じ方向にまっすぐ進んでいること
                     * ・回収対象を飛ばさないこと
                     */
                    ll maxBonus = 0;

                    for (ll j = 1; j <= bonus; ++j)
                    {
                        const ll nextIndex = i + j;
                        if (line.size() <= nextIndex)
                        {
                            break;
                        }
                        const auto &next = line[nextIndex];
                        // 次のTRACKが同じ方向でなければ、ここまで
                        if (next.direction != track.direction)
                        {
                            break;
                        }

                        // 回収対象を飛ばすことになるなら、ここまで
                        if (next.isPickup)
                        {
                            break;
                        }

                        // 本当に現在地から一直線上のマスか確認
                        const auto nextIter = BOARD.GetIterator(next.pos);

                        const ll expectedR = r + dy * j;
                        const ll expectedC = c + dx * j;

                        if (nextIter.GetR() != expectedR || nextIter.GetC() != expectedC)
                        {
                            break;
                        }

                        maxBonus = j;
                    }

                    distance += maxBonus;
                }
            }
        }

        result.push_back({r, c, k, track.direction, distance});

        /*
         * 今回のdistance分は、このRESULTで一気に進む。
         *
         * ただし着地点のマスは次のループで処理する必要があるので、
         * 飛ばした分だけiを進める。
         */
        i += distance - 1;
    }

    return result;
}

int64_t Eval(const vector<RESULT> &result, int64_t penalty = 0)
{
    return result.size() + penalty * 1e6;
};

int64_t UpdateTentative(vector<ll> &scores, vector<vector<ll>> &slimes, vector<SLIME_SCORE> &tentative)
{
    ll score = 0;
    for (ll i = 0; i < K; ++i)
    {
        if (scores[i] < tentative[i].score)
        {
            tentative[i].result = slimes[i];
        }
        score += scores[i];
    }
    return score;
}

std::queue<TOKEN> GenerateSlimes(vector<vector<int64_t>> &slimes, vector<int64_t> &nests, Board<char> &BOARD)
{

    std::queue<TOKEN> currentSlimes; // スライムの色
    // 巣・スライム位置把握
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j)
        {
            if ('a' <= BOARD[i, j] && BOARD[i, j] <= 'z')
            {
                auto token = TOKEN{
                    .pos = BOARD.GetIterator(i, j),
                    .height = 1,
                    .contents = vector<char>(1, BOARD[i, j]),
                    .isNest = false,
                };
                currentSlimes.push(token);
            }
        }
    }
    return currentSlimes;
}

SCORE_RESULT TryTask(vector<SLIME_GROUP> &currentSlimes, vector<TOKEN> slimeTokens, vector<int64_t> &nests, Board<char> &BOARD)
{
    vector<RESULT> result;
    std::queue<SLIME_GROUP> tasks;
    Board<int64_t> activeSlimes(N, N, -1);
    for (ll i = 0; i < currentSlimes.size(); ++i)
    {
        currentSlimes[i].contents.push_back(nests[currentSlimes[i].nest]);
        std::reverse(all(currentSlimes[i].contents));
        tasks.push(currentSlimes[i]);
        for (ll j = 0; j < currentSlimes[i].contents.size(); ++j)
        {
            activeSlimes[slimeTokens[currentSlimes[i].contents[j]].pos.GetIndex()] = currentSlimes[i].contents[j];
        }
    }
    vector<ll> scores(K);
    while (!tasks.empty())
    {
        auto &task = tasks.front();
        auto &group = task.contents;
        auto nest = task.nest;
        auto from = group.back();
        group.pop_back();
        auto to = group.back();
        auto nestColor = *(slimeTokens[group.front()]).pos;
        auto line = GenerateLine(BOARD, slimeTokens[from].pos.GetIndex(), slimeTokens[to].pos.GetIndex(), nestColor);
        if (!slimeTokens[to].isNest)
        {
            slimeTokens[to].height += slimeTokens[from].height;
        }
        else
        {
            activeSlimes[slimeTokens[to].pos.GetIndex()] = -1;
        }
        activeSlimes[slimeTokens[from].pos.GetIndex()] = -1;
        auto r = GenerateResult(line, activeSlimes, slimeTokens, BOARD);
        scores[nest] += Eval(r);
        result.insert(result.end(), all(r));
        if (1 < task.contents.size())
        {
            tasks.push(task);
        }
        tasks.pop();
    }
    return SCORE_RESULT{.score = scores, .result = result};
}

SCORE_RESULT Answer(vector<SLIME_SCORE> &tentative, vector<TOKEN> &tokens, vector<int64_t> &nests, Board<char> &BOARD)
{
    vector<vector<ll>> slimes(K);
    for (ll i = 0; i < K; ++i)
    {
        slimes[i] = tentative[i].result;
    }
    auto slimeGroups = PlacementSlimes(slimes, nests);
    auto result = TryTask(slimeGroups, tokens, nests, BOARD);
    return result;
}

void ShuffleSlimes(vector<vector<int64_t>> &slimes)
{
    for (ll i = 0; i < K; ++i)
    {
        std::shuffle(all(slimes[i]), randomGenerator);
    }
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    std::mt19937 randomGenerator(std::random_device{}());
    // 入力受け取り
    N = input<ll>();
    CELLS = N * N;
    K = input<ll>();
    BOARD = Board<char>(N, N);
    cin >> BOARD;
    // 巣とスライムのグラフ作成
    vector<TOKEN> tokens; // スライム位置
    // 巣・スライム位置把握
    vector<vector<int64_t>> slimes(K);
    vector<int64_t> nests(K);
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j)
        {
            auto iter = BOARD.GetIterator(i, j);
            if ('a' <= *iter && *iter <= 'z')
            {
                slimes[*iter - 'a'].push_back(tokens.size());
                tokens.push_back(TOKEN{
                    .pos = iter,
                    .height = 1,
                    .contents = vector<char>(1, *iter),
                    .isNest = false,
                });
            }
            if ('A' <= *iter && *iter <= 'Z')
            {
                nests[*iter - 'A'] = tokens.size();
                tokens.push_back(TOKEN{
                    .pos = iter,
                    .height = 1,
                    .contents = vector<char>(1, *iter),
                    .isNest = true,
                });
            }
        }
    }
    int64_t score = INT64_MAX;
    vector<SLIME_SCORE> tentative(K);

    const auto start = std::chrono::steady_clock::now();
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();

    vector<ll> groupSizes(K);
    // while (elapsed < TIME_LIMIT)
    {
        ShuffleSlimes(slimes);
        auto slimeGroups = PlacementSlimes(slimes, nests);
        auto result = TryTask(slimeGroups, tokens, nests, BOARD);
        UpdateTentative(result.score, slimes, tentative);
        now = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    }
    auto result = Answer(tentative, tokens, nests, BOARD);
    for (auto &r : result.result)
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
