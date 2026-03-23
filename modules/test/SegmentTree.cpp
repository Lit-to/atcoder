#include "../../dev/segmentTree.cpp"
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
     * 乱数生成関数(半開区間)
     * @param min 最小値
     * @param max 最大値
     */
    int64_t generate(int64_t min, int64_t max)
    {
        std::uniform_int_distribution<> dist(min, max - 1);
        return dist(m_generator);
    }

private:
    std::mt19937 m_generator; //!< メルセンヌツイスタのジェネレータ
};
void test(randomGenerator &ranGen)
{
    int64_t N = ranGen.generate(1, 100000);
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        A[i] = ranGen.generate(1, 100000000);
    }
}
int main()
{
    randomGenerator ranGen;
    int64_t testAmount = 5000;
    for (int64_t testI = 0; testI < testAmount; ++testI)
    {
        test(ranGen);
    }
}