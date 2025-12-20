// ABC437C
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

    int H;
    int W;
    std::cin >> H >> W;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::string S;
    std::cin >> S;

    std::cout << S << std::endl;

    /*実装エリア */

    return 0;
}