#include <iostream>
#include "../cpp/RandomGenerator.cpp"
#include "../cpp/Board.cpp"
#include <fstream>

int main()
{
    // === テストパラメータ === //
    const int64_t H_MAX = 9999;
    const int64_t W_MAX = 999;
    const int64_t V_MAX = 99999999;
    const int64_t TEST_COUNT = 100;
    // --------------------------
    randomGenerator rand;
    // === テストパラメータ === //

    // === 出力テスト === //
    Board<char> debugBoard(11, 15);
    for (int64_t i = 0; i < 11; ++i)
    {
        for (int64_t j = 0; j < 15; ++j)
        {
            debugBoard[i, j] = rand.Generate('a', 'z');
        }
    }
    debugBoard.Dump("testout.md");
    // === 出力テスト === //

    int64_t test = 0;
    while (test < TEST_COUNT)
    {
        const int64_t H = rand.Generate(1, H_MAX);
        const int64_t W = rand.Generate(1, W_MAX);
        std::vector<std::vector<char>> stdBoard(H, std::vector<char>(W));
        Board<char> customBoard(H, W);
        for (int64_t i = 0; i < H; ++i)
        {
            for (int64_t j = 0; j < W; ++j)
            {
                int64_t v = rand.Generate(1, V_MAX);
                stdBoard[i][j] = v;
                customBoard[i, j] = v;
            }
        }
        const int64_t q = rand.Generate(1, 5);
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
                int64_t posR = rand.Generate(1, H) - 1;
                int64_t posC = rand.Generate(1, W) - 1;
                int64_t value = rand.Generate(1, V_MAX);
                stdBoard[posR][posC] = value;
                customBoard[posR, posC] = value;
            }
        }
        else if (q == 3)
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
        else if (q == 4)
        {
            int64_t posR = rand.Generate(1, W_MAX);
            int64_t posC = rand.Generate(1, H_MAX);
            int64_t diffR = rand.Generate(1, std::min<int64_t>(std::max<int64_t>((-1 * H_MAX), 200), std::min<int64_t>(200, H_MAX)));
            int64_t diffC = rand.Generate(1, std::min<int64_t>(std::max<int64_t>((-1 * W_MAX), 200), std::min<int64_t>(200, W_MAX)));
            auto itr = customBoard.GetIterator(posR, posC);
            itr.Move(diffR, diffC);
            if (itr != customBoard.GetIterator(posR, posC))
            {
                continue;
            }
            else
            {
                std::cerr << "q4:不具合:!=" << std::endl;
            }
        }
        else if (q == 5)
        {
            int64_t posR = rand.Generate(1, W_MAX);
            int64_t posC = rand.Generate(1, H_MAX);
            int64_t diffR = rand.Generate(1, std::min<int64_t>(std::max<int64_t>((-1 * H_MAX), 200), std::min<int64_t>(200, H_MAX)));
            int64_t diffC = rand.Generate(1, std::min<int64_t>(std::max<int64_t>((-1 * W_MAX), 200), std::min<int64_t>(200, W_MAX)));
            auto itr = customBoard.GetIterator(posR, posC).GetMoved(diffR, diffC);
            if (itr == customBoard.GetIterator(posR, posC))
            {
                std::cerr << "q4:不具合:==" << std::endl;
            }
            else
            {
                continue;
            }
        }
        ++test;
    }
    std::cout << "OK!" << std::endl;
}