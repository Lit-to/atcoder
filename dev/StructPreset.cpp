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
/**
 * @brief 座標データ構造体
 */
struct POS
{
    int64_t X; //!< x座標
    int64_t Y; //!< y座標
};
const int64_t LRUD[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

/**
 * @brief グラフの辺情報
 */
struct EDGE
{
    int64_t distination; // 隣の行先ノード
    int64_t cost;        // そのノードに行くコスト
};

// ===================

int main()
{
    return 0;
}