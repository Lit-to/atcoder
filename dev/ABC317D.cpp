// ABC317D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

/**
 *方針メモ欄
 *
 * # お気持ち
 * 既に高橋派の選挙区はどうでもいい
 * 青木派の選挙区において、尺取り
 *
 * # 具体的なロジック
 * まず以下
 * 選挙区をリストアップする
 * 高橋君に必要なのこりの議席を求める
 *
 * 尺取について
 * 青木選挙区について以下の情報を持ちたい
 * X Y Z
 * Z(議席数)について、高橋派ののこりの議席以上になるまで右端を進める
 * 必要な人数を求めて最大更新する
 * 左を一個進めて、右を再開する
 * 右左の更新の仕方
 *   -議席数+
 *   -その選挙区で勝つために必要な人数((X+Y+1)/2-X)を+
 *
 *
 */

/*=========================*/

int main()
{
    int64_t N;
    std::cin >> N;
    struct RATIO
    {
        int64_t T; // 高橋派人数
        int64_t A; // 青木派人数
        int64_t Z; // 割り当て議席
    };
    std::vector<RATIO> DINSTINCTS(N);
    int64_t HAVE = 0;
    int64_t ALL = 0;
    std::vector<RATIO> AOKI_AREA(0);

    for (int64_t i = 0; i < N; ++i)
    {
        std::cin >> DINSTINCTS[i].T;
        std::cin >> DINSTINCTS[i].A;
        std::cin >> DINSTINCTS[i].Z;
        ALL += DINSTINCTS[i].Z;
        if (DINSTINCTS[i].A < DINSTINCTS[i].T)
        {
            HAVE += DINSTINCTS[i].Z;
        }
        else
        {
            AOKI_AREA.push_back(DINSTINCTS[i]);
        }
    }
    int64_t MAJORITY_LINE = (ALL + 1) / 2;
    int64_t NEED = MAJORITY_LINE - HAVE; // 高橋君に必要な残りの議席数
    int64_t result = INT64_MAX;
    if (NEED == 0)
    {
        result = 0;
    }
    else
    {
        int64_t seats = 0;
        int64_t people = 0;
        int64_t right = 0;
        for (int64_t left = 0; left < AOKI_AREA.size(); ++left)
        {
            if (right < left)
            {
                right = left;
            }
            while (right < AOKI_AREA.size() && seats + HAVE < MAJORITY_LINE)
            {
                seats += AOKI_AREA[right].Z;
                people += ((AOKI_AREA[right].A + AOKI_AREA[right].T + 1) / 2 - AOKI_AREA[right].T);
                ++right;
            }
            if (MAJORITY_LINE <= seats + HAVE)
            {
                result = std::min(result, people);
            }
            seats -= AOKI_AREA[left].Z;
            people -= ((AOKI_AREA[left].A + AOKI_AREA[left].T + 1) / 2 - AOKI_AREA[left].T);
        }
    }
    std::cout << result << std::endl;
}