#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
vector<int> sizes;
//通常法＋高速構成法
void makeSizes(string pattern, string target)
{
  sizes[0] = -1;
  for (int j = 1; j < pattern.size(); j++)
  {
    int candidate = sizes[j - 1];
    while (true)
    {
      if (pattern[candidate] == pattern[j])
      {
        sizes[j] = candidate + 1;
        break;
      }
      else if (candidate > 0)
      {
        candidate = sizes[candidate];
      }
      else
      {
        sizes[j] = 0;
        break;
      }
    }
  }
}
int main()
{
  string pattern, target;
  cin >> target >> pattern;
  sizes = vector<int>(pattern.size());
  makeSizes(pattern, target);
  //以下マッチングを行う
  //i -> target内先頭インデックス
  //j -> pattern内参照インデックス
  //i + j -> target内参照インデックス
  int i = 0, j = 0;
  while (i + j < target.size())
  {
    if (target[i + j] == pattern[j])
    {
      if (j == pattern.size() - 1)
      {
        cout << "開始位置 : " << i << endl;
        break;
      }
      j++;
    }
    else
    {
      i += j - sizes[j];
      if (j > 0)
        j = sizes[j];
    }
  }
}
