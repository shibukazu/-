#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int range_upper = 100;
/*
逆写像ソート
*/
int main()
{
  int N;
  cin >> N;
  vector<int> NUMS(N);
  for (int i = 0; i < N; i++)
    cin >> NUMS[i];
  vector<int> idxs(range_upper + 1, -1);
  for (int i = 0; i < N; i++)
    idxs[NUMS[i]] = i;
  for (int i = 0; i <= range_upper; i++)
    if (idxs[i] != -1)
      cout << NUMS[idxs[i]] << endl;
}