#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
/*
全体の中央値をpivotとすることで次の問題サイズを3/4倍する
*/
int selectByMedian(vector<int> &target, int k, int l, int r)
{
  if (r - l <= 3)
  {
    sort(&target[l], &target[r]);
    return target[l + k - 1];
  }
  //全体を5つずつに分割し中央値を集める
  vector<int> medians(floor((r - l) / 5));
  for (int i = 0; i < medians.size(); i++)
  {
    sort(&target[l + 5 * i], &target[l + 5 * (i + 1) - 1]);
    medians[i] = target[l + 5 * i + 2];
  }
  //集めた中央値に対して再帰的実行し全体の中央値を取得
  int median;
  if (medians.size() > 0)
    median = selectByMedian(medians, medians.size() / 2 + 1, 0, medians.size());
  else
    median = target[l];
  //medianのidxを探索
  int medianIdx = distance(&target[l], find(&target[l], &target[r], median));
  //medianを左端に移動
  swap(target[l], target[medianIdx]);

  //以下medianをpivotとしてquickSelectを実行
  int pivot = median;
  int j = l;
  for (int i = l + 1; i < r; i++)
    if (target[i] < pivot)
      j++, swap(target[j], target[i]);
  swap(target[l], target[j]);
  int s1 = j - l;
  if (k <= s1)
    return selectByMedian(target, k, l, j);
  else if (k == s1 + 1)
    return target[j];
  else
    return selectByMedian(target, k - (s1 + 1), j + 1, r);
}
int main()
{
  int n;
  cin >> n;
  vector<int> inputs(n);
  for (int i = 0; i < n; i++)
    cin >> inputs[i];
  int k;
  cin >> k;
  cout << selectByMedian(inputs, k, 0, inputs.size()) << endl;
}