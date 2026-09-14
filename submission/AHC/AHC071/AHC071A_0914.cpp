// AHC071A
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <vector>
#include <atcoder/all>

#include <map>
template <class KEY_TYPE, class VALUE_TYPE>
using TreeMap = std::map<KEY_TYPE, VALUE_TYPE>;
#include <unordered_map>
template <class KEY_TYPE, class VALUE_TYPE>
using HashMap = std::unordered_map<KEY_TYPE, VALUE_TYPE>;

#include <set>
template <class VALUE_TYPE>
using TreeSet = std::set<VALUE_TYPE>;
#include <unordered_set>
template <class VALUE_TYPE>
using HashSet = std::unordered_set<VALUE_TYPE>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::abs;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
T input()
{
    T variable;
    cin >> variable;
    return variable;
}
template <typename T>
std::vector<T> input(int64_t n)
{
    std::vector<T> contents(n);
    for (int64_t i = 0; i < n; ++i)
    {
        contents[i] = input<T>();
    }
    return contents;
}
// 自作ライブラリここから

// 自作ライブラリここまで
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    // 入力スニペ
    const auto W = input<ll>();
    const auto H = input<ll>();
    const auto K = input<ll>();
    const auto C = input<ll>(5);
    struct HOLE
    {
        ll y;
        ll x;
        bool operator<(const HOLE &target) const
        {
            return y < target.y || y == target.y && x < target.x;
        }
    };
    struct BRICK
    {

        ll y;
        ll x;
        ll w;
    };

    vector<HOLE> holes(K);
    for (ll i = 0; i < K; ++i)
    {
        cin >> holes[i].x >> holes[i].y;
    }
    std::sort(all(holes));
    vector<vector<char>> BOARD(H, vector<char>(W, '.'));
    vector<BRICK> bricks(0);
    auto isInside = [&](ll i, ll j, ll H, ll W) -> bool
    {
        return 0 <= i && i < H && 0 <= j && j < W;
    };

    auto isAvailable = [&](ll posY, ll posX, ll w) -> bool
    {
        for (ll i = 0; i < w; ++i)
        {
            if (!isInside(posY, posX + i, H, W))
            {
                return false;
            }
            if (BOARD[posY][posX + i] != '#')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    };
    auto setT = [&](ll posY, ll posX, ll w) -> void
    {
        bricks.push_back(BRICK{.y = posY, .x = posX, .w = w});
        for (ll i = 0; i < w; ++i)
        {
            BOARD[posY][posX + i] = '#';
        }

        ll center = posX + (w / 2);
        ll y = posY - 1;
        while (0 <= y && BOARD[y][center] != '#')
        {
            bricks.push_back(BRICK{.y = y, .x = center, .w = 1});
            BOARD[y][posX] = '#';
            --y;
        }
    };

    vector<ll> BRICKS_W({9, 7, 5, 3, 1});
    for (ll h = 0; h < K; ++h)
    {
        ll y = holes[h].y;
        ll x = holes[h].x;
        if (h == K - 1 || holes[h + 1].y != holes[h].y)
        {
            if (isAvailable(y, x, 1))
            {
                setT(y, x, 1);
                continue;
            }
        }
        ll distance = holes[h + 1].x + 1 - holes[h].x;
        if (9 < distance)
        {
            if (isAvailable(y, x, 1))
            {
                setT(y, x, 1);
                continue;
            }
        }
        else if (7 < distance)
        {
            if (isAvailable(y, x, 9))
            {
                setT(y, x, 9);
                continue;
            }
        }
        else if (5 < distance)
        {
            if (isAvailable(y, x, 7))
            {
                setT(y, x, 7);
                continue;
            }
        }
        else if (3 < distance)
        {
            if (isAvailable(y, x, 5))
            {
                setT(y, x, 5);
                continue;
            }
        }
        else if (1 < distance)
        {
            if (isAvailable(y, x, 3))
            {
                setT(y, x, 3);
                continue;
            }
        }
        if (isAvailable(y, x, 1))
        {
            setT(y, x, 1);
        }
    }

    cout << bricks.size() << endl;
    for (auto &brick : bricks)
    {
        cout << brick.x << " " << brick.y << " " << brick.w << endl;
    }
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t TESTCASES = DEFAULT_TESTCASE;
    // std::cin >> TESTCASES;
    for (int64_t i = 0; i < TESTCASES; ++i)
    {
        solve();
    }
}

//======================
/**
 *方針メモ欄
 *
 */
//======================

// AtCoder提出用テンプレート
// 自作ライブラリ・スニペットはここ:https://github.com/Lit-to/atcoder/tree/main/modules/cpp
