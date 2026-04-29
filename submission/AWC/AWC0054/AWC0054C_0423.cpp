// AWC0054C
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
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> S(N);
    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> S[i];
    }
    struct WATER
    {
        int64_t L;
        int64_t R;
        int64_t W;
    };
    struct POS
    {
        int64_t pos;
        int64_t amount;
        bool isLeft;
        /**
         * ソート用の比較関数
         */
        bool operator<(const POS &target) const
        {
            return this->pos < target.pos;
        }
    };
    std::vector<WATER> waters(M);
    for (int64_t i = 0; i < M; ++i)
    {
        std::cin >> waters[i].L >> waters[i].R >> waters[i].W;
        --waters[i].L;
    }
    std::vector<POS> event;
    for (int64_t i = 0; i < M; ++i)
    {
        event.push_back(POS{.pos = waters[i].L, .amount = waters[i].W, .isLeft = true});
        event.push_back(POS{.pos = waters[i].R, .amount = -1 * waters[i].W, .isLeft = false});
    }
    std::vector<int64_t> flowers(N);
    for (int64_t i = 0; i < event.size(); ++i)
    {
        flowers[event[i].pos] += event[i].amount;
    }
    std::vector<int64_t> pfs;
    pfs.push_back(0);
    for (int64_t i = 0; i < N; ++i)
    {
        pfs.push_back(pfs.back() + flowers[i]);
    }
    int64_t result = 0;
    for (int64_t i = 1; i < N + 1; ++i)
    {
        int64_t p = i - 1;
        result += S[p] < pfs[i];
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