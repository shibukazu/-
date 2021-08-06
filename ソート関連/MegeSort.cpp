#include <bits/stdc++.h>
using namespace std;
int SIZE;
vector<int> TARGET;
void MergeSort(int l, int r)
{
  if (r <= l + 1)
  {
    return;
  }
  int mid = floor((r + l) / 2.0);
  MergeSort(l, mid);
  MergeSort(mid, r);
  int count = l;
  //マージ用配列
  vector<int> d(SIZE);
  int i = l, j = mid;
  while (count < r)
  {
    if (i >= mid)
      d[count++] = TARGET[j++];
    else if (j >= r)
      d[count++] = TARGET[i++];
    else
    {
      if (TARGET[i] < TARGET[j])
        d[count++] = TARGET[i++];
      else
        d[count++] = TARGET[j++];
    }
  }

  for (int i = l; i < r; i++)
  {
    TARGET[i] = d[i];
  }
}
int main()
{
  cin >> SIZE;
  TARGET = vector<int>(SIZE);
  for (int i = 0; i < SIZE; i++)
    cin >> TARGET[i];
  MergeSort(0, SIZE);
  for (int i = 0; i < SIZE; i++)
  {
    cout << TARGET[i] << " ";
  }
  cout << endl;
}