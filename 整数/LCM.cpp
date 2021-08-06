#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//n個の要素のLCMを考える
ll lcm(ll a, ll b)
{
  ll t1 = abs(a), t2 = abs(b);
  while (t1 % t2 != 0)
  {
    ll r = t1 % t2;
    t1 = t2;
    t2 = r;
  }
  ll gcd = t2;
  return a / gcd * b;
}
int main()
{
  deque<ll> q;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    ll A;
    cin >> A;
    q.push_back(A);
  }
  while (q.size() != 1)
  {
    ll a1 = q.front();
    q.pop_front();
    ll a2 = q.front();
    q.pop_front();
    q.push_back(lcm(a1, a2));
  }
  cout << q.front() << endl;
}