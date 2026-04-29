// TESOK001O
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//

class LitUtility
{
public:
    static int64_t calcGCD(int64_t A, int64_t B)
    {
        if (A < B)
        {
            std::swap(A, B);
        }
        while (A % B != 0)
        {
            int64_t temp = A % B;
            A = temp;
            if (A < B)
            {
                std::swap(A, B);
            }
        }
        return B;
    }
};

using Lit = LitUtility;
int main()
{
    int64_t A, B;
    std::cin >> A >> B;
    std::cout << Lit::calcGCD(A, B) << std::endl;
}

//======================
/**
 *方針メモ欄
 *
 */
//======================