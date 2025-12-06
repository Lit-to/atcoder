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

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    int power = 0;
    int result = N;
    for (int i = 0; i < N; ++i)
    {
        if (power < A[i])
        {
            power = A[i];
        }
        --power;
        if (power == 0)
        {
            result = i + 1;
            break;
        }
    }
    std::cout << result << std::endl;
    return 0;

    /*実装エリア */
}