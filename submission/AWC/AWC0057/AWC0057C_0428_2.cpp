// AWC0057C
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
// using mint = atcoder::modint998244353;
using mint = atcoder::modint1000000007;
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
#include <vector>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <limits>
/**
 * @brief りっとー便利ツール詰め合わせ
 * @details 状態を持たない関数のうち、ひとまとめにするほど規模の大きくないこまごまとした関数を置く
 */
namespace LitUtility
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
    /**
     * @brief xよりyが大きいときのみxを更新する
     * @return xよりyのほうが大きいかどうか
     */
    int64_t ChangeMax(int64_t &x, int64_t &y)
    {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }
    /**
     * @brief xよりyが小さいときのみxを更新する
     * @return xよりyのほうが小さいかどうか
     */
    int64_t ChangeMin(int64_t &x, int64_t &y)
    {
        if (y < x)
        {
            y = x;
            return true;
        }
        return false;
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
     * @deprecated
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

namespace Lit = LitUtility;
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N, K;
    std::cin >> N >> K;
    std::vector<int64_t> L(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> L[i];
    }
    mint mx = Lit::Max(L);
    mint result = Lit::Sum(L) - mx;
    mint p = Lit::Pow(mint(2), K);
    std::cout << (result + mx * p).val() << std::endl;
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