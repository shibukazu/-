#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
  int A, B;
  cin >> A >> B;
  A = abs(A), B = abs(B);
  while (A % B != 0)
  {
    int r = A % B;
    A = B;
    B = r;
  }
  cout << B << endl;
}