// ABC433B
#include <iostream>
#include <string>
#include <vector>

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
    /*実装エリア */
    for (int i = 0; i < N; ++i)
    {
        bool isResolved = false;
        for (int j = i; 0 <= j; --j)
        {
            if (A[i] < A[j])
            {
                std::cout << j + 1 << std::endl;
                isResolved = true;
                break;
            }
        }
        if (isResolved)
        {
            continue;
        }
        else
        {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}
