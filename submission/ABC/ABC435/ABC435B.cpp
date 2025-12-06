// ABC435B
// template
#include <iostream>
#include <string>
#include <vector>
int sum(int l, int r, std::vector<int> a)
{
    int result = 0;
    for (int i = l; i < r; ++i)
    {
        result += a.at(i);
    }
    return result;
}
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
    int result = 0;
    for (int l = 0; l < N; ++l)
    {
        for (int r = l; r < N; ++r)
        {
            for (int i = l; i <= r; ++i)
            {
                int s = sum(l, r + 1, A);
                if ((s % A[i]) == 0)
                {
                    break;
                }
                else
                {
                    if (i == r)
                    {
                        ++result;
                    }
                }
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}
