// AWC0076C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <stack>
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
    vector<std::string> T(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> T[i];
    }
    ll K;
    cin >> K;
    vector<ll> p(K);
    for (ll i = 0; i < K; ++i)
    {
        cin >> p[i];
        --p[i];
    }
    vector<std::string> fomula(N);
    vector<bool> isSign(N);
    ll iter = 0;
    auto resolve = [&](auto self, ll bg) -> ll
    {
        if (!isSign[iter])
        {
            return std::stoll(fomula[iter]);
        }
        ++iter;
        ll a = self(self, iter);
        ++iter;
        ll b = self(self, iter);

        if (fomula[bg][0] == '+')
        {
            return a + b;
        }
        else if (fomula[bg][0] == '-')
        {
            return a - b;
        }
        else if (fomula[bg][0] == '*')
        {
            return a * b;
        }
        else if (fomula[bg][0] == '/')
        {
            return a / b;
        }
        return 0;
    };

    vector<std::string> s(N);
    vector<std::string> t(N);

    for (ll i = 0; i < N; ++i)
    {
        if (T[i][0] == '+' || T[i].size() == 1 && T[i][0] == '-' || T[i][0] == '*' || T[i][0] == '/')
        {
            isSign[i] = true;
        }
        s[i] = T[i];
        t[i] = T[i];
    }
    for (ll i = 0; i < K; ++i)
    {
        if (T[p[i]][0] == '+')
        {
            s[p[i]] = '-';
        }
        else if (T[p[i]][0] == '-')
        {
            s[p[i]] = '+';
        }
        else if (T[p[i]][0] == '*')
        {
            s[p[i]] = '/';
        }
        else if (T[p[i]][0] == '/')
        {
            s[p[i]] = '*';
        }
    }
    ll result[2] = {0, 0};
    std::copy(t.begin(), t.end(), fomula.begin());
    iter = 0;
    result[0] = resolve(resolve, 0);
    std::copy(s.begin(), s.end(), fomula.begin());
    iter = 0;
    result[1] = resolve(resolve, 0);
    cout << result[0] << endl;
    cout << result[1] << endl;
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