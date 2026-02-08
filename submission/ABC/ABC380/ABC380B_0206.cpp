// ABC380B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
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
    struct token
    {
        char code;     //! 文字
        int64_t count; //! 文字の連続個数
    };
    /**
     * @brief 文字列から連続部分列の個数と文字を持つ配列に圧縮する。
     * @param target 文字列
     */
    static std::vector<token> Encode(const std::string &target)
    {
        std::vector<token> result(0);
        result.push_back(token{.code = target[0], .count = 1});
        for (int64_t i = 1; i < target.size(); ++i)
        {
            if (result.back().code == target[i])
            {
                ++result.back().count;
            }
            else
            {
                result.push_back(token{.code = target[i], .count = 1});
            }
        }
        return result;
    }
    /**
     * @brief 圧縮済みのものから元の文字列に戻す。
     * @param target 圧縮済み配列
     */
    static std::string Decode(const std::vector<token> &target)
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

int main()
{
    std::string S;
    std::cin >> S;
    std::vector<RLC::token> rle = RLC::Encode(S);
    for (int64_t i = 0; i < rle.size(); ++i)
    {
        if (rle[i].code == '|')
        {
            continue;
        }
        std::cout << rle[i].count << " ";
    }
    std::string s_ = RLC::Decode(rle);
    std::cerr << s_ << std::endl;
    if (S != s_)
    {
        std::cout << "WA" << std::endl;
    }
    std::cout << std::endl;
}