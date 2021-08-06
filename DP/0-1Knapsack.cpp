#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  int N, W;
  cin >> N >> W;
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  vector<int> values(N);
  vector<int> weights(N);
  for (int i = 0; i < N; i++)
  {
    cin >> values[i] >> weights[i];
  }
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (j - weights[i - 1] >= 0)
        //dpの行とvalues, weightsのインデックスは異なる
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  cout << *(max_element(dp[N].begin(), dp[N].end())) << endl;
}