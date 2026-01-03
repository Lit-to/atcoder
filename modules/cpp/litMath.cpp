#include <cstdint>
int64_t permutation(int64_t n, int64_t r)
{
    int64_t result = 1;
    for (int64_t i = n; n - r < i; --i)
    {
        result *= i;
    }
    return result;
}
int64_t permutation(int64_t n)
{
    return permutation(n, n);
}
int64_t combination(int64_t n, int64_t r)
{
    return permutation(n, r) / permutation(r);
}