#include <iostream>
#include "../cpp/RandomGenerator.cpp"
#include "../cpp/Board.cpp"
#include <fstream>

int main()
{
    // === テストパラメータ === //
    const int64_t N_MAX = 999999;
    const int64_t H_MAX = 9999;
    const int64_t W_MAX = 999;
    const int64_t V_MAX = 99999999;
    const int64_t TEST_COUNT = 100;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //
    int64_t test = 0;
    Board<int64_t> debugBoard(11, 15);
    for (int64_t i = 0; i < 11; ++i)
    {
        for (int64_t j = 0; j < 11; ++j)
        {
            debugBoard[i, j] = rand.Generate(1, 100);
        }
    }
    debugBoard.Dump("testout.md");
    while (test < TEST_COUNT)
    {
        const int64_t H = rand.Generate(1, H_MAX);
        const int64_t W = rand.Generate(1, W_MAX);
        std::vector<std::vector<int64_t>> stdBoard(H, std::vector<int64_t>(W));
        Board<int64_t> customBoard(H, W);
        for (int64_t i = 0; i < H; ++i)
        {
            for (int64_t j = 0; j < W; ++j)
            {
                int64_t v = rand.Generate(1, V_MAX);
                stdBoard[i][j] = v;
                customBoard[i, j] = v;
            }
        }
        const int64_t q = rand.Generate(1, 3);
        if (q == 1)
        {
            for (int64_t i = 0; i < H; ++i)
            {
                for (int64_t j = 0; j < W; ++j)
                {
                    if (stdBoard[i][j] != customBoard[i, j])
                    {
                        std::cerr << "q1:不一致(" << i << "," << j << ")[" << stdBoard[i][j] << "!=" << customBoard[i, j] << "]" << std::endl;
                    }
                }
            }
        }
        else if (q == 2)
        {
            // てきとうな場所を上書き
            for (int i = 0; i < 10; ++i)
            {
                int64_t posR = rand.Generate(1, H);
                int64_t posC = rand.Generate(1, W);
                int64_t value = rand.Generate(1, V_MAX);
                stdBoard[posR][posC] = value;
                customBoard[posR, posC] = value;
            }
        }
        else
        {
            // イテレータ作成、てきとうに移動
            int64_t posR = rand.Generate(1, W_MAX);
            int64_t posC = rand.Generate(1, H_MAX);
            int64_t diffR = rand.Generate(1, std::min<int64_t>(std::max<int64_t>((-1 * H_MAX), 200), std::min<int64_t>(200, H_MAX)));
            int64_t diffC = rand.Generate(1, std::min<int64_t>(std::max<int64_t>((-1 * W_MAX), 200), std::min<int64_t>(200, W_MAX)));
            auto itr = customBoard.GetIterator(posR, posC);
            itr.Move(diffR, diffC);
            if (itr.IsInside())
            {
                int64_t r = posR + diffR;
                int64_t c = posC + diffC;
                if ((*itr) != stdBoard[r][c])
                {
                    std::cerr << "q3:不一致(" << r << "," << c << ")[" << stdBoard[r][c] << "!=" << customBoard[r, c] << "]" << std::endl;
                }
            }
        }

        ++test;
    }
    std::cout << "OK!" << std::endl;
}