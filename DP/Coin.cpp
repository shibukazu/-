#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  int AMOUNT, NUMS;
  cin >> AMOUNT >> NUMS;
  vector<int> dp(AMOUNT + 1, 1000);
  dp[0] = 0;
  vector<int> coins(NUMS);
  for (int i = 0; i < NUMS; i++)
    cin >> coins[i];

  for (int i = 0; i < NUMS; i++)
  {
    for (int j = 0; j <= AMOUNT; j++)
    {
      if (j - coins[i] >= 0)
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      else
        dp[j] = dp[j];
    }
  }
  cout << dp[AMOUNT] << endl;
}