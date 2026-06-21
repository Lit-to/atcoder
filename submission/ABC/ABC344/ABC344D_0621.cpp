// ABC344D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
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
    std::string toString() const
    {
        std::string result = "";
        for (int64_t i = 0; i < GetHeight(); ++i)
        {
            for (int64_t j = 0; j < GetWidth(); ++j)
            {
                result += std::to_string(this->operator[](i, j));
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
#include <vector>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <limits>

/**
 * @brief りっとーアルゴリズム便利ツール詰め合わせ
 * @details 状態を持たない関数のうち、ひとまとめにするほど規模の大きくないこまごまとした関数を置く
 */
namespace LitAlgorithm
{
    /**
     * 二分探索関数
     * 評価関数evalがtrueになる範囲とfalseになる範囲の境界値を求める
     * @param ok trueになる片極端
     * @param ng falseになる片極端
     * @param eval 評価関数
     */
    template <class Func>
    int64_t Search(int64_t ok, int64_t ng, Func eval)
    {
        while (1 < std::abs(ok - ng))
        {
            int64_t mid = (ok + ng) / 2;
            if (eval(mid))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        return ok;
    }
    /**
     * 値と桁数からビット列を生成する。
     * e.g.,(5,3) -> {true,false,true}
     */
    std::vector<bool> GenerateBit(int64_t value, const int64_t digits)
    {
        std::vector<bool> result(digits);
        for (int64_t i = 0; i < digits; ++i)
        {
            result[digits - i - 1] = (value & 1);
            value >>= 1;
        }
        ++value;
        return result;
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
    /**
     * @brief 条件がtrueのときにYes,そうでないときにNoと出力する
     * @param isYes Yesを吐き出す条件
     * @return isYesの中身
     */
    bool YesNo(bool isYes)
    {
        if (isYes)
        {
            Yes();
        }
        else
        {
            No();
        }
        return isYes;
    }
    /**
     * vectorの中身を前から順に空白区切りで吐き出す
     * @param first 開始イテレータ
     * @param last 終了イテレータ
     */
    template <class T>
    void Output(const T &first, const T &last)
    {
        for (auto it = first; it != last; ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    /**
     * vectorの中身を前から順に空白区切りで吐き出す
     * @param data コンテナ
     */
    template <class T>
    void Output(const T &data)
    {
        Output(data.begin(), data.end());
    }
    template <class T>
    /**
     * vectorの中身を前から順に取り込む
     * @param first 開始イテレータ
     * @param last 終了イテレータ
     */
    void Input(T first, T last)
    {
        for (auto it = first; it != last; ++it)
        {
            std::cin >> *it;
        }
    }
    /**
     * vectorの中身を前から順に取り込む
     * @param data コンテナ
     */
    template <class T>
    void Input(T &data)
    {
        Input(data.begin(), data.end());
    }
    /**
     * そこがボードの内側かどうかを判定する
     * @param i 調べたい座標(高さ)
     * @param j 調べたい座標(幅)
     * @param H ボードの高さ
     * @param W ボードの幅
     */
    bool IsInside(int64_t i, int64_t j, int64_t H, int64_t W)
    {
        return 0 <= i && i < H && 0 <= j && j < W;
    }

}
namespace LitA = LitAlgorithm;
#include <vector>
#include <cstdint>
/**
 * @brief りっとー数学便利ツール詰め合わせ
 * @details 状態を持たない関数として詰め合わせた数学ツールたち
 */
namespace LitMath
{
    /**
     * @brief コンテナの中の最大値を求める
     * @param 求めたいコンテナ(std::vector等)
     */
    template <class T>
    typename T::value_type Max(const T &target)
    {
        typename T::value_type nowMax = std::numeric_limits<typename T::value_type>::min();
        for (const auto &i : target)
        {
            if (nowMax < i)
            {
                nowMax = i;
            }
        }
        return nowMax;
    }
    /**
     * @brief コンテナの中の最小値を求める
     * @param 求めたいコンテナ(std::vector等)
     */
    template <class T>
    typename T::value_type Min(const T &target)
    {
        typename T::value_type nowMin = std::numeric_limits<typename T::value_type>::max();
        for (const auto &i : target)
        {
            if (i < nowMin)
            {
                nowMin = i;
            }
        }
        return nowMin;
    }
    /**
     * @brief コンテナの中の合計を求める
     * @param 求めたいコンテナ(std::vector等)
     */
    template <class T>
    typename T::value_type Sum(const T &target)
    {
        typename T::value_type now = 0;
        for (const auto &i : target)
        {
            now += i;
        }
        return now;
    }

    /**
     * @brief 順列を計算する
     * @param n n 母数
     * @param r r 項目数
     * @return nPrの計算結果
     *
     */
    int64_t Permutation(int64_t n, int64_t r)
    {
        int64_t result = 1;
        for (int64_t i = 0; i < r; ++i)
        {
            result *= (n - i);
        }
        return result;
    }
    /**
     * @brief 階乗を計算する
     * @param n 値
     * @return n!の計算結果
     *
     */
    int64_t Factorial(int64_t n)
    {
        return Permutation(n, n);
    }
    /**
     * @brief 組み合わせを計算する
     * @param n 母数
     * @param r 選択数
     * @return nCrの計算結果
     *
     */
    int64_t Combination(int64_t n, int64_t r)
    {
        int64_t result = 1;
        for (int64_t i = 0; i < r; ++i)
        {
            result *= (n - i);
            result /= i + 1;
        }
        return result;
    }
    /**
     * @brief 最大公約数を求める
     * @param A 求める値
     * @param B 求める値
     * @return AとBの最大公約数
     */
    int64_t CalcGCD(int64_t A, int64_t B)
    {
        if (A < B)
        {
            std::swap(A, B);
        }
        while (A % B != 0)
        {
            int64_t temp = A % B;
            A = temp;
            if (A < B)
            {
                std::swap(A, B);
            }
        }
        return B;
    }
    template <class T>
    /**
     * @brief uよりvが大きいときのみuを更新する
     * @return uよりvのほうが大きいかどうか
     */
    bool ChangeMax(T &u, T v)
    {
        if (u < v)
        {
            u = v;
            return true;
        }
        return false;
    }
    template <class T>
    /**
     * @brief uよりvが小さいときのみuを更新する
     * @return uよりvのほうが小さいかどうか
     */
    bool ChangeMin(T &u, T v)
    {
        if (v < u)
        {
            u = v;
            return true;
        }
        return false;
    }
    /**
     * @brief x^nを計算する
     * @details 繰り返し2乗法で計算する。modの値で毎回余りを取る。
     * @param x 底
     * @param n 指数
     * @param mod 余りを取る値(デフォルトは998244353)
     * @return n^rの値
     */
    int64_t PowMod(int64_t x, int64_t n, int64_t mod = 998244353)
    {
        int64_t result = 1;
        int64_t product = x;
        while (0 < n)
        {
            if (n & 1)
            {
                result = result * product % mod;
            }
            product = product * product % mod;
            n >>= 1;
        }
        return result;
    }
    /**
     * @brief x^nを計算する
     * @details 繰り返し2乗法で計算する。あまりをとらない。
     * @note ACLのmint等を利用する想定なので、積を取る際にmod計算が走らないとオーバーフローするので注意
     * @param x 底
     * @param n 指数
     * @return n^rの値
     */
    template <class T>
    T Pow(T x, int64_t n)
    {
        T result = 1;
        T product = x;
        while (0 < n)
        {
            if (n & 1)
            {
                result *= product;
            }
            product *= product;
            n >>= 1;
        }
        return result;
    }
}
namespace LitM = LitMath;
namespace LitUtility
{
    using namespace LitM;
    using namespace LitA;
}
namespace Lit = LitUtility;

ll countSameChars(string &s, string &t, ll startPos)
{
    ll count = 0;
    for (ll i = startPos; i < min(s.size(), t.size()); ++i)
    {
        if (s[i] == t[i])
        {
            ++count;
        }
        else
        {
            return -1;
        }
    }
    return count;
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    string T;
    ll N;
    cin >> T >> N;
    vector<ll> A(N);
    vector<vector<string>> S(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> A[i];
        for (ll j = 0; j < A[i]; ++j)
        {
            string s;
            cin >> s;
            S[i].push_back(s);
        }
    }
    ll n = T.size();

    Board<ll> DP(N + 1, n + 1); // i個目までのbag,j文字目まで一致させたときのコストの最小値
    const ll INF = N + N;
    DP.Fill(INF);
    DP[0, 0] = 0;
    for (ll i = 0; i < N; ++i) // i番目のバッグについて
    {
        for (ll j = 0; j < n + 1; ++j)
        {
            // なにもしないとき
            Lit::ChangeMin(DP[i + 1, j], DP[i, j]);
        }
        for (ll j = 0; j < n + 1; ++j)
        {
            // バッグのj個目を採用するとき
            for (ll k = 0; k < A[i]; ++k)
            {
                ll s_len = S[i][k].size();
                // 遷移前がk文字目のとき
                // 遷移前 DP[i,k]
                // 遷移後 DP[i+1,k+s_len]
                if (DP[i, j] == INF) // 遷移前が到達不能
                {
                    continue;
                }
                if (n + 1 <= j + s_len) // 遷移後が到達不能
                {
                    continue;
                }
                bool isOK = true;
                for (ll l = 0; l < s_len; ++l)
                {
                    if (S[i][k][l] != T[j + l])
                    {
                        isOK = false;
                        break;
                    }
                }
                if (isOK)
                {
                    Lit::ChangeMin(DP[i + 1, j + s_len], DP[i, j] + 1);
                }
            }
            // cerr << DP.toString() << endl;
        }
    }
    if (DP[N, n] == INF)
    {
        cout << -1 << endl;
        return;
    }
    cout << DP[N, n] << endl;
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