// ABC115D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
long layerSize[51];
long pattySize[51];
int64_t X;
long patties = 0;
int64_t layers = 0;
int64_t ans = 0;
void makeBurger(int64_t level)
{
    if (level == 0)
    {
        layers++;
        patties++;
        return;
    }
    else
    {
        layers++;
        if (layers == X)
        {
            return;
        }
        //
        if (X <= layers + layerSize[level - 1])
        {
            makeBurger(level - 1);
            return;
        }
        layers += layerSize[level - 1];
        patties += pattySize[level - 1];
        //
        layers++;
        patties++;
        if (layers == X)
        {
            return;
        }
        //
        if (X <= layers + layerSize[level - 1])
        {
            makeBurger(level - 1);
            return;
        }
        layers += layerSize[level - 1];
        patties += pattySize[level - 1];
        //
        layers++;
        if (layers == X)
        {
            return;
        }
    }
}
int main()
{
    layerSize[0] = 1;
    pattySize[0] = 1;
    for (long i = 1; i < 51; ++i)
    {
        layerSize[i] = layerSize[i - 1] * 2 + 3;
        pattySize[i] = pattySize[i - 1] * 2 + 1;
    }
    /*入力エリア*/
    int64_t N;
    std::cin >> N >> X;

    /*実装エリア */
    makeBurger(N);
    std::cout << patties << std::endl;
    return 0;
}