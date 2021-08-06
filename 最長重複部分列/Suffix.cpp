#include <bits/stdc++.h>
using namespace std;

int main()
{
  string INPUT;
  cin >> INPUT;
  vector<string> suffix(INPUT.size());
  //入力文字列のsuffixをすべて求める
  for (int i = 0; i < INPUT.size(); i++)
  {
    suffix[i] = &INPUT[i];
  }
  //suffixを辞書順ソートする
  sort(suffix.begin(), suffix.end());
  int max_size = 0;
  int max_pair_idx = -1;
  //隣接するsuffix同士のみを比較する
  for (int l = 0; l < suffix.size() - 1; l++)
  {
    int size = 0;
    while (size <= min(suffix[l].size(), suffix[l + 1].size()))
    {
      if (suffix[l][size] == suffix[l + 1][size])
        size++;
      else
        break;
    }
    if (size > max_size)
    {
      max_size = size;
      max_pair_idx = l;
    }
  }
  if (max_pair_idx == -1)
  {
    cout << "ペアは存在しない" << endl;
  }
  else
  {
    for (int i = 0; i < max_size; i++)
    {
      cout << suffix[max_pair_idx][i];
    }
    cout << endl;
  }
}