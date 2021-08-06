#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
vector<int> shifts;
//京大法＋通常構成法
void makeShifts(string pattern, string target)
{
  for (int j = 0; j < pattern.size(); j++)
  {
    int size = j - 1;
    bool found = false;
    while (size > 0 && !found)
    {
      for (int i = 0; i < size; i++)
      {
        if (pattern[i] != pattern[j - size + i])
        {
          size--;
          break;
        }
        else if (i == size - 1 && pattern[size] != pattern[j])
        {
          found = true;
          break;
        }
      }
    }
    if (size <= 0)
    {
      if (pattern[j] == pattern[0])
        shifts[j] = j + 1;
      else
        shifts[j] = j - 0;
    }
    else
      shifts[j] = j - size;
  }
}
int main()
{
  string pattern, target;
  cin >> target >> pattern;
  shifts = vector<int>(pattern.size());
  makeShifts(pattern, target);
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
      i += shifts[j];
      if (shifts[j] > j)
        j = 0;
      else
        j = j - shifts[j];
    }
  }
}
