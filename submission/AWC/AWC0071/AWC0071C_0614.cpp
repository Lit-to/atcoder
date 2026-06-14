// AWC0071C
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <unordered_set>
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
    ll N;
    cin >> N;
    vector<ll> W(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> W[i];
    }
    auto psm = PrefixSumManager(W);
    unordered_set<ll> psmSet;
    for (ll i = 1; i < N + 1; ++i)
    {
        psmSet.insert(psm.At(i));
    }
    ll T = psm.At(psm.GetSize() - 1);
    ll result = 0;
    for (ll i = 1; i < N + 1; ++i)
    {
        ll p = 0;
        if (T % i != 0)
        {
            continue;
        }
        bool isOK = true;
        for (ll j = 1; j < i; ++j)
        {
            p = j * (T / i);
            if (!psmSet.contains(p))
            {
                isOK = false;
                break;
            }
        }
        if (isOK)
        {
            result = max(i, result);
        }
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