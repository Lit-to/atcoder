#include <string>
#include <vector>
#include <cstdint>
// コピペ用
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
/**
 * 4方向移動差分配列LRUD
 */
const int64_t LRUD_4[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

/**
 * 8方向移動差分配列LRUD
 */
const int64_t LRUD8[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};

/**
 * @brief グラフの辺情報
 */
struct EDGE
{
    int64_t destination; // 隣の行先ノード
    int64_t cost;        // そのノードに行くコスト
};

/**
 * DFSスニペット
 */
auto dfs = [&](auto self) -> bool // 引数にノード、戻り値は適度に
{
    // 訪問済み管理のチェック

    // 訪問済み管理の登録

    // 行きがけ順に処理したい内容

    for (;;) // 遷移処理
    {
        self(self);
    }
    // 帰りがけ順に処理したい内容
};
// 構造体ではないけどおまじない
#include <queue>
template <typename T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

// ===================

int main()
{
    return 0;
}