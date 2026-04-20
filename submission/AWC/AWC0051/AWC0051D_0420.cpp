// AWC0051D
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
//

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    int64_t N, M, K, T;
    std::cin >> N >> M >> K >> T;
    /**
     * @brief グラフの辺情報
     */
    struct EDGE
    {
        int64_t distination; // 隣の行先ノード
        int64_t cost;        // そのノードに行くコスト
    };
    std::vector<std::vector<EDGE>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v, w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        GRAPH[u].push_back(EDGE{.distination = v, .cost = w});
        GRAPH[v].push_back(EDGE{.distination = u, .cost = w});
    }
    std::vector<int64_t> penaltyNode(N);
    std::vector<int64_t> G(K);
    for (int64_t i = 0; i < K; ++i)
    {
        std::cin >> G[i];
        --G[i];
        penaltyNode[G[i]] += T;
    }
    struct node
    {
        int64_t pos;
        int64_t cost;
        /**
         * ソート用の比較関数
         */
        bool operator>(const node &target) const
        {
            return cost > target.cost;
        }
    };
    greater_priority_queue<node> gqp;
    gqp.push(node{.pos = 0, .cost = penaltyNode[0]});
    std::vector<int64_t> costs(N, INT64_MAX);
    costs[0] = penaltyNode[0];
    std::vector<bool> done(N);
    while (!gqp.empty())
    {
        node task = gqp.top();
        gqp.pop();
        if (done[task.pos])
        {
            continue;
        }
        done[task.pos] = true;
        for (int64_t i = 0; i < GRAPH[task.pos].size(); ++i)
        {
            EDGE edge = GRAPH[task.pos][i];
            costs[edge.distination] = std::min(costs[task.pos] + edge.cost + penaltyNode[edge.distination], costs[edge.distination]);
            gqp.push(node{.pos = edge.distination, .cost = costs[edge.distination]});
        }
    }
    std::cout << costs[N - 1] << std::endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    int64_t TESTCASES = 1;

    // std::cin >> TESTCASES;

    for (int64_t i = 0; i < TESTCASES; ++i)
    {
        solve();
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================