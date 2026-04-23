// AWC0054B
// template
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
//

/**
 * 1ケースぶんの処理実行
 */
void solve()
{
    /**
     * @brief 半開区間を表す構造体
     */
    struct SECTION
    {
        int64_t l; //<! 区間の左端
        int64_t r; //<! 区間の右端
        /**
         * ソート用の比較関数
         */
        bool operator<(const SECTION &target) const
        {
            return l < target.l || l == target.l && r < target.r;
        }
    };
    int64_t N, W;
    std::cin >> N >> W;
    std::vector<SECTION> secs(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> secs[i].l >> secs[i].r;
        secs[i].r += secs[i].l;
    }
    struct POS
    {
        int64_t pos;
        bool isLeft;
        /**
         * ソート用の比較関数
         */
        bool operator<(const POS &target) const
        {
            return this->pos < target.pos;
        }
    };
    std::vector<POS> A;

    for (int64_t i = 0; i < N; ++i)
    {
        A.push_back(POS{.pos = secs[i].l, .isLeft = true});
        A.push_back(POS{.pos = secs[i].r, .isLeft = false});
    }
    std::sort(A.begin(), A.end());
    std::vector<int64_t> stack;
    int64_t result = 0;
    for (int64_t i = 0; i < A.size(); ++i)
    {
        if (A[i].isLeft)
        {
            stack.push_back(A[i].pos);
        }
        else
        {
            int64_t p = stack.back();
            stack.pop_back();
            if (stack.empty())
            {
                result += A[i].pos - p;
            }
        }
    }
    std::cout << result << std::endl;
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