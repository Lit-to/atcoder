// ABC434D
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
    ll N;
    cin >> N;
    struct CLOUD
    {
        ll r;
        ll c;
        ll v;
    };
    struct QUERY
    {
        ll U;
        ll D;
        ll L;
        ll R;
    };
    vector<CLOUD> CLOUDS;
    vector<QUERY> QUERIES;
    for (ll i = 0; i < N; ++i)
    {

        ll U;
        ll D;
        ll L;
        ll R;
        cin >> U;
        cin >> D;
        cin >> L;
        cin >> R;
        --U;
        --L;
        CLOUDS.push_back(CLOUD{.r = U, .c = L, .v = 1});
        CLOUDS.push_back(CLOUD{.r = U, .c = R, .v = -1});
        CLOUDS.push_back(CLOUD{.r = D, .c = L, .v = -1});
        CLOUDS.push_back(CLOUD{.r = D, .c = R, .v = 1});
        QUERIES.push_back(QUERY{.U = U, .D = D, .L = L, .R = R});
    }
    const ll H = 2000;
    const ll W = 2000;
    vector<vector<ll>> BOARD(H + 2, vector<ll>(W + 2));
    for (ll i = 0; i < CLOUDS.size(); ++i)
    {
        ll r, c;
        r = CLOUDS[i].r;
        c = CLOUDS[i].c;
        BOARD[r + 1][c + 1] += CLOUDS[i].v;
    }
    for (ll i = 0; i < H + 1; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            BOARD[i][j + 1] += BOARD[i][j];
        }
    }
    for (ll i = 0; i < H; ++i)
    {
        for (ll j = 0; j < W + 1; ++j)
        {
            BOARD[i + 1][j] += BOARD[i][j];
        }
    }
    ll result = 0;
    for (ll i = 1; i < H + 1; ++i)
    {
        for (ll j = 1; j < W + 1; ++j)
        {
            result += BOARD[i][j] == 0;
        }
    }
    //
    vector<vector<ll>> ONE_BOARD(H + 2, vector<ll>(W + 2));
    for (ll i = 0; i < H + 1; ++i)
    {
        for (ll j = 0; j < W + 1; ++j)
        {
            {
                ONE_BOARD[i][j] = BOARD[i][j] == 1;
            }
        }
    }
    for (ll i = 0; i < H + 1; ++i)
    {
        for (ll j = 0; j < W; ++j)
        {
            ONE_BOARD[i][j + 1] += ONE_BOARD[i][j];
        }
    }
    for (ll j = 0; j < W + 1; ++j)
    {
        for (ll i = 0; i < H; ++i)
        {
            ONE_BOARD[i + 1][j] += ONE_BOARD[i][j];
        }
    }
    auto check = [&](ll lx, ll ly, ll rx, ll ry) -> ll
    {
        return ONE_BOARD[ry][rx] - ONE_BOARD[ly][rx] - ONE_BOARD[ry][lx] + ONE_BOARD[ly][lx];
    };
    for (ll i = 0; i < N; ++i)
    {
        ll u = QUERIES[i].U;
        ll d = QUERIES[i].D;
        ll l = QUERIES[i].L;
        ll r = QUERIES[i].R;
        cout << result + check(l, u, r, d) << endl;
    }
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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