// ABC355D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <stack>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 括弧列の組み合わせとして見る/lをカッコ、rをコッカとして取り扱い、stackに積み上げる
 * コッカを見たときに、1組にして捨て、stackに積まれているの子っとカッコの数ぶんを加算する。=>総和を取る
 * # 具体的なロジック
 * 入力を受け取る
 * (l,0),(r,1)みたいなべくたーを持ってソート
 * stackにカッコのインデックスを積み上げる
 * コッカが来たらスタックの末尾を捨て、スタックの長さを答えに加算
 * 答えを出す
 *
 *
 */
int main()
{
    int64_t N;
    std::cin >> N;
    struct item
    {
        int64_t m_index;
        bool m_isEnd;
        bool operator<(const item &rhs) const
        {
            return m_index < rhs.m_index || (m_index == rhs.m_index && m_isEnd != rhs.m_isEnd && m_isEnd == false);
        }
    };
    std::vector<item> SEP(0);

    for (int64_t i = 0; i < N; ++i)
    {
        int64_t l, r;
        std::cin >> l >> r;
        SEP.push_back(item{.m_index = l, .m_isEnd = false});
        SEP.push_back(item{.m_index = r, .m_isEnd = true});
    }
    std::sort(SEP.begin(), SEP.end());
    std::stack<int64_t> stack;
    int64_t result = 0;
    for (int64_t i = 0; i < SEP.size(); ++i)
    {
        if (SEP[i].m_isEnd)
        {
            if (!stack.empty())
            {
                stack.pop();
            }
            result += stack.size();
        }
        else
        {
            stack.push(SEP[i].m_index);
        }
    }
    std::cout << result << std::endl;
}