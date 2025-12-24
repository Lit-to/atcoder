// ABC283D
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdint>
#include <unordered_set>

int main()
{

    /*入力エリア*/
    std::string S;
    std::cin >> S;

    /*実装エリア */
    std::string result = "Yes";
    std::unordered_set<char> box;
    std::stack<int> par;
    std::stack<char> charStack;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == '(')
        {
            par.push(charStack.size());
        }
        else if (S[i] == ')')
        {
            int j = par.top();
            par.pop();
            while (j < charStack.size())
            {
                box.erase(charStack.top());
                charStack.pop();
            }
        }
        else
        {
            if (box.contains(S[i]))
            {
                result = "No";
                break;
            }
            else
            {
                charStack.push(S[i]);
                box.insert(S[i]);
            }
        }
    }
    std::cout << result << std::endl;

    return 0;
}