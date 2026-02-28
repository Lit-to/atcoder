// ABC447D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
#include <vector>
#include <cstdint>
#include <string>

/**
 * @brief ランレングス圧縮
 */
class RunLengthCompression
{
public:
    /**
     * @brief 1トークンを表す構造体
     * @details 文字と個数を持つ
     */
    struct TOKEN
    {
        char code;     //! 文字
        int64_t count; //! 文字の連続個数
    };
    /**
     * @brief 文字列から連続部分列の個数と文字を持つ配列に圧縮する。
     * @param target 文字列
     */
    static std::vector<TOKEN> Encode(const std::string &target)
    {
        std::vector<TOKEN> result(0);
        result.push_back(TOKEN{.code = target[0], .count = 1});
        for (int64_t i = 1; i < target.size(); ++i)
        {
            if (result.back().code == target[i])
            {
                ++result.back().count;
            }
            else
            {
                result.push_back(TOKEN{.code = target[i], .count = 1});
            }
        }
        return result;
    }
    /**
     * @brief 圧縮済みのものから元の文字列に戻す。
     * @param target 圧縮済み配列
     */
    static std::string Decode(const std::vector<TOKEN> &target)
    {
        std::string output;
        for (int64_t i = 0; i < target.size(); ++i)
        {
            for (int64_t j = 0; j < target[i].count; ++j)
            {
                output.push_back(target[i].code);
            }
        }
        return output;
    }
};
using RLC = RunLengthCompression;
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
int main()
{
    std::string S;
    std::cin >> S;
    std::vector<RLC::TOKEN> s = RLC::Encode(S);
    int64_t N = s.size();
    std::vector<RLC::TOKEN> stack(0);
    int64_t result = 0;
    for (int i = 0; i < N; ++i)
    {
        stack.push_back(s[i]);
        int64_t n = stack.size();
        if (stack[n - 3].code == 'A' && stack[n - 2].code == 'B' && stack[n - 1].code == 'C')
        {
            int64_t mn = stack[n - 3].count;
            int64_t mn = std::min(mn, stack[n - 2].count);
            int64_t mn = std::min(mn, stack[n - 1].count);
            result += mn;
            stack[n - 3].count -= mn;
            stack[n - 2].count -= mn;
            stack[n - 1].count -= mn;
            for (int i = 1; i <= 3; ++i)
            {
                if (stack[n - i].count == 0)
                {
                    stack.erase(n - i);
                }
            }
        }
    }
}