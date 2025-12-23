// ABC328D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
bool hasABC(std::vector<char> &value)
{
    return (value[value.size() - 3] == 'A' && value[value.size() - 2] == 'B' && value[value.size() - 1] == 'C');
}
int main()
{

    /*入力エリア*/
    std::string S;
    std::cin >> S;
    int N = S.length();
    std::vector<char> stack(0);
    /*実装エリア */
    for (int i = 0; i < N; ++i)
    {
        stack.push_back(S.at(i));
        while (3 <= stack.size() && hasABC(stack))
        {
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
        }
    }

    for (int i = 0; i < stack.size(); ++i)
    {
        std::cout << stack[i];
    }
    std::cout << std::endl;
    return 0;
}
