#include <string>
#include <vector>
#include <cstdint>
// コピペ用 構造体集
// ===================
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
// ===================

int main()
{
    return 0;
}