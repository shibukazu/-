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
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; // テキストの文字数
  int m; // パターンの文字数
  cin >> n >> m;
  vector<char> text(n);    // テキスト配列
  vector<char> pattern(m); // パターン配列
  input_from_stdin(text, pattern);
  map<char, int> shifts; // テキスト内各文字が右端の場合にシフトする量を保存する連想配列

  for (int i = 0; i < m - 1; i++) //　パターン内最後の文字はシフト量 m より除外
  {
    shifts.insert_or_assign(pattern[i], m - i - 1); // パターンの左から調べることでパターン内で最も右の文字によるシフト量を設定できる
  }
  // パターンに存在しない文字に関しては条件分岐によって m シフトするため
  // パターン内に存在する文字のみシフト量を調べれば良い

  int i = 0;
  while (i < n - m + 1)
  {                                   // 最悪の場合パターンが末端に達するまで繰り返す
    char mostRight = text[i + m - 1]; // 最も右の値を保存する
    for (int j = m - 1; j >= 0; j--)
    {
      if (pattern[j] != text[i + j])
      {
        break;
      }
      if (j == 0)
      { // breakせずに j=0 となるのは全て一致している時のみ
        cout << "一致箇所の先頭インデックス : " << i << endl;
        return 0;
      }
    }
    //シフト量を決定する
    int shiftNum;
    if (shifts.find(mostRight) != shifts.end())
    {
      shiftNum = shifts[mostRight];
    }
    else
    {
      shiftNum = m;
    }
    i += shiftNum;
  }
  cout << "発見されませんでした" << endl;
  return 0;
}