#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
vector<int> table1;
vector<int> table2;
string pattern, text;
void constructTable1();
void constructTable2();
int calcShift1(int, int);
int calcShift2(int);
int main()
{
  cin >> text >> pattern;
  table1 = vector<int>(128, -1);        //方針1によるシフト量計算のためのテーブルはASCIIコード分確保する
  table2 = vector<int>(pattern.size()); //方針2によるシフト量のテーブルはパターンのサイズ分確保する
  constructTable1();
  constructTable2();
  int i = 0, j = pattern.size() - 1;
  while (i + j < text.size())
  {
    if (text[i + j] == pattern[j])
    {
      j--;
      if (j < 0)
      {
        cout << "先頭idx : " << i << endl;
        return 0;
      }
    }
    else
    {
      i += max(calcShift1(i, j), calcShift2(j));
      j = pattern.size() - 1;
    }
  }
  cout << "発見されませんでした" << endl;
  return 0;
}
/*
方針1:
  不一致位置のテキスト内文字が一致するようにシフトする
constructTable1:
  シフト量決定のための各ASCII文字のパターン内インデックスをテーブルに保存する
calcShift1:
  誤り位置i+jに基づきシフト量を計算する
*/
void constructTable1()
{
  for (int j = 0; j < pattern.size(); j++)
    table1[pattern[j]] = j;
};
int calcShift1(int i, int j)
{
  return max(1, j - table1[text[i + j]]);
}

/*
方針2:
  不一致位置のパターン内文字の手前まで(一致した部分）が一致するようにシフトする(ナイーブな実装)
constructTable2:
  パターン内の各位置において誤りが発生したときに4つのパターンをチェックし、最小のシフト量をシフト量とする
calcShift2:
  誤り位置jに基づきシフト量を計算する
*/
void constructTable2()
{
  //パターン内各文字に対して以下の4つのパターンを考え、最小のものを採用する
  //(実装の都合上シフト量=pattern.size()のものをデフォルトとしてはじめに計算している)
  for (int j = 0; j < pattern.size(); j++)
  {
    /*
    パターン1:
      以下のいずれも満たさない場合
    */
    table2[j] = pattern.size();
    /*
    パターン2:
      誤り位置がパターンの末端の場合
    */
    if (j == pattern.size() - 1)
      table2[j] = 1 < table2[j] ? 1 : table2[j];
    /*
    パターン3:
      誤り位置より手前が完全に含まれる場合
    */
    int i = 0, k = 0;
    while (i + k < j)
    {
      if (pattern[i + k] == pattern[j + k])
      {
        k++;
        if (j + k == pattern.size())
          table2[i] = j + 1 - i < table2[j] ? j + 1 - i : table2[j];
      }
      else
      {
        i++, k = 0;
      }
    }
    /*
    パターン4:
      誤り位置より手前の一部が含まれる場合（誤り位置の前後でのprefixとsuffixの一致）
    */
    for (int size = min(j - 0, (int)pattern.size() - 1 - j); size > 0; size--)
    {
      int k = 0;
      while (k < size)
      {
        if (pattern[0 + k] == pattern[pattern.size() - size + k])
          k++;
        else
          break;
      }
      if (k == size)
      {
        table2[i] = pattern.size() - size < table2[j] ? pattern.size() - size : table2[j];
        break;
      }
    }
  }
}
int calcShift2(int j)
{
  return table2[j];
}