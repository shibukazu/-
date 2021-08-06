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
  for (int i = 1; i < n; i++)
  {
    int j = i - 1;
    int pivot = data[i];
    while (j >= 0)
    {
      if (data[j] > pivot)
      {
        data[j + 1] = data[j];
        if (j == 0)
          data[0] = pivot;
        j--;
      }
      else
      {
        data[j + 1] = pivot;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << data[i] << " ";
  cout << endl;
}