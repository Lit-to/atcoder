// ABC343D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */

int main()
{
    int64_t N, T;
    std::cin >> N >> T;
    std::vector<std::vector<int64_t>> QUERIES(T);
    for (int64_t i = 0; i < T; ++i)
    {
        std::vector<int64_t> line(2);
        std::cin >> line[0] >> line[1];
        --line[0];
        QUERIES[i] = line;
    }
    std::unordered_map<int64_t, int64_t> numMap;
    numMap[0] = N;
    std::vector<int64_t> playerMap(N);
    for (int64_t i = 0; i < QUERIES.size(); ++i)
    {
        --numMap[playerMap[QUERIES[i][0]]];
        if (numMap[playerMap[QUERIES[i][0]]] == 0)
        {
            numMap.erase(playerMap[QUERIES[i][0]]);
        }
        playerMap[QUERIES[i][0]] += QUERIES[i][1];
        ++numMap[playerMap[QUERIES[i][0]]];
        std::cout << numMap.size() << std::endl;
    }
}