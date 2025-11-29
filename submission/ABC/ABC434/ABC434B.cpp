// ABC434B
// template
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main()
{

    /*入力エリア*/
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> birdsSize(M);
    std::vector<int> birdsCount(M);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i] >> B[i];
    }
    std::cerr << "___" << std::endl;

    for (int i = 0; i < N; ++i)
    {
        ++birdsCount[A[i] - 1];
        birdsSize[A[i] - 1] += B[i];
    }
    for (int i = 0; i < M; ++i)
    {
        double size = static_cast<double>(birdsSize[i]);
        double count = static_cast<double>(birdsCount[i]);
        double ans = (size / count);
        std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
    }

    /*実装エリア */

    return 0;
}