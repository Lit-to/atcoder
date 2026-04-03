#include <random>

/**
 * 乱数生成ラッパ
 * 最初にコンストラクタを読んだら以降はgenerate関数1回でてきとうな整数が返ってくる
 */
class randomGenerator
{
public:
    /**
     * コンストラクタ
     */
    randomGenerator() : m_generator(std::random_device{}()) {}
    /**
     * @brief 値から乱数生成関数(半開区間)
     * @param min 最小値
     * @param max 最大値
     */
    int64_t generate(int64_t min, int64_t max)
    {
        std::uniform_int_distribution<> dist(min, max - 1);
        return dist(m_generator);
    }
    /**
     * @brief 範囲から乱数生成関数(半開区間)
     * @param range {最小値,最大値}
     */
    template <size_t N>
    int64_t generate(int64_t (&range)[N])
    {
        return generate(range[0], range[1]);
    }

private:
    std::mt19937 m_generator; //!< メルセンヌツイスタのジェネレータ
};
