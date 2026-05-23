// AWC0061C
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
    void Input(T data)
    {
        Input(data.begin(), data.end());
    }

}
namespace LitA = LitAlgorithm;

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    LitA::Input(A.begin(), A.end());
    ++K;
    vector<ll> DP;
    DP.push_back(A[0]);
    for (ll i = 1; i < N; ++i)
    {
        if (0 <= (i - K))
        {
            DP.push_back(std::max(DP[i - K] + A[i], DP.back()));
        }
        else
        {
            DP.push_back(std::max(A[i], DP.back()));
        }
    }
    cout << DP[N - 1] << endl;
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