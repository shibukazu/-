#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//l,rは含まれる
//rの要素を基準とする
void quickSort(vector<int> &v, int l, int r)
{

  int key = v[(l + r) / 2];
  //iがkey以下ライン
  //jが比較終了ライン
  int i = l, j = r;
  //ループ後のi-1がkeyのインデックス
  while (1)
  {
    while (v[i] < key)
      i++;
    while (key < v[j])
      j--;
    if (i == j)
      break;
    swap(v[i], v[j]);
    if (v[i] == v[j])
      i++;
  }
  if (l < i - 1)
    quickSort(v, l, i - 1);
  if (j + 1 < r)
    quickSort(v, j + 1, r);
}
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }
  quickSort(v, 0, N - 1);
  for (int i = 0; i < N; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}