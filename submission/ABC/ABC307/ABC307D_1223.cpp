// ABC307D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

int main()
{

    /*入力エリア*/
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    std::vector<char> chrStack(0);
    std::vector<int> parStack(0);
    for (int i = 0; i < N; ++i)
    {
        chrStack.push_back(S[i]);
        if (S[i] == '(')
        {
            parStack.push_back(i);
        }
        else if (S[i] == ')' && 0 < parStack.size())
        {
            while (chrStack[chrStack.size() - 1] != '(')
            {
                chrStack.pop_back();
            }
            chrStack.pop_back();
            parStack.pop_back();
        }
    }
    for (char i : chrStack)
    {
        std::cout << i;
    }

    std::cout << std::endl;

    /*実装エリア */

    return 0;
}