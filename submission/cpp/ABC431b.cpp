// template
#include <iostream>
#include <string>
#include <vector>

int main()
{

    int X;
    int N;
    std::cin >> X;
    std::cin >> N;
    std::vector<int> W(N);
    for (int i = 0; i < N; ++i)
    {
        int w;
        std::cin >> w;
        W[i] = w;
    }
    int Q;
    std::cin >> Q;
    std::vector<int> QUERIES(Q);
    for (int i = 0; i < Q; ++i)

    {
        int p;
        std::cin >> p;
        QUERIES[i] = p;
    }

    std::cerr << "______" << std::endl;
    /*実装エリア */
    int weight = X;
    std::vector<bool> parts(N);
    for (int i = 0; i < Q; ++i)
    {
        int q = QUERIES[i];
        if (parts[q - 1])
        {
            parts[q - 1] = false;
            weight -= W[q - 1];
        }
        else
        {
            parts[q - 1] = true;
            weight += W[q - 1];
        }
        std::cout << weight << std::endl;
    }
    return 0;
}
