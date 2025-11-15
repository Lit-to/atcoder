// ABC432A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{

    /*入力エリア*/
    int A, B, C;
    // std::cin >> A >> B >> C;

    std::vector<int> digits(3);
    for (int i = 0; i < 3; ++i)
    {
        std::cin >> digits[i];
    }
    std::sort(digits.begin(), digits.end(), std::greater<int>());

    for (int i = 0; i < 3; ++i)
    {
        std::cout << digits[i];
    }
    /*実装エリア */
    std::cout << std::endl;
    return 0;
}
