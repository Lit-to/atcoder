// ABC429A
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        if (i <= M)
        {
            std::cout << "OK" << std::endl;
        }
        else
        {
            std::cout << "Too Many Requests" << std::endl;
        }
    }

    return 0;
}
