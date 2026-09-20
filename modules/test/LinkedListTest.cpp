#include <iostream>
#include "../cpp/RandomGenerator.cpp"
#include "../cpp/LinkedList.cpp"
#include <list>

bool isEqual(std::list<int64_t> &stdList, LinkedList<int64_t> customList)
{
    int64_t n = stdList.size();
    if (n != customList.GetSize())
    {
        std::cout << "NG:Size" << std::endl;
        return false;
    }
    auto customItr = customList.begin();
    for (auto stdItr = stdList.begin(); stdItr != stdList.end(); ++stdItr)
    {
        if (*stdItr != *customItr)
        {
            return false;
        }
        ++customItr;
    }
    return true;
}

int main()
{
    // === テストパラメータ === //
    const int64_t N_MAX = 9999;
    const int64_t V_MAX = 999999;
    const int64_t TEST_COUNT = 100;
    const int64_t TASK_COUNT = 100;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //
    int64_t test = 0;
    while (test < TEST_COUNT)
    {
        const int64_t N = rand.Generate(1, N_MAX);
        LinkedList<int64_t> customList(N);
        std::list<int64_t> stdList(N);
        for (int64_t task = 0; task < TASK_COUNT; ++task)
        {
            auto query = rand.Generate(0, 4);
            if (query == 0)
            {
                // 値挿入(PushBack)
                int64_t v = rand.Generate(0, V_MAX);
                stdList.push_back(v);
                customList.PushBack(v);
            }
            else if (query == 1)
            {
                // 値挿入(PushFront)
                int64_t v = rand.Generate(0, V_MAX);
                customList.PushFront(v);
                stdList.push_front(v);
            }
            else if (query == 2)
            {
                // 値削除(PopBack)
                if (customList.IsEmpty())
                {
                    customList.PopBack();
                    stdList.pop_back();
                }
            }
            else if (query == 3)
            {
                // 値削除(PopFront)
                if (customList.IsEmpty())
                {
                    for (int64_t i = 0; i < N; ++i)
                    {
                        customList.PopFront();
                        stdList.pop_front();
                    }
                }
            }
            else
            {
                // 全部チェック
                // 空チェック
                if (customList.IsEmpty() != stdList.empty())
                {
                    std::cout << "NG:IsEmpty" << std::endl;
                }
                // 空チェック
                if (customList.GetSize() != stdList.size())
                {
                    std::cout << "NG:Size:true" << std::endl;
                }
                // 値一致
                if (!isEqual(stdList, customList))
                {
                    std::cout << "NG:Values" << std::endl;
                }
            }
        }
        customList.Clear();
        stdList.clear();
        if (!isEqual(stdList, customList))
        {
            std::cout << "NG:Clear" << std::endl;
        }
        ++test;
    }
    std::cout << "OK!" << std::endl;
}