#include <random>

/**
 * 乱数生成ラッパ
 * 最初にコンストラクタを読んだら以降はGenerate関数1回でてきとうな整数が返ってくる
 */
class randomGenerator
{
public:
    /**
     * コンストラクタ
     */
    randomGenerator() : m_generator(std::random_device{}()) {}
    /**
     * @brief 値から乱数生成関数
     * @param min 最小値
     * @param max 最大値
     */
    int64_t Generate(int64_t min, int64_t max)
    {
        std::uniform_int_distribution<> dist(min, max);
        return dist(m_generator);
    }
    /**
     * @brief 範囲から乱数生成関数
     * @param range {最小値,最大値}
     */
    template <size_t N>
    int64_t Generate(int64_t (&range)[N])
    {
        return Generate(range[0], range[1]);
    }

    template <class T>
    /**
     * べくたーのシャッフルする
     * @param target シャッフル対象
     */
    void Shuffle(std::vector<T> &target)
    {
        struct TOKEN
        {
            int64_t index;
            int64_t value;
            bool operator<(const TOKEN &target) const
            {
                return value < target.value;
            }
        };
        std::vector<TOKEN> order;
        for (int64_t i = 0; i < target.size(); ++i)
        {
            order.push_back(TOKEN{.index = i, value = this->Generate(0, (target.size() - 1) * 100000)});
        }
        std::sort(all(value));
        vector<int64_t> retVal;
        for (int64_t i = 0; i < order.size(); ++i)
        {
            retVal.push_back(target[order[i].index]);
        }
        return retVal;
    }

private:
    std::mt19937 m_generator; //!< メルセンヌツイスタのジェネレータ
};
