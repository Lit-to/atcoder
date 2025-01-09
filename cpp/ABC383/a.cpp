#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int t;
    int v;
    int w=0;
    int time=0;
    for (int i = 0;i < N;i++) {
        std::cin >> t >> v;
        while (time < t){
            w--;
            if (w<0){
                w=0;
            }
            time++;
        }
        w+=v;
    }
    std::cout << w+1 << std::endl ;
    return 0;
}

