#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
/*
O(n^(log2 3))で行えるかけ算
*/
int multiple(int a, int b)
{
  //大きい方のビット数をnとする
  int n = 1;
  int tmp1 = a, tmp2 = b;
  while (tmp1 > 1 || tmp2 > 1)
  {
    n++;
    tmp1 /= 2, tmp2 /= 2;
  }
  if (n <= 1)
  {
    return a * b;
  }
  int mask = (1 << n / 2) - 1;
  //aの前半ビット
  int a1 = a >> (n / 2);
  //aの後半n/2ビット
  int a2 = a & mask;
  //bの前半ビット
  int b1 = b >> (n / 2);
  //bの後半n/2ビット
  int b2 = b & mask;

  int a1b1 = multiple(a1, b1);
  int a1a2b1b2 = multiple(a1 + a2, b1 + b2);
  int a2b2 = multiple(a2, b2);
  //n = n/2 *2とは限らないので n/2 * 2で表現
  return (a1b1 << n / 2 * 2) + ((a1a2b1b2 - a1b1 - a2b2) << (n / 2)) + a2b2;
}
int main()
{
  int a, b;
  cin >> a >> b;
  cout << multiple(a, b) << endl;
}