// ABC333E
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdint>
#include <unordered_map>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 全部拾って全モンスターを倒していいのであれば、HashMapにすべてを詰めて倒せばよい
 * ところが、倒した後不要だったポーションはそもそも拾う必要がなかったことになるので、そのようなインデックスを列挙したい
 *
 * # 入力
 * N(行数)
 * Ti 1or2 (ポーションorモンスター)
 * Xi 種類
 * 入力をNと二次元配列の{(T0,X0),(T1,X1)...}としてQUERIESを持つ
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 * 持っているポーション一覧HashMap potions(キー:int,値:queue)
 *
 * # 具体的なロジック
 * QUERIESを全部走る
 *  Tiが1のとき
 *    potions[Xi]にiの値をプッシュ
 *  Tiが2のとき
 *    potions[Xi]がなければ-1を出力してプログラムを終了
 *    potions[Xi]をポップ
 * usedPotionのint配列をN個作る&全部-1として初期化する
 * potionsのキーで走査
 *   potions[key]をすべてpop
 *   usedPotion[popしたもの]を0にする
 * potionCount = 0
 * maxPotionCount = 0
 * QUERIESを全部走る
 *  Tiが1のとき
 *    usedPotion[i]が-1なら
 *      potionCount++
 *      maxPotionCountの最大更新をする
 *      usedPotion[i]を1にしておく
 *  Tiが2のとき
 *    potionCount--
 *
 * # 出力
 * maxPotionCountを出す
 * usedPotionを前から順に見る
 * 0<=usedPotion[i]のものを順吐き出す
 *
 */
int main()
{
    /*入力エリア*/
    int64_t N;
    std::cin >> N;
    std::unordered_map<int64_t, std::stack<int64_t>> potions(N);
    std::vector<std::vector<int64_t>> QUERIES(N);
    for (int i = 0; i < N; ++i)
    {
        int t, x;
        std::cin >> t >> x;
        QUERIES[i].push_back(t);
        QUERIES[i].push_back(x - 1);
    }
    /*実装エリア */
    for (int i = 0; i < N; ++i)
    {
        int Ti = QUERIES[i][0];
        int Xi = QUERIES[i][1];
        if (Ti == 1)
        {
            potions[Xi].push(i);
        }
        else if (Ti == 2)
        {
            if (potions[Xi].empty())
            {
                std::cout << -1 << std::endl;
                return 0;
            }
            potions[Xi].pop();
        }
    }
    std::vector<int64_t> usedPotion(N);
    for (int i = 0; i < N; ++i)
    {
        usedPotion[i] = -1;
    }
    for (int64_t i = 0; i < N; ++i)
    {
        while (!potions[i].empty())
        {
            usedPotion[potions[i].top()] = 0;
            potions[i].pop();
        }
    }
    int64_t potionCount = 0;
    int64_t maxPotionCount = 0;
    for (int64_t i = 0; i < N; ++i)
    {
        if (QUERIES[i][0] == 1)
        {
            if (usedPotion[i] != 0)
            {
                ++potionCount;
                maxPotionCount = std::max(maxPotionCount, potionCount);
                usedPotion[i] = 1;
            }
        }
        else
        {
            --potionCount;
        }
    }
    // 出力
    std::cout << maxPotionCount << std::endl;
    for (int i = 0; i < N; ++i)
    {
        if (0 <= usedPotion[i])
        {
            std::cout << usedPotion[i] << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}