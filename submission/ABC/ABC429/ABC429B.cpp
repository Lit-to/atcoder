// ABC429B
#include <iostream>
#include <string>
#include <vector>

int main()
{

    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        result += A[i];
    }

    for (int i = 0; i < N; ++i)
    {
        if (result - A[i] == M)
        {
            std::cout << "Yes";
            return 0;
        }
    }
    std::cout << "No";
    return 0;
}
