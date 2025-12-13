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
    std::vector<std::vector<int>> LRUD(4);
    std::vector<int> L(2);
    std::vector<int> R(2);
    std::vector<int> U(2);
    std::vector<int> D(2);
    L = {0, 0};
    R = {0, 1};
    U = {1, 0};
    D = {1, 1};
    LRUD[0] = L;
    LRUD[1] = R;
    LRUD[2] = U;
    LRUD[3] = D;

    /*入力エリア*/
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> RC(M);
    for (int i = 0; i < M; ++i)
    {
        int R, C;
        std::cin >> R >> C;
        std::vector<int> temp(2);
        temp[0] = R;
        temp[1] = C;
        RC[i] = temp;
    }

    /*実装エリア */
    std::set<std::vector<int>> isPlaced;

    for (int i = 0; i < M; ++i)
    {
        bool isNotCovered = true;
        for (int j = 0; j < 4; ++j)
        {
            std::vector<int> pos(2);
            pos[0] = RC[i][0] + LRUD[j][0];
            pos[1] = RC[i][1] + LRUD[j][1];
            if (isPlaced.contains(pos))
            {
                isNotCovered = false;
                break;
            }
        }
        if (isNotCovered)
        {
            for (int j = 0; j < 4; ++j)
            {
                std::vector<int> pos(2);
                pos[0] = RC[i][0] + LRUD[j][0];
                pos[1] = RC[i][1] + LRUD[j][1];
                isPlaced.insert(pos);
            }
        }
        // std::cerr << RC[i][0] << ":" << RC[i][1] << ":" << isPlaced.size() << std::endl;
    }
    std::cout << isPlaced.size() / 4 << std::endl;

    return 0;
}