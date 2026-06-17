// ABC343D
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
    ll N, T;
    cin >> N >> T;
    vector<ll> A(T);
    vector<ll> B(T);
    struct contest
    {
        int64_t A; //<! 区間の左端
        int64_t B; //<! 区間の右端
        /**
         * ソート用の比較関数
         */
        bool operator<(const contest &target) const
        {
            return A < target.A || A == target.A && B < target.B;
        }
    };
    vector<contest> contests(T);
    for (ll i = 0; i < T; ++i)
    {
        cin >> contests[i].A >> contests[i].B;
        --contests[i].A;
    }
    unordered_map<ll, ll> PEOPLE_SCORES(N);
    vector<ll> PEOPLE(N);
    PEOPLE_SCORES[0] = N;
    for (ll i = 0; i < T; ++i)
    {
        --PEOPLE_SCORES[PEOPLE[contests[i].A]];
        if (PEOPLE_SCORES[PEOPLE[contests[i].A]] == 0)
        {
            PEOPLE_SCORES.erase(PEOPLE[contests[i].A]);
        }
        PEOPLE[contests[i].A] += contests[i].B;
        ++PEOPLE_SCORES[PEOPLE[contests[i].A]];
        cout << PEOPLE_SCORES.size() << endl;
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