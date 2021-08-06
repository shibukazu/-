#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  int n;
  cin >> n;
  vector<int> data(n);
  for (int i = 0; i < n; i++)
    cin >> data[i];
  for (int i = 0; i < n; i++)
  {
    int minv = data[i];
    int minidx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (data[j] < minv)
      {
        minv = data[j];
        minidx = j;
      }
    }
    swap(data[minidx], data[i]);
  }

  for (int i = 0; i < n; i++)
    cout << data[i] << " ";
  cout << endl;
}