#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//ナイーブなソートによるsuffix array
int main()
{
  string target, search;
  cout << "target : " << endl;
  cin >> target;
  cout << "search : " << endl;
  cin >> search;
  vector<int> suffixArray(target.size());
  iota(suffixArray.begin(), suffixArray.end(), 0);
  //suffixの先頭ポインタを持つsuffixArrayに対する辞書順ソート
  sort(suffixArray.begin(), suffixArray.end(), [target](auto const &i, auto const &j)
       {
         int minSize = min(target.size() - i, target.size() - j);
         for (int k = 0; k < minSize; ++k)
         {
           if ((&target[i])[k] == (&target[j])[k])
           {
             continue;
           }
           if ((&target[i])[k] > (&target[j])[k])
             return i < j;
           if ((&target[i])[k] < (&target[j])[k])
             return i > j;
         }
         if (target.size() - i > target.size() - j)
           return i < j;
         else
           return i > j;
       });
  //二分探索の実施
  int l = 0, r = suffixArray.size();
  while (l < r)
  {
    int c = (l + r) / 2;
    string suffix = &target[suffixArray[c]];
    for (int i = 0; i < min(suffix.size(), search.size()); i++)
    {
      if (search[i] == suffix[i])
      {
        if (i == min(suffix.size(), search.size()) - 1)
        {
          //最後まで一致するがsearchが残ってしまっている場合
          if (search.size() - 1 > i)
          {
            r = c;
            break;
          }
          //最後まで一致しsearchが残っていない場合
          else
          {
            cout << suffixArray[c] << "インデックスから始まる部分に検索文字列がありました" << endl;
            l = r;
            break;
          }
        }
        continue;
      }
      //searchの方が辞書順で前の場合
      else if (search[i] < suffix[i])
      {
        r = c;
        break;
      }
      //searchの方が辞書順であとの場合
      else if (search[i] > suffix[i])
      {
        l = c + 1;
        break;
      }
    }
  }
}