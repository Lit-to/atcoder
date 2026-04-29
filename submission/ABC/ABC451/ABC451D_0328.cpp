// ABC451D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//
std::vector<int64_t> goodNumbers;
std::vector<std::string> candidates;
void dfs(std::string num)
{
    for (std::string &i : candidates)
    {
        if (9 < num.size() + i.size())
        {
            continue;
        }
        dfs(num + i);
    }
    if (!num.empty())
    {
        goodNumbers.push_back(std::stoll(num));
    }
}
int main()
{
    int64_t N;
    std::cin >> N;
    int64_t num = 1;

    while (num < (1ll << 31))
    {
        candidates.push_back(std::to_string(num));
        num <<= 1;
    }
    dfs("");
    std::sort(goodNumbers.begin(), goodNumbers.end());
    goodNumbers.erase(std::unique(goodNumbers.begin(), goodNumbers.end()), goodNumbers.end());
    std::cout << goodNumbers[N - 1] << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================