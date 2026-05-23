// ARC218B
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
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
void v_output(const std::vector<T> &a)
{
    for (int64_t i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void output(bool isAlice)
{
    if (isAlice)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
}

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    // 差が2以上のとき or 複数個同じ値がある => 分岐が生まれるためその瞬間にその人が勝ち

    sort(rall(A));
    bool isAlice = true;
    // bool isBob = false;
    if (A.size() == 1)
    {
        if (1 < A[0])
        {
            output(isAlice);
        }
        else if (A[0] == 0)
        {
            output(isAlice);
        }
        else
        {
            output(!isAlice);
        }
        return;
    }
    ll offset = 0;
    while (!(offset + 1 < A.back() || (A.back() == offset && A[A.size() - 2] == offset)))
    {
        if (A.size() == 1)
        {
            if (A[0] == offset + 1)
            {
                output(!isAlice);
            }
            else
            {
                output(isAlice);
            }
            return;
        }
        if (offset + 1 < A.back())
        {
            break;
        }
        else if (A.back() == offset + 1)
        {
            offset++;
        }
        else
        {
            A.pop_back();
        }
        isAlice = !isAlice;
    }
    output(isAlice);
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int64_t TESTCASES = 1;

    std::cin >> TESTCASES;

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