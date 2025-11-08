// template
#include <iostream>
#include <string>
#include <vector>

int main()
{

    /*入力エリア*/

    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    /*実装エリア */
    if (A <= C)
    {
        if (B <= D)
        {
            std::cout << "No";
            return 0;
        }
        else
        {
            std::cout << "Yes";
            return 0;
        }
    }
    std::cout << "No";
    return 0;

    return 0;
}
