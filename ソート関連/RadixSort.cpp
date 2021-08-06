#include <bits/stdc++.h>
using namespace std;

int main()
{
  int K, N; //桁数とデータ数
  vector<list<int>> buckets(10);
  vector<int> data(N);

  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> data[i];
  }
  //各桁ごとにバケットソートを実行
  for (int i = 0; i < K; i++)
  {
    for (int j = 0; j < N; j++)
    {
      //注目している桁の値の抽出
      int key = (data[j] / (int)(pow(10, i))) % 10;
      //注目している桁の値を元にバケット配列へ代入
      buckets[key].push_front(data[j]);
    }
    //data配列におけるインデックス
    int idx = N - 1;
    //バケット配列から取り出しを行う
    //データ配列の末尾から先頭へ向かって入れていくことで安定ソートとなる
    for (int j = 9; j >= 0; j--)
    {
      while (!buckets[j].empty())
      {
        data[idx--] = buckets[j].front();
        buckets[j].pop_front();
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    cout << " " << data[i];
  }
  cout << endl;
}