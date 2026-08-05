// ABC469D
// clang-format off
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <atcoder/all>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define DEFAULT_TESTCASE (1);
using std::cin;using std::cout;using std::endl;using ll = int64_t;using vll = std::vector<int64_t>;using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
template <typename T>using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>T input(){T variable;cin >> variable;return variable;}
template <typename T>std::vector<T> input(int64_t n){std::vector<T> contents(n);for (int64_t i = 0; i < n; ++i){contents[i] = input<T>();}return contents;}
// clang-format on
#include <vector>
#include <cstdint>
/**
 * 累積和計算クラス
 */
class PrefixSumManager
{
public:
    /**
     * コンストラクタ
     * 累積和の事前計算を行う
     * @param values 求めたい値配列
     */
    PrefixSumManager(const std::vector<int64_t> &values)
    {
        m_data.push_back(0);
        for (int64_t i = 0; i < values.size(); ++i)
        {
            m_data.push_back(m_data[i] + values[i]);
        }
    };

    /**
     * 与えられたデータの(l,r)までの総和を求める。
     * -  -  半開区間[0,r)の総和-[0,l)の総和の差を返す
     */
    int64_t GetSum(int64_t leftSection, int64_t rightSection) const
    {
        return m_data[rightSection] - m_data[leftSection];
    };

    /**
     * 累積済みの配列のi番目の値を求める
     */
    int64_t At(int64_t pos)
    {
        return m_data[pos];
    }
    /**
     * サイズ取得
     */
    int64_t GetSize()
    {
        return m_data.size();
    }

private:
    std::vector<int64_t> m_data; //!< 累積和として計算済みのデータ
};
using PSM = PrefixSumManager;
/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /*
    // const auto S = input<std::string>();
    // const auto A = input<ll>(10);
    */
    const auto N = input<ll>();
    const auto M = input<ll>();
    struct WINNER_PAIR
    {
        ll A;
        ll B;
    };
    std::vector<WINNER_PAIR> AB(M);
    for (ll i = 0; i < M; ++i)
    {
        cin >> AB[i].A >> AB[i].B;
        --AB[i].A;
        --AB[i].B;
    }
    std::vector<ll> isWinnerExp(N);
    for (ll i = 0; i < M; ++i)
    {
        isWinnerExp[AB[i].A] = 1;
        isWinnerExp[AB[i].B] = 1;
    }
    ll count = 0;
    ll result = 0;
    for (ll i = 0; i < N; ++i)
    {
        if (0 < isWinnerExp[i])
        {
            ++count;
        }
        result += (count * (count - 1)) / 2;
    }
    cout << result << endl;
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