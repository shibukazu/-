#include <bits/stdc++.h>
using namespace std;
void input_from_stdin(vector<char> &text, vector<char> &pattern)
{
  for (int i = 0; i < text.size(); i++)
  {
    cin >> text[i];
  }
  for (int i = 0; i < pattern.size(); i++)
  {
    cin >> pattern[i];
  }
}
/*
不一致文字規則による文字列照合
*/
int main()
{
  int n; // テキストの文字数
  int m; // パターンの文字数
  cin >> n >> m;
  vector<char> text(n);    // テキスト配列
  vector<char> pattern(m); // パターン配列
  input_from_stdin(text, pattern);
  vector<int> indexesInPattern(26, -1); //テキスト登場文字（アルファベット）のパターン内インデックス配列
  /*
  ①シフト量決定のためのパターン内インデックス配列の作成
  */
  for (int i = 0; i < m; i++)
  {
    //indexesInPatternにおけるindexを計算
    int idx = pattern[i] - 'a';
    indexesInPattern[idx] = i;
  } // 左から調べることで最右のインデックスを保存する

  /*
  ②テキストとパターンの照合を行う
  */
  int i = 0;
  while (i < n - m + 1)
  {
    int shiftNum;
    for (int j = m - 1; j >= 0; j--)
    {
      if (text[i + j] != pattern[j])
      {
        /*
        ③間違った場合indexesInPatternに基づいてシフト量を決定
        */
        int idx = pattern[j] - 'a';
        shiftNum = max(1, j - indexesInPattern[idx]);
        i += shiftNum;
        break;
      }
      if (j == 0)
      {
        cout << "一致箇所の先頭インデックス : " << i << endl;
        return 0;
      }
    }
  }
  cout << "発見されませんでした" << endl;
}