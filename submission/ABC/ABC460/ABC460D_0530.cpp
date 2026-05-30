// ABC460D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    const int64_t LRUD[8][2] = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1},
    };

    ll H, W;
    cin >> H >> W;
    vector<vector<char>> BOARD(H, vector<char>(W));
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            cin >> BOARD[i][j];
        }
    }
    struct pos
    {
        ll y;
        ll x;
    };
    vector<pos> toBeWhite;
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            if (BOARD[i][j] == '#')
            {
                ll blackCount = 0;
                for (ll d = 0; d < 8; ++d)
                {
                    ll pos[2] = {LRUD[d][0] + i, LRUD[d][1] + j};
                    if (0 <= pos[0] && pos[0] < H && 0 <= pos[1] && pos[1] < W)
                    {
                        blackCount += BOARD[pos[0]][pos[1]] == '#';
                    }
                    else
                    {
                        ++blackCount;
                    }
                }
                if (blackCount == 8)
                {
                    toBeWhite.push_back(pos{.y = i, .x = j});
                }
            }
        }
    }
    for (pos &p : toBeWhite)
    {
        BOARD[p.y][p.x] = '.';
    }
    struct TASK
    {
        ll count;
        pos p;
    };
    queue<TASK> tasks;
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            if (BOARD[i][j] == '#')
            {
                tasks.push(TASK{.count = 1, .p = pos{.y = i, .x = j}});
            }
        }
    }
    vector<vector<bool>> done(H, vector<bool>(W));
    while (!tasks.empty())
    {
        TASK task = tasks.front();
        tasks.pop();
        for (ll d = 0; d < 8; ++d)
        {
            pos nextPos = pos{.y = LRUD[d][0] + task.p.y, .x = LRUD[d][1] + task.p.x};
            if (0 <= nextPos.y && nextPos.y < H && 0 <= nextPos.x && nextPos.x < W)
            {
                if (done[nextPos.y][nextPos.x])
                {
                    continue;
                }
                done[nextPos.y][nextPos.x] = true;
                if (task.count % 2 == 0)
                {
                    BOARD[nextPos.y][nextPos.x] = '#';
                }
                tasks.push(TASK{.count = task.count + 1, .p = pos{.y = nextPos.y, .x = nextPos.x}});
            }
        }
    }
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            cout << BOARD[i][j];
        }
        cout << endl;
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
    int64_t TESTCASES = 1;

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