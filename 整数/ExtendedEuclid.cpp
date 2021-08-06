#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//2値リターンができないのでポインタで扱う
void exEuclid(ll a, ll b, ll *x, ll *y)
{
  if (b == 0)
  {
    *x = 1, *y = 0;
    return;
  }
  exEuclid(b, a % b, y, x);
  *y -= (a / b) * *x;
}
int main()
{
  ll A, B;
  cin >> A >> B;
  ll x, y;
  exEuclid(A, B, &x, &y);
  cout << x << " " << y << endl;
}