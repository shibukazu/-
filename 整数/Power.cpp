#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
ll divisor = 1000000007;
ll power(ll m, ll n)
{
  if (n == 1)
    return m;
  else
  {
    if (n % 2 == 0)
      return power(m * m % divisor, n / 2);
    else
    {
      return (power(m * m % divisor, (n - 1) / 2) % divisor) * m % divisor;
    }
  }
}
int main()
{
  int M, N;
  cin >> M >> N;
  cout << power(M, N) << endl;
}