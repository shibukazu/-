#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  int N;
  cin >> N;
  vector<int> INPUTS(N);
  for (int i = 0; i < N; i++)
  {
    cin >> INPUTS[i];
  }
  int max = *(max_element(INPUTS.begin(), INPUTS.end()));
  //sqrt(最大値)までの範囲でふるい落としを行う
  vector<bool> number_table(max + 1, true);
  for (int i = 2; i <= sqrt(max); i++)
  {
    if (number_table[i])
    {
      for (int j = 2; i * j <= max; j++)
      {
        number_table[i * j] = false;
      }
    }
  }
  int count = 0;
  for (auto it = INPUTS.begin(); it != INPUTS.end(); it++)
  {
    if (number_table[*(it)])
      count++;
  }
  cout << count << endl;
}