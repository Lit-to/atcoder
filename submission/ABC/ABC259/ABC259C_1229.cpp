// ABC259C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */
struct item
{
    char charactor;
    int64_t count;
};
std::vector<item> runLengthEncode(std::string target)
{
    std::vector<item> rleResult(0);
    for (int i = 0; i < target.length(); ++i)
    {
        if (rleResult.empty())
        {
            rleResult.push_back(item{.charactor = target[i], .count = 1});
            continue;
        }
        if (rleResult.back().charactor == target[i])
        {
            ++rleResult.back().count;
            continue;
        }
        rleResult.push_back(item{.charactor = target[i], .count = 1});
    }
    return rleResult;
}

int main()
{

    /*入力エリア
     * std::cin >> N;
     */
    std::string S, T;
    std::cin >> S;
    std::cin >> T;
    std::vector<item> rleS = runLengthEncode(S);
    std::vector<item> rleT = runLengthEncode(T);
    bool result = true;
    if (rleS.size() != rleT.size())
    {
        result = false;
    }
    else
    {
        for (int64_t i = 0; i < rleS.size(); ++i)
        {
            if (rleS[i].charactor == rleT[i].charactor && rleS[i].count == rleT[i].count)
            {
                continue;
            }
            else
            {
                if (rleS[i].charactor == rleT[i].charactor && 2 <= rleS[i].count && rleS[i].count <= rleT[i].count)
                {
                    continue;
                }
                else
                {
                    result = false;
                    break;
                }
            }
        }
    }
    if (result)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}