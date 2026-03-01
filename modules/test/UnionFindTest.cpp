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
    std::uniform_int_distribution<> testDist(3, 100);
    for (int i = 0; i < 100; ++i)
    {
        int64_t nodes = testDist(gen);
        std::uniform_int_distribution<> nodeDist(2, nodes - 1);
        atcoder::dsu aclUF(nodes);
        UnionFind litUF(nodes);
        for (int j = 0; j < nodeDist(gen); ++j)
        {
            int64_t u = nodeDist(gen);
            int64_t v = nodeDist(gen);
            assert(aclUF.leader(u) == litUF.GetRoot(u));
            assert(aclUF.leader(v) == litUF.GetRoot(v));
            assert(aclUF.same(u, v) == litUF.IsSameRoot(u, v));
            int64_t parent = aclUF.merge(u, v);
            litUF.Unite(u, v);
            assert(aclUF.same(u, v) == litUF.IsSameRoot(u, v));
            assert(parent == litUF.GetRoot(u));
            assert(parent == litUF.GetRoot(v));
            assert(aclUF.size(u) == litUF.GetGroupSize(u));
            assert(aclUF.size(v) == litUF.GetGroupSize(v));
            assert(aclUF.groups().size() == litUF.GetRootCount());
        }
    }
    std::cout << "OK!" << std::endl;
    return 0;
}
