// AWC0051C
// template
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
        for (auto &i : target)
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
        for (auto &i : target)
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
        for (auto &i : target)
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
    int64_t calcGCD(int64_t A, int64_t B)
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
     * @brief xよりyが大きいときのみ更新する
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
     * @brief xよりyが小さいときのみ更新する
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
}
namespace Lit = LitUtility;
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N, M, K;
    std::cin >> N >> M >> K;
    struct PRJ
    {
        int64_t C;
        int64_t P;
        std::vector<bool> NO_COMP;
    };
    std::vector<PRJ> PROJECTS(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> PROJECTS[i].C;
        std::cin >> PROJECTS[i].P;
        PROJECTS[i].NO_COMP.resize(N);
    }
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v;
        std::cin >> u >> v;
        --u;
        --v;
        PROJECTS[u].NO_COMP[v] = true;
        PROJECTS[v].NO_COMP[u] = true;
    }
    int64_t result = 0;
    for (int64_t i = 0; i < (2 << N); ++i)
    {
        std::vector<bool> bits = Lit::GenerateBit(i, N);
        int64_t costSum = 0;
        int64_t profitSum = 0;
        for (int64_t j = 0; j < N; ++j)
        {
            if (!bits[j])
            {
                continue;
            }
            bool isCompetition = false;
            for (int64_t k = 0; k < N; ++k)
            {
                if (j == k)
                {
                    continue;
                }
                else if (PROJECTS[j].NO_COMP[k] && bits[k])
                {
                    isCompetition = true;
                    break;
                }
            }
            if (isCompetition)
            {
                break;
            }
            costSum += PROJECTS[j].C;
            profitSum += PROJECTS[j].P;
        }
        if (costSum <= K)
        {
            result = std::max(result, profitSum);
        }
    }
    std::cout << result << std::endl;
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