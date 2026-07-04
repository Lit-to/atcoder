// ABC465C
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using std::cin;
using std::cout;
using std::endl;
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
    int64_t N;
    cin >> N;
    std::string S;
    cin >> S;
    bool isMaruBack = true;
    std::deque<ll> result;
    for (ll i = 0; i < N; ++i)
    {
        if (S[i] == 'o')
        {
            if (isMaruBack)
            {
                result.push_back(i);
            }
            else
            {
                result.push_front(i);
            }
            isMaruBack = !isMaruBack;
        }
        else
        {
            if (isMaruBack)
            {
                result.push_back(i);
            }
            else
            {
                result.push_front(i);
            }
        }
    }
    if (!isMaruBack)
    {
        std::reverse(result.begin(), result.end());
    }
    auto rIter = result.begin();
    for (ll i = 0; i < N; ++i)
    {
        cout << (*rIter) + 1 << " ";
        ++rIter;
        // cout << result[i] + 1 << " ";
    }
    cout << endl;
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