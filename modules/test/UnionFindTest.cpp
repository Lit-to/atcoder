#include "../cpp/UnionFind.cpp"
#include <atcoder/all>
#include <random>
#include <cassert>
#include <cstdint>
#include <iostream>
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> testDist(3, 5000);
    int64_t testCount = testDist(gen);
    for (int i = 0; i < testCount; ++i)
    {
        int64_t nodes = testDist(gen);
        std::uniform_int_distribution<> nodeDist(2, nodes - 1);
        std::uniform_int_distribution<> queryDist(0, 3);
        atcoder::dsu aclUF(nodes);
        UnionFind litUF(nodes);

        for (int j = 0; j < testDist(gen); ++j)
        {
            // std::cout << i << "-" << j << ": ";
            int64_t query = queryDist(gen);
            int64_t u = nodeDist(gen);
            int64_t v = nodeDist(gen);
            // std::cout << query << " " << u << " " << v;
            if (query == 0)
            {
                assert(aclUF.leader(u) == litUF.GetRoot(u));
                assert(aclUF.leader(v) == litUF.GetRoot(v));
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
                assert(parent == litUF.GetRoot(u));
                assert(parent == litUF.GetRoot(v));
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
