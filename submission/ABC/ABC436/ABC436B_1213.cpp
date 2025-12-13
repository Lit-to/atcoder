// ABC436B
// template
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdint>

int main()
{

    /*入力エリア*/
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> BOARD(N);

    /*実装エリア */
    for (int i = 0; i < N; ++i)
    {
        std::vector<int> line(N);
        for (int j = 0; j < N; ++j)
        {
            line[j] = 0;
        }
        BOARD[i] = line;
    }
    int k = 0;
    int r = 0;
    int c = (N - 1) / 2;
    BOARD[r][c] = ++k;

    for (int i = 0; i < std::pow(N, 2) - 1; ++i)
    {
        int candR_A = (r - 1 + N) % N;
        int candC_A = (c + 1) % N;
        int candR_B = (r + 1) % N;
        int candC_B = c;
        if (0 <= candR_A && BOARD[candR_A][candC_A] == 0)
        {
            BOARD[candR_A][candC_A] = ++k;
            r = candR_A;
            c = candC_A;
        }
        else
        {
            BOARD[candR_B][candC_B] = ++k;
            r = candR_B;
            c = candC_B;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << BOARD[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
    return 0;
}