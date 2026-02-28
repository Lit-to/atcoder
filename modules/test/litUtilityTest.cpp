#include "../cpp/LitUtility.cpp"
int main()
{
    std::vector<int64_t> A(10);
    for (int i = 0; i < 10; ++i)
    {
        A[i] = 1;
    }
    std::cout << LitUtility::Factorial(5) << std::endl; // いつか書く
}