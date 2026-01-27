// ABC442D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */
int main()
{
    int64_t N, Q;
    std::cin >> N >> Q;
    std::vector<int64_t> numbers(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> numbers[i];
    }
    std::vector<std::vector<int64_t>> QUERIES(Q);
    for (int64_t i = 0; i < Q; ++i)
    {
        int q;
        std::cin >> q;
        if (q == 1)
        {
            int x;
            std::cin >> x;
            --x;
            QUERIES[i].push_back(q);
            QUERIES[i].push_back(x);
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            l--;
            r--;
            QUERIES[i].push_back(q);
            QUERIES[i].push_back(l);
            QUERIES[i].push_back(r);
        }
    }

    std::vector<int64_t> prefixSum(0);
    prefixSum.push_back(0);
    for (int64_t i = 0; i < N; ++i)
    {
        prefixSum.push_back(prefixSum[i] + numbers[i]);
    }
    for (int64_t i = 0; i < Q; ++i)
    {
        if (QUERIES[i][0] == 1)
        {
            int64_t x = QUERIES[i][1];
            std::swap(numbers[x], numbers[x + 1]);
            prefixSum[x + 1] = prefixSum[x] + numbers[x];
        }
        else if (QUERIES[i][0] == 2)
        {
            int64_t l = QUERIES[i][1];
            int64_t r = QUERIES[i][2];
            std::cout << prefixSum[r + 1] - prefixSum[l] << std::endl;
        }
    }
}