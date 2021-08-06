#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//k番目の値を再帰的にクイックサーチする
int quickSelect(vector<int> &target, int k, int l, int r)
{
  int pivot = target[l];
  //iは調べる対象のインデックス
  //jはj以下がpivot以下となっているようなインデックス
  int j = l;
  for (int i = l + 1; i < r; i++)
    if (target[i] < pivot)
      j++, swap(target[j], target[i]);
  //pivotを境界へ移動
  swap(target[l], target[j]);
  //pivotより小さい値からなるグループのサイズを計算
  int s1 = j - l;
  //検索したいk番目とs1との関係から次のquickSelectを実行
  if (k <= s1)
    return quickSelect(target, k, l, j);
  else if (k == s1 + 1)
    return target[j];
  else
    return quickSelect(target, k - (s1 + 1), j + 1, r);
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
  cout << quickSelect(inputs, k, 0, inputs.size()) << endl;
}