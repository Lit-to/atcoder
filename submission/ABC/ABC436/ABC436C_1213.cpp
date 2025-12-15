// ABC436C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_set>
#include <set>

int main()
{
    const int64_t LRUD[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

    /*入力エリア*/
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int64_t>> RC(M);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t R, C;
        std::cin >> R >> C;
        std::vector<int64_t> temp(2);
        temp[0] = R;
        temp[1] = C;
        RC[i] = temp;
    }

    /*実装エリア */
    // std::set<std::vector<int64_t>> isPlaced;
    std::unordered_set<int64_t> isPlaced;
    const int64_t H = 2e9;
    const int64_t W = 2e9;
    for (int64_t i = 0; i < M; ++i)
    {
        bool isNotCovered = true;
        for (auto &d : LRUD)
        {
            std::vector<int64_t> pos(2);
            pos[0] = RC[i][0] + d[0];
            pos[1] = RC[i][1] + d[1];
            if (isPlaced.contains(pos[0] * W + pos[1]))
            {
                isNotCovered = false;
                break;
            }
        }
        if (isNotCovered)
        {
            for (auto &d : LRUD)
            {
                std::vector<int64_t> pos(2);
                pos[0] = RC[i][0] + d[0];
                pos[1] = RC[i][1] + d[1];
                isPlaced.insert(pos[0] * W + pos[1]);
            }
        }
    }
    std::cout << isPlaced.size() / 4 << std::endl;

    return 0;
}