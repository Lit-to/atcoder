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
     * 特定の順番で並べ替える
     * @param target シャッフル対象
     * @param order シャッフル順序
     */
    void Place(std::vector<T> &target, std::vector<int64_t> order)
    {
        vector<int64_t> retVal(target.size());
        for (int64_t i = 0; i < target.size(); ++i)
        {
            retVal[i] = target[order[i]];
        }
        std::swap(target, retVal);
    }
    template <class T>
    /**
     * べくたーのシャッフルする
     * @param target シャッフル対象
     */
    void Shuffle(std::vector<T> &target)
    {
        std::vector<int64_t> rank;
        for (int64_t i = 0; i < target.size(); ++i)
        {
            rank.push_back(i);
        }
        std::shuffle(rank.begin(), rank.end(), this->m_generator);
        Place(target, rank);
        return target;
    }

private:
    std::mt19937 m_generator; //!< メルセンヌツイスタのジェネレータ
};
