// template
#include <iostream>
#include <string>
#include <vector>

int main()
{

    /*入力エリア*/
    int S, A, B, X;
    std::cin >> S >> A >> B >> X;

    /*実装エリア */
    std::vector<int> move(A + B);
    for (int i = 0; i < A; ++i)
    {
        move[i] = S;
    }
    for (int i = A; i < A + B; ++i)
    {
        move[i] = 0;
    }

    int result = 0;
    for (int i = 0; i < X; ++i)
    {
        result += move[i % (A + B)];
    }
    std::cout << result << std::endl;
    return 0;
}
