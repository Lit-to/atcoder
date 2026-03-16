// ABC398C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

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
    int64_t N, K;
    std::cin >> N >> K;
    struct MEDICINE
    {
        int64_t duration;
        int64_t count;
        const bool operator<(const MEDICINE &rhs)
        {
            return duration < rhs.duration || duration == rhs.duration && count < rhs.count;
        }
    };
    std::vector<MEDICINE> medicines(N);
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t a;
        int64_t b;
        std::cin >> a >> b;
        medicines[i] = MEDICINE{.duration = a, .count = b};
    }
    std::sort(medicines.begin(), medicines.end());
    int64_t all = 0;
    for (int64_t i = 0; i < medicines.size(); ++i)
    {
        all += medicines[i].count;
    }
    int64_t i = 0;
    int64_t day = 0;
    while (K < all)
    {
        day = medicines[i].duration;
        all -= medicines[i].count;
        ++i;
    }
    std::cout << day + 1 << std::endl;
}