// AWC0017D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/
/**
 * 値と桁数からビット列を生成する。
 * e.g.,(5,3) -> {true,false,true}
 */
std::vector<bool> GenerateBit(int64_t value, const int64_t digits)
{
    std::vector<bool> result(digits);
    for (int64_t i = 0; i < digits; ++i)
    {
        result[digits - i - 1] = (value & 1);
        value >>= 1;
    }
    ++value;
    return result;
}
int64_t convertId(int64_t u, int64_t v, int64_t m)
{
    return u * m + v;
}
int main()
{
    int64_t N, M, K;
    std::cin >> N >> M >> K;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    std::unordered_map<int64_t, int64_t> PAIRS;
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v, b;
        std::cin >> u >> v >> b;
        --u;
        --v;
        PAIRS[convertId(u, v, N)] = b;
    }
    int64_t ans = INT64_MIN;
    for (int64_t i = 0; i < (1 << (N + 1)); ++i)
    {
        std::vector<bool> bits = GenerateBit(i, N);
        std::vector<int64_t> person;
        for (int64_t j = N - 1; 0 <= j; --j)
        {
            if (bits[j])
            {
                person.push_back(j);
            }
        }
        std::reverse(person.begin(), person.end());
        if (person.size() != K)
        {
            continue;
        }
        int64_t result = 0;
        for (int64_t &j : person)
        {
            result += A[j];
        }
        // std::cerr << result << " ";
        for (int64_t j = 0; j < K; ++j)
        {
            for (int64_t k = j + 1; k < K; ++k)
            {
                result -= PAIRS[convertId(person[j], person[k], N)];
            }
        }
        // std::cerr << result << std::endl;
        ans = std::max(result, ans);
    }
    std::cout << ans << std::endl;
}