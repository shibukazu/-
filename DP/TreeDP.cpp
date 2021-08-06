#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//https://atcoder.jp/contests/dp/tasks/dp_p
//自分が黒の場合と白の場合の自分をルートとする組み合わせ数を保持
int rec(int root)
{
  int childN;
  for (int i = 0; i < N; i++)
  {
    edges[root][]
  }
}
int main()
{
  int N;
  cin >> N;
  vector<vector<int>> edges(N, vector<int>(N, 0));
  for (int i = 0; i < N - 1; i++)
  {
    int X, Y;
    cin >> X >> Y;
    edges[X][Y] = 1;
    edges[Y][X] = 1;
  }
  vector<int> b(N);
  vector<int> w(N);
}