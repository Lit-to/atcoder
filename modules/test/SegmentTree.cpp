#include "../cpp/SegmentTree.cpp"
#include "../cpp/RandomGenerator.cpp"

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
    int64_t N = ranGen.Generate(1, 100000);
    std::vector<int64_t> A(N);
    int64_t t = ranGen.Generate(0, 1);
    for (int64_t i = 0; i < N; ++i)
    {
        A[i] = ranGen.Generate(1, 1000000);
    }
    SegmentTree<int64_t> segTree(A, 0, [](int64_t u, int64_t v)
                                 { return u + v; });
    int64_t Q = ranGen.Generate(1, 100000);
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t q = ranGen.Generate(1, 3);
        if (q == 1)
        {
            // updateクエリ
            int64_t index = ranGen.Generate(0, N);
            int64_t v = ranGen.Generate(1, 100);
            segTree.updateQuery(index, v);
        }
        else
        {
            // getクエリ
            int64_t l = ranGen.Generate(0, N);
            int64_t r = ranGen.Generate(l, N);
            int64_t resultA = segTree.getQuery(l, r);
        }
    }
    return true;
}

bool testB(randomGenerator &ranGen)
{
    int64_t N = ranGen.Generate(1, 100000);
    int64_t t = ranGen.Generate(0, 1);
    SegmentTree<int64_t> segTree(N, 0, [](int64_t u, int64_t v)
                                 { return u + v; });
    int64_t Q = ranGen.Generate(1, 100000);
    for (int64_t i = 0; i < Q; ++i)
    {
        int64_t q = ranGen.Generate(1, 3);
        if (q == 1)
        {
            // updateクエリ
            int64_t index = ranGen.Generate(0, N);
            int64_t v = ranGen.Generate(1, 100);
            segTree.updateQuery(index, v);
        }
        else
        {
            // getクエリ
            int64_t l = ranGen.Generate(0, N);
            int64_t r = ranGen.Generate(l, N);
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