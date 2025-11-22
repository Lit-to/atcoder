// ABC433A
#include <iostream>
#include <string>
#include <vector>

int main()
{

    /*入力エリア*/
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    /*実装エリア */
    while (!(X < Y * Z))
    {
        if (X == Y * Z)
        {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        ++X;
        ++Y;
    }
    std::cout << "No" << std::endl;

    return 0;
}
