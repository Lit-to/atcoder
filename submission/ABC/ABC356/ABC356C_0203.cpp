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

class BitManager
{
public:
    BitManager(int64_t digits)
    {
        m_max = 1 << digits;
        m_digits = digits;
        m_value = 0;
    }
    std::vector<int> next()
    {
        int64_t value = m_value;
        std::vector<int> result(m_digits);
        for (int64_t i = 0; i < m_digits; ++i)
        {
            result[m_digits - i - 1] = (value & 1);
            value >>= 1;
        }
        ++m_value;
        return result;
    }
    bool isFinished()
    {
        return m_max <= m_value;
    }
    int64_t m_max;
    int64_t m_value;
    int64_t m_digits;
};

struct task
{
    int64_t keyCount;
    std::vector<int> keys;
    int64_t isOpened;
};
std::vector<task> TASKS;
int K;
bool doTest(std::vector<int> &keys)
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
    // BitManager bm = BitManager(3);
    // for (int i = 0; i < 10; ++i)
    // {
    //     std::vector<int> contents = bm.next();
    //     for (int j = 0; j < contents.size(); ++j)
    //     {
    //         std::cout << contents[j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
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
    BitManager bm = BitManager(N);
    int64_t result = 0;
    while (!bm.isFinished())
    {
        std::vector<int> keys = bm.next();
        // for (int j = 0; j < keys.size(); ++j)
        // {
        //     std::cout << keys[j] << " ";
        // }
        // std::cout << std::endl;
        result += doTest(keys);
    }
    std::cout << result << std::endl;
}