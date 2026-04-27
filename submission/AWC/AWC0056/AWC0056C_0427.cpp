// AWC0056C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;
using ll = int64_t;
using vll = std::vector<int64_t>;
//
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    ll N, K;
    cin >> N >> K;
    vll A(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    int64_t r = 0;
    int64_t result = 0;
    int64_t s = 0;
    for (int64_t l = 0; l < N; ++l)
    {
        if (r < l)
        {
            r = l;
        }
        while (r < N && s <= K)
        {
            result = max(r - l, result);
            s += A[r];
            ++r;
        }
        if (s <= K)
        {
            result = max(r - l, result);
        }
        s -= A[l];
    }
    cout << result << endl;
}

/**
 * エントリポイント
 * テストケースごとに回す(デフォルトは1)
 */
int main()
{
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