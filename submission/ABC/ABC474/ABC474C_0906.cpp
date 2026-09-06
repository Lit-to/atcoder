// ABC474C
// template
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <list>
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
    // const auto S = input<std::string>();
    //
    const auto N = input<ll>();
    const auto Q = input<ll>();
    const auto P = input<ll>(N);
    const auto QUERIES = input<ll>(Q);

    std::list<ll> linkedList;
    vector<std::__cxx11::list<ll>::iterator> bucket(N + 1);

    for (ll i = 0; i < N; ++i)
    {
        linkedList.push_back(P[i]);
        bucket[P[i]] = linkedList.end(); // ある値はどの位置にあるのかを表すばけつ
        bucket[P[i]]--;
    }
    for (ll i = 0; i < Q; ++i)
    {
        linkedList.erase(bucket[QUERIES[i]]);
        // 末尾への追加
        linkedList.push_back(QUERIES[i]);
        bucket[QUERIES[i]] = linkedList.end();
        bucket[QUERIES[i]]--;
    }
    for (auto i = linkedList.begin(); i != linkedList.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    // struct linkedListNode
    // {
    //     ll next;
    //     ll prev;
    //     ll value;
    // };
    // vector<linkedListNode> linkedList(N);
    // vector<vector<ll>> bucket(N + 1);

    // for (ll i = 0; i < N; ++i)
    // {
    //     linkedList[i].next = i + 1;
    //     linkedList[i].prev = i - 1;
    //     linkedList[i].value = P[i];
    //     bucket[P[i]].push_back(i); // ある値はどの位置にあるのかを表すばけつ
    // }
    // linkedList.push_back(linkedListNode{.next = -1, .prev = N - 1, .value = -1});
    // ll head = 0;
    // ll tail = N;
    // for (ll i = 0; i < Q; ++i)
    // {
    //     for (auto &q : bucket[QUERIES[i]]) // 削除
    //     {
    //         if (q == head)
    //         {
    //             head = linkedList[q].next;
    //         }

    //         linkedList[linkedList[q].prev].next = linkedList[q].next;
    //         linkedList[linkedList[q].next].prev = linkedList[q].prev;
    //     }
    //     // 末尾への追加
    //     linkedList.push_back(linkedListNode{.next = tail, .prev = linkedList[tail].prev, .value = QUERIES[i]});
    //     linkedList[linkedList[tail].prev].next = linkedList.size() - 1;
    //     bucket[QUERIES[i]].clear();
    //     bucket[QUERIES[i]].push_back(tail);
    // }
    // ll p = head;
    // while (p != tail)
    // {
    //     cout << linkedList[p].value << " ";
    //     p = linkedList[p].next;
    // }
    // cout << endl;
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
