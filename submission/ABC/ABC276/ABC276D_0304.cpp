// ABC276D
// もしゃ！
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    int g = 0;
    for (int i = 0; i < N; ++i)
    {
        g = std::gcd(g, A[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        A[i] /= g;
        while (A[i] % 2 == 0)
        {
            A[i] /= 2;
            ++ans;
        }
        while (A[i] % 3 == 0)
        {
            A[i] /= 3;
            ++ans;
        }
        if (A[i] != 1)
        {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}