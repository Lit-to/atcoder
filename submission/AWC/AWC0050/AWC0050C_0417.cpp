// AWC0050C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <map>
#include <stack>

//
int main()
{
    int64_t N;
    std::cin >> N;
    std::map<int64_t, int64_t> latest;
    struct QUERY
    {
        int64_t q;
        int64_t c;
    };
    std::vector<QUERY> queries(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::string S;
        std::cin >> S;
        if (S == "PUT")
        {
            queries[i].q = 0;
            std::cin >> queries[i].c;
        }
        else if (S == "REMOVE")
        {
            queries[i].q = 1;
            queries[i].c = 0;
        }
        else
        {
            queries[i].q = 2;
            queries[i].c = 0;
        }
    }
    int64_t p = 0;
    std::stack<int64_t> st;
    for (int64_t i = 0; i < N; ++i)
    {
        if (queries[i].q == 0)
        {
            p ^= queries[i].c;
            st.push(p);
        }
        else if (queries[i].q == 1)
        {
            int64_t v = st.top();
            p ^= v;
            st.pop();
        }
        else
        {
            std::cout << latest[p] - 1 << std::endl;
            latest[p] = i + 1;
        }
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================