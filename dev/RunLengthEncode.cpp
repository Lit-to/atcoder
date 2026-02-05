#include <vector>
#include <cstdint>
struct token
{
    char code;
    int64_t count;
};
std::vector<token> runLengthEncode(std::string &target)
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