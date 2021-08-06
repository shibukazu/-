#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  int N;
  cin >> N;
  int f1 = 1;
  int f2 = 1;
  for (int i = 3; i <= N; i++)
  {
    int tmp = f1;
    f1 = f1 + f2;
    f2 = tmp;
  }
  cout << f1 << endl;
}