// AWC0055B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
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

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N, P, Q;
    struct POST
    {
        int64_t X;
        int64_t C;
        /**
         * ソート用の比較関数
         */
        bool operator<(const POST &target) const
        {
            return X < target.X;
        }
    };
    std::cin >> N >> P >> Q;
    std::vector<POST> POSTS(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> POSTS[i].X >> POSTS[i].C;
    }
    std::sort(POSTS.begin(), POSTS.end());
    int64_t pos_p = 0;
    int64_t pos_px = INT64_MAX;
    for (int64_t i = 0; i < N; ++i)
    {
        if (LitM::ChangeMin(pos_px, std::abs(P - POSTS[i].X)))
        {
            pos_p = i;
        }
    }
    int64_t pos_q = 0;
    int64_t pos_qx = INT64_MAX;
    for (int64_t i = 0; i < N; ++i)
    {
        if (LitM::ChangeMin(pos_qx, std::abs(Q - POSTS[i].X)))
        {
            pos_q = i;
        }
    }
    if (pos_p == pos_q)
    {
        std::cout << POSTS[pos_p].C + 2 << std::endl;
    }
    else if (pos_p != pos_q)
    {
        std::cout << POSTS[pos_p].C + POSTS[pos_q].C + 2 << std::endl;
    }
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
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