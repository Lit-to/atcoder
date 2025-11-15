// ABC432A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{

    /*入力エリア*/
    int X;
    std::cin >> X;

    std::vector<int> a(0);
    while (0 < X)
    {
        a.push_back(X % 10);
        X /= 10;
    }
    std::sort(a.begin(), a.end());
    int usedIndex = 0;
    std::vector<int> b(0);
    for (int i = 0; i < std::ssize(a); ++i)
    {
        if (a[i] == 0)
        {
            continue;
        }
        usedIndex = i;
        b.push_back(a[i]);
        break;
    }
    for (int i = 0; i < std::ssize(a); ++i)
    {
        if (i == usedIndex)
        {
            continue;
        }
        b.push_back(a[i]);
    }
    for (int i = 0; i < std::ssize(a); ++i)
    {
        std::cout << b[i];
    }
    std::cout << std::endl;
    return 0;
}
