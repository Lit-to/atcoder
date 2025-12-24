// ABC243D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <stack>

int main()
{

    /*入力エリア*/
    long N, X;
    std::string S;
    std::cin >> N >> X;
    std::cin >> S;
    std::vector<char> tasks(0);
    for (int i = 0; i < N; ++i)
    {
        if (S[i] == 'U')
        {
            if (0 < tasks.size() && (tasks.back() == 'L' || tasks.back() == 'R'))
            {
                tasks.pop_back();
                continue;
            }
        }
        tasks.push_back(S[i]);
    }
    long pos = X;

    for (int i = 0; i < tasks.size(); ++i)
    {
        // std::cerr << tasks[i];
        if (tasks[i] == 'U')
        {
            pos /= 2;
        }
        else
        {
            pos *= 2;
        }
        if (tasks[i] == 'R')
        {
            ++pos;
        }
    }
    // std::cerr << std::endl;
    std::cout << pos << std::endl;

    /*実装エリア */

    return 0;
}