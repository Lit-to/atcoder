// ABC437B
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

int main()
{

    /*入力エリア*/
    int N;
    int H;
    int W;
    std::cin >> H >> W >> N;

    std::vector<std::vector<int>> A(H);
    for (int i = 0; i < H; ++i)
    {
        A[i].resize(W);
        for (int j = 0; j < W; ++j)
        {
            std::cin >> A[i][j];
        }
    }
    std::vector<int> B(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> B[i];
    }
    std::vector<int> count(H + 1);
    for (int i = 0; i < N; ++i)
    {
        for (int h = 0; h < H; ++h)
        {
            for (int w = 0; w < W; ++w)
            {
                count[h] += B[i] == A[h][w];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < H; ++i)
    {
        if (result < count[i])
        {
            result = count[i];
        }
    }
    std::cout << result << std::endl;

    /*実装エリア */

    return 0;
}