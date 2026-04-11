#include <algorithm>
#include "../cpp/RandomGenerator.cpp"
#include "../cpp/LitUtility.cpp"

bool SearchTest(int64_t testCount)
{
    // === テストパラメータ === //
    int64_t N_MAX = 999999;
    int64_t VALUE_MAX = 999999999;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //
    for (int64_t i = 0; i < testCount; ++i)
    {
        int64_t n = rand.Generate(1, N_MAX);
        std::vector<int64_t> A(n);
        for (int64_t i = 0; i < n; ++i)
        {
            A[i] = rand.Generate(1, VALUE_MAX);
        }
        std::sort(A.begin(), A.end());
        int64_t v = rand.Generate(1, VALUE_MAX);
        int64_t simpleResult = -1;
        for (int64_t i = 0; i < n; ++i)
        {
            if (A[i] == v)
            {
                simpleResult = i;
                break;
            }
        }
        int64_t searchResult = -1;
        int64_t searchIndex = Lit::Search(0, n, [&](int64_t index)
                                          { return A[index] <= v; });
        if (0 <= searchIndex && searchIndex < n && A[searchIndex] == v)
        {
            searchResult = searchIndex;
        }
        if (simpleResult != searchResult)
        {
            return false;
        }
    }
    return true;
}

bool GenerateBitTest(int64_t testCount)
{
    // === テストパラメータ === //
    int64_t BIT_MAX = 31;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //

    for (int64_t i = 0; i < testCount; ++i)
    {
        int64_t bit = rand.Generate(1, BIT_MAX);
        int64_t value = rand.Generate(0, (1LL << bit));
        std::vector<bool> result = Lit::GenerateBit(value, bit + 1);
        std::reverse(result.begin(), result.end());
        int64_t num = 0;
        for (int64_t i = 0; i < bit; ++i)
        {
            if (result[i])
            {
                num += 1 << i;
            }
        }

        if (result.size() != bit + 1 || num != value)
        {
            return false;
        }
    }
    return true;
}

template <class Func>
void DoTest(const std::string &name, Func f)
{
    std::cout << name << ": ";
    if (!f(200))
    {
        std::cout << ">>>>>>>NG" << std::endl;
    }
    else
    {
        std::cout << "OK!" << std::endl;
    }
}

int main()
{
    DoTest("SearchTest", SearchTest);
    DoTest("GenerateBitTest", GenerateBitTest);
}