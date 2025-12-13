// ABC436A
// template
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

    int oCount = N - S.length();

    for (int i = 0; i < oCount; ++i)
    {
        std::cout << "o";
    }
    std::cout << S << std::endl;

    /*実装エリア */

    return 0;
}