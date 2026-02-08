// ABC356C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 * bit全探索
 * 2^Nの鍵が正しいかそうでないかの全通りを列挙する
 * すべての鍵を持って与えられたテストがすべて通るかどうかをチェックし、通れば組み合わせとして加算する
 * # 具体的なロジック
 * 入力を受け取る
 *
 * テストロジック(鍵の有効/無効を表すvector)
 *   テストを前から順に行う
 *   使う鍵一覧を前から見て、有効な本数がK本超えていたら開いたとみなす
 *   この結果がRiと一致してるかを確認する
 * すべてがRiと一致していたらtrueを返す
 *
 *
 *
 *
 *
 */

#include <vector>
#include <cstdint>
#include <iostream>

/**
 * @brief りっとー便利ツール詰め合わせ
 * @details 状態を持たない関数のうち、ひとまとめにするほど規模の大きくないこまごまとした関数を置く
 */
namespace litUtility
{
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
}

struct task
{
    int64_t keyCount;
    std::vector<int> keys;
    int64_t isOpened;
};
std::vector<task> TASKS;
int K;
bool doTest(std::vector<bool> &keys)
{
    for (int64_t i = 0; i < TASKS.size(); ++i)
    {
        int trueKeyCount = 0;
        for (int j = 0; j < TASKS[i].keyCount; ++j)
        {
            int usedKey = TASKS[i].keys[j];
            trueKeyCount += (keys[usedKey] == 1);
        }
        if (TASKS[i].isOpened == (K <= trueKeyCount))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{

    int64_t N, M;
    std::cin >> N >> M >> K;
    for (int64_t i = 0; i < M; ++i)
    {
        int c;
        std::cin >> c;
        std::vector<int> keys(c);
        for (int j = 0; j < c; ++j)
        {
            std::cin >> keys[j];
            --keys[j];
        }
        char r;
        std::cin >> r;
        TASKS.push_back(task{.keyCount = c, .keys = keys, .isOpened = (r == 'o')});
    }
    int64_t result = 0;
    int64_t bit = 0;
    while (bit < (1 << N))
    {

        ++bit;
        std::vector<bool> keys = litUtility::GenerateBit(bit, N);
        result += doTest(keys);
    }
    std::cout << result << std::endl;
}