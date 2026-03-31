#include "../cpp/SegmentTree.cpp"
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

/**
 *愚直セグメント木
 */

class nonSegTree
{
public:
    nonSegTree(std::vector<int64_t> &data, int64_t identityElement, std::function<int64_t(int64_t, int64_t)> eval)
    {
        m_dataSize = data.size();
        m_data.resize(m_dataSize, identityElement);
        for (int64_t i = 0; i < m_dataSize; ++i)
        {
            m_data[i] = data[i];
        }
        m_eval = eval;
        m_identityElement = identityElement;
    };
    int64_t getQuery(int l, int r)
    {
        int64_t result = m_identityElement;
        for (int64_t i = l; i < r; ++i)
        {
            result = m_eval(result, m_data[i]);
        }
        return result;
    }
    void updateQuery(int i, int64_t v)
    {
        m_data[i] = v;
    }
    void out()
    {
        for (int i = 0; i < m_dataSize; ++i)
        {
            std::cout << m_data[i] << ",";
        }
        std::cout << std::endl;
    }
    std::vector<int64_t> debug_getData()
    {
        return m_data;
    }

private:
    std::vector<int64_t> m_data;
    int m_dataSize;
    int64_t m_identityElement;
    std::function<int64_t(int64_t, int64_t)> m_eval;
};

bool testA(randomGenerator &ranGen)
{
    int64_t N = ranGen.generate(1, 100000);
    std::vector<int64_t> A(N);
    int64_t t = ranGen.generate(0, 1);
    for (int64_t i = 0; i < N; ++i)
    {
        A[i] = ranGen.generate(1, 1000000);
    }
    SegmentTree<int64_t> segTree(A, 0, [](int64_t u, int64_t v)
                                 { return u + v; });
    int64_t Q = ranGen.generate(1, 100000);
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t q = ranGen.generate(1, 3);
        if (q == 1)
        {
            // updateクエリ
            int64_t index = ranGen.generate(0, N);
            int64_t v = ranGen.generate(1, 100);
            segTree.updateQuery(index, v);
        }
        else
        {
            // getクエリ
            int64_t l = ranGen.generate(0, N);
            int64_t r = ranGen.generate(l, N);
            int64_t resultA = segTree.getQuery(l, r);
        }
    }
    return true;
}

bool testB(randomGenerator &ranGen)
{
    int64_t N = ranGen.generate(1, 100000);
    int64_t t = ranGen.generate(0, 1);
    SegmentTree<int64_t> segTree(N, 0, [](int64_t u, int64_t v)
                                 { return u + v; });
    int64_t Q = ranGen.generate(1, 100000);
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t q = ranGen.generate(1, 3);
        if (q == 1)
        {
            // updateクエリ
            int64_t index = ranGen.generate(0, N);
            int64_t v = ranGen.generate(1, 100);
            segTree.updateQuery(index, v);
        }
        else
        {
            // getクエリ
            int64_t l = ranGen.generate(0, N);
            int64_t r = ranGen.generate(l, N);
            int64_t resultA = segTree.getQuery(l, r);
        }
    }
    return true;
}

int main()
{
    randomGenerator ranGen;
    int64_t testAmount = 100;
    for (int64_t testI = 0; testI < testAmount; ++testI)
    {
        if (!testA(ranGen))
        {
            break;
        }
        if (!testB(ranGen))
        {
            break;
        }
    }
    std::cout << "OK!" << std::endl;
}