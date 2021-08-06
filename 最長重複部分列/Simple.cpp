#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  string INPUT;
  cin >> INPUT;
  int max_size = 0;
  int max_start = 0;
  for (int s_start = 0; s_start < N; s_start++) //検索文字列の各スタート位置に対して
  {

    for (int s_size = 1; s_size <= N - s_start; s_size++) //検索文字列の各サイズに対して
    {

      int t_start = 0; //検索対象列（INPUT）のスタート位置
      while (t_start + s_size <= N)
      {
        //自明なマッチの除外
        if (t_start == s_start)
        {
          t_start++;
          continue;
        }

        for (int i = 0; i < s_size; i++)
        {
          //マッチングしなかった場合t_startをずらす
          if (INPUT[t_start + i] != INPUT[s_start + i])
          {
            t_start++;
            break;
          }
          //マッチングした場合max_sizeを更新
          else if (i == s_size - 1)
          {
            if (s_size > max_size)
            {
              max_size = s_size;
              max_start = t_start;
            }
            t_start++;
            break;
          }
        }
      }
    }
  }
  for (int i = max_start; i < max_start + max_size; i++)
  {
    cout << INPUT[i] << " ";
  }
  cout << endl;
}