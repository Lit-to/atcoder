// ABC0020D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stack>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 具体的なロジック
 *
 */

/*=========================*/

int main()
{
    int64_t N, L;
    std::cin >> N >> L;
    struct wifi
    {
        int64_t x;
        int64_t r;
    };
    std::vector<wifi> WIFI(N);
    for (int64_t i = 0; i < N; ++i)
    {
        int64_t x, r;
        std::cin >> x >> r;
        WIFI[i] = (wifi{.x = x, .r = r});
    }
    struct wifiSection
    {
        int64_t pos;
        bool isStart;
        const bool operator<(const wifiSection &rhs) const
        {
            if (pos != rhs.pos)
            {
                return pos < rhs.pos;
            }
            return isStart;
        }
    };
    std::vector<wifiSection> wifiPoints;
    for (int64_t i = 0; i < N; ++i)
    {
        wifiPoints.push_back(wifiSection{.pos = WIFI[i].x - WIFI[i].r, .isStart = true});
        wifiPoints.push_back(wifiSection{.pos = WIFI[i].x + WIFI[i].r + 1, .isStart = false});
    }
    std::sort(wifiPoints.begin(), wifiPoints.end());
    std::stack<int64_t> stack;
    stack.push(wifiPoints[0].pos);
    int64_t last = std::min<int64_t>(0, wifiPoints[0].pos);
    if (0 < wifiPoints[0].pos)
    {
        std::cout << "No" << std::endl;
        return 0;
    }
    for (int64_t i = 0; i < 2 * N; ++i)
    {
        if (!wifiPoints[i].isStart && wifiPoints[i].pos)
        {
        }
        if (last < wifiPoints[i].pos)
        {
            break;
        }
        last = std::max<int64_t>(wifiPoints[i].pos, last);
    }
    if (last <= L)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}