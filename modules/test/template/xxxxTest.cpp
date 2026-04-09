#include <iostream>
#include "../cpp/RandomGenerator.cpp"
// #include "../cpp/xxxxx.cpp"

int main()
{
    // === テストパラメータ === //
    const int64_t N_MAX = 999999;
    const int64_t V_MAX = 99999999;
    const int64_t TEST_COUNT = 100;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //
    int64_t test = 0;
    while (test < TEST_COUNT)
    {
        ++test;
    }
    std::cout << "OK!" << std::endl;
}