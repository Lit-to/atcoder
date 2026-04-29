#include "../cpp/UnionFind.cpp"
#include <atcoder/all>
#include <cassert>
#include <cstdint>
#include <iostream>
#include "../cpp/RandomGenerator.cpp"

int main()
{
    //====テスト定数====//
    randomGenerator rg;
    int64_t TEST_COUNT = 100;
    int64_t QUERY_COUNT_RANGE[2] = {1, 101};
    int64_t QUERY_RANGE[2] = {1, 4};
    //====テスト定数====//
    for (int i = 0; i < TEST_COUNT; ++i)
    {
        int64_t nodes = rg.Generate(1, 200000);
        atcoder::dsu aclUF(nodes);
        UnionFind litUF(nodes);

        for (int j = 0; j < rg.Generate(QUERY_COUNT_RANGE); ++j)
        {
            int64_t query = rg.Generate(QUERY_RANGE);
            int64_t u = rg.Generate(1, nodes);
            int64_t v = rg.Generate(1, nodes);
            if (query == 0)
            {
                assert(aclUF.leader(u) == litUF.FetchRoot(u));
                assert(aclUF.leader(v) == litUF.FetchRoot(v));
            }
            else if (query == 1)
            {
                assert(aclUF.same(u, v) == litUF.IsSameRoot(u, v));
            }
            else if (query == 2)
            {
                int64_t parent = aclUF.merge(u, v);
                litUF.Unite(u, v);
                assert(aclUF.same(u, v) == litUF.IsSameRoot(u, v));
                assert(parent == litUF.FetchRoot(u));
                assert(parent == litUF.FetchRoot(v));
            }
            else if (query == 3)
            {
                assert(aclUF.size(u) == litUF.GetGroupSize(u));
                assert(aclUF.size(v) == litUF.GetGroupSize(v));
                assert(aclUF.groups().size() == litUF.GetRootCount());
            }
        }
    }
    std::cout << "OK!" << std::endl;
    return 0;
}
