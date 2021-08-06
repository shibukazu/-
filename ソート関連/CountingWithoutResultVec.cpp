#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
/*
結果配列を用いない計数ソート
*/
int main()
{
  int N;
  cin >> N;
  vector<int> data(N);
  for (int i = 0; i < N; i++)
  {
    cin >> data[i];
  }
  int max = *(max_element(data.begin(), data.end()));
  vector<int> count(max + 1, 0);
  for (int i = 0; i < N; i++)
  {
    count[data[i]]++;
  }
  for (int i = 0; i <= max; i++)
  {
    int j = N - 1;
    while (count[i] > 0)
    {
      if (data[j] == i)
      {
        cout << data[j] << " ";
        count[i]--;
      }
      j--;
    }
  }
  cout << endl;
}