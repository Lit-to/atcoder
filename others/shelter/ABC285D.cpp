// ABC285D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <map>
//
int main()
{
    int64_t N;
    std::cin >> N;
    std::map<std::string, std::string> graph;
    for (int64_t i = 0; i < N; ++i)
    {
        std::string s, t;
        std::cin >> s >> t;
        graph[s] = t;
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================