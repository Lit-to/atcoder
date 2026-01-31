// ABC443D
// template
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

int solve()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> R(N);
    std::unordered_map<int64_t, std::unordered_set<int64_t>> place;
    int64_t cost = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> R[i];
        R[i] = N - R[i];
        place[R[i]].insert(i);
    }
    for (int64_t i = N - 1; 0 <= i; --i)
    {
        for (int64_t j : place[i])
        {
            int64_t pos = j;
            if (0 <= pos - 1)
            {
                int64_t c = (i - 1) - R[pos - 1];
                if (0 < c)
                {
                    cost += c;
                    place[i - 1].insert(pos - 1);
                    R[pos - 1] = i - 1;
                }
            }
            if (pos + 1 < N)
            {
                int64_t c = (i - 1) - R[pos + 1];
                if (0 <= c)
                {
                    cost += c;
                    place[i - 1].insert(pos + 1);
                    R[pos + 1] = i - 1;
                }
            }
        }
    }
    std::cout << cost << std::endl;
    return 0;
}

int main()
{
    int64_t T;
    std::cin >> T;
    for (int64_t t = 0; t < T; ++t)
    {
        solve();
    }
}