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