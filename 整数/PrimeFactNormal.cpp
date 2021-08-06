#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  int N;
  cin >> N;
  vector<int> counter((int)sqrt(N) + 1, 0);
  int target = N;
  for (int i = 2; i * i <= N; i++)
  {
    while (target % i == 0)
    {
      target /= i;
      counter[i]++;
    }
  }
  cout << N << ":";
  //素数の場合
  //targetにはNが残っている
  if (target == N)
  {
    cout << " " << N << endl;
  }
  //素数でない場合
  //targetには残りの素数または1が残っている
  else
  {
    for (int i = 2; i * i <= N; i++)
    {
      while (counter[i] > 0)
      {
        cout << " " << i;
        counter[i]--;
      }
    }
    if (target != 1)
      cout << " " << target;
    cout << endl;
  }
}