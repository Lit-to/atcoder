// ABC335D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 *
 *
 *
 *
 *
 *
 * # 出力
 *
 *
 */

bool isInner(int64_t y, int64_t x, std::vector<std::vector<int64_t>> &board)
{
    return 0 <= y && y < board.size() && 0 <= x && x < board[y].size();
}
bool isValidPos(int64_t y, int64_t x, std::vector<std::vector<int64_t>> &board)
{
    if (!isInner(y, x, board))
    {
        return false;
    }
    return board[y][x] == 0;
}
int RDLU[4][2] = {{0, 1},
                  {1, 0},
                  {0, -1},
                  {-1, 0}};

int main()
{
    int N;
    std::cin >> N;
    std::vector<std::vector<int64_t>> BOARD(N);
    for (int i = 0; i < N; ++i)
    {
        std::vector<int64_t> line(N);
        for (int j = 0; j < N; ++j)
        {
            line[i] = 0;
        }
        BOARD[i] = line;
    }
    int direction = 0;
    int pos[] = {0, 0};
    int64_t count = 1;
    while (isValidPos(pos[0], pos[1], BOARD))
    {
        BOARD[pos[0]][pos[1]] = count;
        ++count;
        int newPos[] = {pos[0] + RDLU[direction][0],
                        pos[1] + RDLU[direction][1]};
        if (!isValidPos(newPos[0], newPos[1], BOARD))
        {
            ++direction;
            direction %= 4;
            pos[0] = pos[0] + RDLU[direction][0];
            pos[1] = pos[1] + RDLU[direction][1];
        }
        else
        {
            pos[0] = newPos[0];
            pos[1] = newPos[1];
        }
        // std::cerr << "[" << pos[0] << "," << pos[1] << "]" << std::endl;
    }
    BOARD[(N + 1) / 2 - 1][(N + 1) / 2 - 1] = -1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (BOARD[i][j] == -1)
            {
                std::cout << "T ";
                continue;
            }
            else
            {
                std::cout << BOARD[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}