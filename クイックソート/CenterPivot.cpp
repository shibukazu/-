#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//pivot値が中央の値の場合のクイックソート
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
  int pivot = data[(r + l) / 2];
  int i = l, j = r - 1;
  /*特徴
  1.pivot位置は固定されない
  2.終了時のiとjがpivot位置を与える
  3.pivot値を超えてswapを行わないようにi++, j--の条件にpivot値と同じ場合は含まない
  */
  /*疑問①
  Q.同一の値を含んでも対応できるか
  A.pivotと同一の値があるとき無限ループに陥る。
          i   j
    1 2 3 4 2 4 7
    よってdata[i], data[j]ともにpivot値と同じ値であるとき
    強制的にiを1ステップ進める。するとiとjが一致して終了する。
    pivot位置である i = j はもとのpivotではないが本質的に値が同じであり問題ない。
  */
  /*疑問②
  Q.iがjを超えることは起こり得るか？
  A.起こり得ない。
    想定されるケースとしては
          i j
    1 2 3 4 4 5 7
    この状況ではiを1増加させる。
    そのときiとjが一致して終了するので起こり得ない
  */
  cout << i << " " << j << endl;
  while (i != j)
  {
    while (data[i] < pivot)
      i++;
    while (data[j] > pivot)
      j--;
    if (i >= j)
      break;
    swap(data[i], data[j]);
    i++, j--;
  }
  quickSort(data, l, i);
  quickSort(data, i + 1, r);
  return;
}
