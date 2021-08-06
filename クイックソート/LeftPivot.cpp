#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//pivot値が左端にある場合のクイックソート
void quickSort(vector<int> &, int, int);
int main()
{
  int n;
  cin >> n;
  vector<int> inputs(n);
  cout << "入力受付開始" << endl;
  for (int i = 0; i < n; i++)
    cin >> inputs[i];
  cout << "入力受付完了" << endl;
  quickSort(inputs, 0, n);
  cout << "ソート結果" << endl;
  for (int i = 0; i < n; i++)
    cout << inputs[i] << " ";
  cout << endl;
}
void quickSort(vector<int> &data, int l, int r)
{
  if (r <= l + 1)
    return;
  int pivot = data[l];
  int i = l + 1, j = l;
  //iの手前まで分割終了
  //jまでpivot以下である保証
  while (i < r)
  {
    if (data[i] <= pivot)
      j++, swap(data[j], data[i]);
    i++;
  }
  swap(data[j], data[l]);
  quickSort(data, l, j);
  quickSort(data, j + 1, r);
  return;
}
