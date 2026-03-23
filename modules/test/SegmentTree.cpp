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

/**
 *愚直セグメント木
 */

class nonSegTree
{
public:
    nonSegTree(std::vector<int64_t> data, int64_t identityElement, std::function<int64_t(int64_t, int64_t)> eval)
    {
        m_dataSize = data.size();
        // m_height = 0; // テストしないため無視
        // m_memorySize = ((m_height + 1) * 2) << 1;
        m_data.resize(m_dataSize, identityElement);
        // m_identityElement = identityElement;
        // m_eval = eval;
        // for (int64_t i = 0; i < m_dataSize; ++i)
        // {
        //     m_data[i + m_memorySize / 2] = data[i];
        // }
        for (int64_t i = 0; i < m_dataSize; ++i)
        {
            m_data[i] = data[i];
        }
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

private:
    std::vector<int64_t> m_data;
    int m_dataSize;
    int64_t m_identityElement;
    std::function<int64_t(int64_t, int64_t)> m_eval;
};

void test(randomGenerator &ranGen)
{
    int64_t N = ranGen.generate(1, 100000);
    std::vector<int64_t> A(N);
    for (int64_t i = 0; i < N; ++i)
    {
        A[i] = ranGen.generate(1, 100000000);
    }
    SegmentTree segTree(A, -1, [&](int64_t u, int64_t v)
                        { return std::max(u, v); });
    nonSegTree nonSegTree(A, -1, [&](int64_t u, int64_t v)
                          { return std::max(u, v); });
    int64_t Q = ranGen.generate(1, 100000);
    int64_t q = ranGen.generate(1, 3);
    if (q == 1)
    {
        // updateクエリ
        int64_t v = ranGen.generate(1, 100000000);
        int64_t i = ranGen.generate(0, N);
        segTree.updateQuery(i, v);
        nonSegTree.updateQuery(i, v);
    }
    else
    {
        // getクエリ
        int64_t l = ranGen.generate(0, N - 1);
        int64_t r = ranGen.generate(l + 1, N);
        int64_t resultA = segTree.getQuery(l, r);
        int64_t resultB = nonSegTree.getQuery(l, r);
        if (resultA != resultB)
        {
            std::cout << " <<< NG" << std::endl;
        }
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