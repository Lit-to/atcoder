#include <iostream>
#include "../cpp/RandomGenerator.cpp"
#include "../cpp/RunLengthCompression.cpp"

int main()
{
    // === テストパラメータ === //
    const int64_t N_MAX = 10000000;
    const int64_t TEST_COUNT = 100;
    const int64_t Q_TYPE = 2;
    const int64_t Q1_TOKEN_MAX_SIZE = 20;
    const int64_t Q1_TOKEN_MAX_COUNT = 100000;
    const int64_t Q2_STRING_MAX_SIZE = 1000000;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //
    int64_t test = 0;
    while (test < TEST_COUNT)
    {
        int q = rand.Generate(0, 2);
        if (q == 0)
        {
            // ある程度同じ文字が並ぶ文字列
            int tokenCount = rand.Generate(1, Q1_TOKEN_MAX_SIZE);
            std::string target;
            for (int64_t i = 0; i < tokenCount; ++i)
            {
                char token = rand.Generate(0, 53) + 'a';
                int64_t count = rand.Generate(1, Q1_TOKEN_MAX_SIZE);
                if (!target.empty() && target.back() == token)
                {
                    continue;
                }
                for (int64_t j = 0; j < count; ++j)
                {
                    target += token;
                }
            }
            std::vector<RLC::TOKEN> result = RLC::Encode(target);
            int64_t pos = 0;
            for (int64_t i = 0; i < result.size(); ++i)
            {
                for (int64_t j = pos; pos + j < result[i].count; ++j)
                {
                    if (target[j] != result[i].code)
                    {
                        std::cout << "<<<<<<NG" << std::endl;
                    }
                }
                pos += result[i].count;
            }
            std::string decodedResult = RLC::Decode(result);
            if (target != decodedResult)
            {
                std::cout << "<<<<<<NG" << std::endl;
            }
        }
        else if (q == 1)
        {
            // だいぶランダムにまぜまぜの文字列のテスト
            int tokenCount = rand.Generate(1, Q2_STRING_MAX_SIZE);
            std::string target;
            for (int64_t i = 0; i < tokenCount; ++i)
            {
                target += rand.Generate(0, 53) + 'a';
            }
            std::vector<RLC::TOKEN> result = RLC::Encode(target);
            std::string decodedResult = RLC::Decode(result);
            if (target != decodedResult)
            {
                std::cout << "<<<<<<NG" << std::endl;
            }
        }
        ++test;
    }
    std::cout << "OK!" << std::endl;
}