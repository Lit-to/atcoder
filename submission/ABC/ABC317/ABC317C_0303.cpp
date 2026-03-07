// ABC317C
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
struct street
{
    int64_t to;
    int64_t distance;
};
int64_t ans;

void dfs(int64_t pos, int64_t cost, const std::vector<std::vector<street>> &GRAPH, std::vector<int64_t> &PATH, std::vector<bool> &done)
{
    if (done[pos])
    {
        return;
    }
    for (const street &i : GRAPH[pos])
    {
        if (done[i.to])
        {
            continue;
        }
        done[pos] = true;
        dfs(i.to, cost + PATH[i.distance], GRAPH, PATH, done);
        done[pos] = false;
    }
    ans = std::max(ans, cost);
}

int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::vector<street>> GRAPH(N);
    std::vector<int64_t> PATH(M);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t a, b, c;
        std::cin >> a >> b >> c;
        GRAPH[a - 1].push_back(street{.to = b - 1, .distance = i});
        GRAPH[b - 1].push_back(street{.to = a - 1, .distance = i});
        PATH[i] = c;
    }
    ans = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        std::vector<bool> done(N);
        dfs(i, 0, GRAPH, PATH, done);
    }
    std::cout << ans << std::endl;
}