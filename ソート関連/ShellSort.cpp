#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
/*
シェルソート
間隔は h = 3 * h + 1　の数列により決定する
*/
int main()
{
  int N;
  cin >> N;
  vector<int> data(N);
  for (int i = 0; i < N; i++)
    cin >> data[i];
  int h = 1;
  //最初のhを決定
  while (h < N / 9)
    h = h * 3 + 1;
  while (h >= 1)
  {
    int origin = 0;
    //開始点によって各グループを判別
    while (origin < h)
    {
      //各グループごとに挿入ソート
      for (int i = origin; i < N; i += h)
      {
        int j = i;
        int k = j - h;
        while (k >= 0)
        {
          if (data[k] > data[j])
          {
            swap(data[k], data[j]);
            j = k;
            k = j - h;
          }
          else
            break;
        }
      }
      origin++;
    }
    h = (h - 1) / 3;
  }
  for (int i = 0; i < N; i++)
    cout << data[i] << " ";
  cout << endl;
}