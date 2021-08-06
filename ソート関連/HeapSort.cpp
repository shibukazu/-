#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
/*
単一配列によるヒープソート
末端から確定していくので最大ヒープである必要
*/
int main()
{
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];
  //-------------------------------
  //ヒープの構成
  //-------------------------------
  int root = floor((N - 1 - 1) / 2.0);
  while (root > 0)
  {
    int i = root;
    //子が一人でもいるかどうか
    while (2 * i + 1 < N)
    {
      //子が二人の場合
      if (2 * i + 2 < N)
      {
        int mi = V[2 * i + 1] > V[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
        if (V[i] > V[mi])
          break;
        else
        {
          swap(V[i], V[mi]);
          i = mi;
        }
      }
      //子が一人の場合
      else
      {
        if (V[i] > V[2 * i + 1])
          break;
        else
        {
          swap(V[i], V[2 * i + 1]);
          i = 2 * i + 1;
        }
      }
    }
    root--;
  }
  //-------------------------------
  //ソートの実行
  //-------------------------------
  //ルートの値を末端に後ろから前へどんどん入れていく
  int ei = N - 1;
  while (ei > 0)
  {
    swap(V[0], V[ei--]);
    int i = 0;
    while (2 * i + 1 <= ei)
    {
      //子が二人の場合
      if (2 * i + 2 <= ei)
      {
        int mi = V[2 * i + 1] > V[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
        if (V[i] > V[mi])
          break;
        else
        {
          swap(V[i], V[mi]);
          i = mi;
        }
      }
      //子が一人の場合
      else
      {
        if (V[i] > V[2 * i + 1])
          break;
        else
        {
          swap(V[i], V[2 * i + 1]);
          i = 2 * i + 1;
        }
      }
    }
  }
  //--------------------------
  //確認
  //-------------------------
  for (int i = 0; i < N; i++)
    cout << V[i] << " ";
  cout << endl;
}