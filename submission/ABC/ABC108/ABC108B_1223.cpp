// ABC108B
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
bool hasFox(std::vector<char> &value)
{
    return (value[value.size() - 3] == 'f' && value[value.size() - 2] == 'o' && value[value.size() - 1] == 'x');
}
int main()
{

    /*入力エリア*/
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    std::vector<char> stack(0);
    /*実装エリア */
    for (int i = 0; i < N; ++i)
    {
        stack.push_back(S[i]);
        while (3 <= stack.size() && hasFox(stack))
        {
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
        }
    }

    std::cout << stack.size();
    std::cout << std::endl;
    return 0;
}
