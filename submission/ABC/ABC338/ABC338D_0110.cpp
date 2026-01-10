// ABC338D
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

/**
 *方針メモ欄
 *
 * # お気持ち
 *
 * # 入力
 *
 * # 事前準備(宣言周り,~を求めておく系のやつ)
 * * 用意しておくもの
 * std::vector<int64_t> v(N); // すべての橋が存在するときのその橋を通る経路の長さの総和
 * std::vector<int64_t> c(N); // すべての橋が存在するときのその橋を通る回数
 * int64_t result = INF; //答え
 *
 * # 具体的なロジック
 * v_diff べくたー
 * c_diff べくたー
 * 0<= i < M-1 繰り返す
 *  //Xi X_(i+1)の移動を行い、vを更新
 *  Xi<X(i+1)を保証するために、swapする
 *  その移動の最短経路←std::min(X(i+1)-Xi,N-(X(i+1)-Xi))
 *  最短経路がX(i+1)-Xiの場合:
 *    v_diff[Xi]+=最短経路
 *    v_diff[X(i+1)-1]-=最短経路
 *    c_diff[Xi]++;
 *    c_diff[X(i+1)-1]--;
 *  そうでない場合
 *    v_diff[X(i+1)]+=最短経路
 *    v_diff[Xi]-=最短経路
 *    c_diff[X(i+1)-1]++;
 *    c_diff[Xi]--;
 *
 * Vをv_diffの累積和として持つ
 * Cをc_diffの累積和として持つ
 * s = Vの中身を全部足す
 * 0< i <Nについて
 *  s_かなんかを作って以下をやる
 *  s-Viを引く
 *  sに((Ci*N)-Vi)を足す
 *  resultを最小更新
 *
 * # 出力
 *
 *
 */

int main()
{
    int64_t N, M;
    std::cin >> N >> M;
    std::vector<int64_t> X(M);
    for (int64_t i = 0; i < M; ++i)
    {
        int64_t x;
        std::cin >> x;
        X[i] = x - 1;
    }
    int64_t result = INT_FAST64_MAX;
    std::vector<int64_t> v_diff(N);
    std::vector<int64_t> c_diff(N);
    std::vector<int64_t> v(N);
    std::vector<int64_t> c(N);
    int64_t s = 0;
    for (int64_t i = 0; i < M - 1; ++i)
    {
        int64_t from = X[i];
        int64_t to = X[i + 1];
        if (to < from)
        {
            std::swap(to, from);
        }
        int64_t k = to - from;
        int64_t nearest = std::min(k, N - k);
        if (nearest == k)
        {
            v_diff[from] += nearest;
            v_diff[to] -= nearest;
            c_diff[from]++;
            c_diff[to]--;
        }
        else
        {
            v_diff[to] += nearest;
            v_diff[0] += nearest;
            v_diff[from] -= nearest;

            c_diff[to]++;
            c_diff[0]++;
            c_diff[from]--;
        }
        s += nearest;
    }
    v[0] = v_diff[0];
    c[0] = c_diff[0];
    for (int64_t i = 1; i < N; ++i)
    {
        v[i] += v[i - 1] + v_diff[i];
        c[i] += c[i - 1] + c_diff[i];
    }

    int64_t s_copy = s;
    for (int64_t i = 0; i < N; ++i)
    {
        s = s_copy;
        s -= v[i];
        s += ((c[i] * N) - v[i]);
        result = std::min(result, s);
    }
    std::cout << result << std::endl;
}