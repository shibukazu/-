#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
/*
最長共通部分列を求めるアルゴリズム
*/
int main()
{
  string A, B;
  cin >> A >> B;
  vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
  for (int i = 1; i < A.size() + 1; i++)
  {
    for (int j = 1; j < B.size() + 1; j++)
    {
      if (A[i - 1] == B[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  int length = dp[A.size()][B.size()];
  cout << "最長共通部分列長 : " << length << endl;
  /*
  結果テーブル表示
  */
  for (int i = 0; i < A.size() + 1; i++)
  {
    for (int j = 0; j < B.size() + 1; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  /*
  バックトレース
  */
  vector<char> result(length);
  int i = A.size(), j = B.size();
  while (i > 0 || j > 0)
  {
    if (dp[i][j] == dp[i][j - 1])
      j = j - 1;
    else if (dp[i][j] == dp[i - 1][j])
      i = i - 1;
    else
    {
      result[--length] = A[i - 1];
      i = i - 1, j = j - 1;
    }
  }
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  cout << endl;
}