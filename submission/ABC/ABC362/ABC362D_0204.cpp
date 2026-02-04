// ABC362D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <queue>
#include <unordered_set>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 頂点1から全頂点が探索済みになるまでダイクストラ
 * # 具体的なロジック
 * キューを作る
 * hashSetに訪問済み管理をする
 * hashSetの中身がN個になるまで以下繰り返す
 *     キューの先頭を吐き出す
 *     この頂点を訪問済みsetに追加
 *     重みを答え配列の頂点番号に入れる
 *     キューのキューの示す頂点から次の頂点を列挙する
 *     キューに頂点とその頂点に行くまでのコスト(現在までの重み+パス上の重み+行先頂点重み)を入れる
 * 答え配列を頂点0を除いて前から順に吐き出す
 *
 *
 */

int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }
    struct node
    {
        int64_t m_to;
        int64_t m_cost;
        bool operator>(const node &rhs) const
        {
            return m_cost > rhs.m_cost;
        };
    };
    std::vector<std::vector<node>> GRAPH(N);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t u, v, b;
        std::cin >> u >> v >> b;
        GRAPH[u - 1].push_back(node{.m_to = v - 1, .m_cost = b});
        GRAPH[v - 1].push_back(node{.m_to = u - 1, .m_cost = b});
    }
    std::priority_queue<node, std::vector<node>, std::greater<node>> pq;
    pq.push(node{.m_to = 0, .m_cost = 0});
    std::vector<int64_t> result(N, INT64_MAX);
    result[0] = 0;
    while (0 < pq.size())
    {
        node pos = pq.top();
        pq.pop();
        if (result[pos.m_to] < pos.m_cost)
        {
            continue;
        }
        for (node &i : GRAPH[pos.m_to])
        {
            int64_t newCost = pos.m_cost + i.m_cost + A[i.m_to];
            if (newCost < result[i.m_to])
            {
                result[i.m_to] = newCost;
                pq.push(node{.m_to = i.m_to, .m_cost = newCost});
            };
        }
    }
    for (int64_t i = 1; i < N; ++i)
    {
        std::cout << result[i] + A[0] << " ";
    }
    std::cout << std::endl;
    return 0;
}