#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  string STR1, STR2;
  cin >> STR1 >> STR2;
  vector<vector<int>> dp(STR1.size() + 1, vector<int>(STR2.size() + 1));
  //初期化
  for (int i = 0; i <= STR1.size(); i++)
    dp[i][0] = i;
  for (int i = 0; i <= STR2.size(); i++)
    dp[0][i] = i;

  for (int i = 1; i <= STR1.size(); i++)
  {
    for (int j = 1; j <= STR2.size(); j++)
    {
      dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + (STR1[i - 1] != STR2[j - 1] ? 1 : 0));
    }
  }
  cout << dp[STR1.size()][STR2.size()] << endl;
}