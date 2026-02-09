template <class T>
class Board
{
public:
    Board(int64_t height, int64_t width, T initValue = T())
    {
    }
};
#include <cstdint>

bool IsInner(int64_t i, int64_t j, int64_t h, int64_t w)
{
    return (0 <= i && i < h) && (0 <= j && j < w);
}
int64_t convertOneDigit(int64_t i, int64_t j, int64_t w)
{
    return i * w + j;
}
const int64_t LRUD[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
