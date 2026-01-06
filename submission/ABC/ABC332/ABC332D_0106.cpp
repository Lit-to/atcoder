// ABC332D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <deque>
#include <map>

/**
 *方針メモ欄
 *
 * # お気持ち
 * BFSして、盤面の状態を持ちながら手数を数える
 *
 * # 入力
 * H縦 W横
 * 盤面A
 * 盤面B
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 *
 * # 具体的なロジック
 * 子ノードを列挙する関数(配列:[0,1,2,3,4]):
 *   答え配列 = []
 *   i < 配列長-1にかけてループ
 *   i,i+1を入れ替えた配列を作る
 *   答え配列にコピーして突っ込む
 *   答え配列を返す
 * 盤面を生成する関数(縦配列:[0,1,2,3,4],横配列:[0,1,2,3,4])
 *  縦配列、横配列の各インデックスの値からA[i][j]の値をコピーして二次元配列を作る
 *  返す
 *
 *
 *
 *  縦と横の配列を作る
 *  縦初期値[0,1..,H-1]
 *  横初期値[0,1..,W-1]
 *  空のqueueを作る
 *  ここに([縦初期値],[横初期値],0)をqueueに入れる
 *
 *  BFSのwhile queueが空になるまで
 *    top = queueからtopを取り出す
 *    topの情報で盤面を生成する
 *    生成した盤面とBが一致していたらtopの手数を出力してプログラムを終了
 *    そうじゃなかったら生成した盤面topの手数+1をキューに入れる
 *  この時点で一致しなかったとみなして-1を出力する
 *
 *
 *
 *
 * # 出力
 *
 *
 */

struct state
{
    std::vector<int64_t> column;
    std::vector<int64_t> row;
    int64_t count;
};
std::vector<std::vector<int64_t>> generateCandidates(std::vector<int64_t> head)
{
    std::vector<std::vector<int64_t>> result(0);
    int n = head.size();
    for (int i = 0; i < n - 1; ++i)
    {
        // for (int j = i + 1; j < n; ++j)
        // {
        std::swap(head[i], head[i + 1]);
        std::vector<int64_t> newHead(head.size());
        std::copy(head.begin(), head.end(), newHead.begin());
        result.push_back(newHead);
        std::swap(head[i + 1], head[i]);
        // }
    }
    return result;
}
std::vector<std::vector<int64_t>> generateBoard(state boardState, std::vector<std::vector<int64_t>> &A)
{
    std::vector<std::vector<int64_t>> result(0);
    for (int i = 0; i < A.size(); ++i)
    {
        std::vector<int64_t> line(A[i].size());
        for (int j = 0; j < A[i].size(); ++j)
        {
            line[j] = A[boardState.column[i]][boardState.row[j]];
        }
        result.push_back(line);
    }
    return result;
}
bool isSameBoard(std::vector<std::vector<int64_t>> &a, std::vector<std::vector<int64_t>> &b)
{
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    /*入力エリア
     * std::cin >> N;
     */
    int64_t H, W;
    std::cin >> H >> W;
    std::vector<std::vector<int64_t>> A(H);
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            int64_t inp;
            std::cin >> inp;
            A[i].push_back(inp);
        }
    }
    std::vector<std::vector<int64_t>> B(H);
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            int64_t inp;
            std::cin >> inp;
            B[i].push_back(inp);
        }
    }

    /* 実装エリア */

    std::deque<state> queue;
    std::vector<int64_t> column(H);
    std::vector<int64_t> row(W);
    for (int i = 0; i < H; ++i)
    {
        column[i] = i;
    }
    for (int i = 0; i < W; ++i)
    {
        row[i] = i;
    }
    queue.push_back(state{.column = column, .row = row, .count = 0});
    int64_t result = -1;

    std::map<std::vector<std::vector<int64_t>>, int64_t> done;
    if (isSameBoard(A, B))
    {
        result = 0;
        queue.clear();
    }
    while (!queue.empty())
    {
        state target = queue.front();
        queue.pop_front();
        std::vector<std::vector<int64_t>> columnCandidates = generateCandidates(target.column);
        for (int i = 0; i < columnCandidates.size(); ++i)
        {
            state newState = state{.column = columnCandidates[i], .row = target.row, .count = target.count + 1};
            std::vector<std::vector<int64_t>> t(0);
            t.push_back(newState.column);
            t.push_back(newState.row);
            if (done.contains(t))
            {
                continue;
            }
            done[t] = newState.count;
            std::vector<std::vector<int64_t>> targetBoard = generateBoard(newState, A);
            if (isSameBoard(targetBoard, B))
            {
                result = target.count + 1;
                queue.clear();
                break;
            }
            else
            {
                queue.push_back(newState);
            }
        }
        std::vector<std::vector<int64_t>> rowCandidates = generateCandidates(target.row);
        for (int i = 0; i < rowCandidates.size(); ++i)
        {
            state newState = state{.column = target.column, .row = rowCandidates[i], .count = target.count + 1};
            std::vector<std::vector<int64_t>> t(0);
            t.push_back(newState.column);
            t.push_back(newState.row);
            if (done.contains(t))
            {
                continue;
            }
            done[t] = newState.count;
            std::vector<std::vector<int64_t>> targetBoard = generateBoard(newState, A);
            if (isSameBoard(targetBoard, B))
            {
                result = target.count + 1;
                queue.clear();
                break;
            }
            else
            {
                queue.push_back(newState);
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}