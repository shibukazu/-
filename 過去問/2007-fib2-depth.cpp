#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
vector<int> fib;
tuple<int, int> FIB(int n, int d)
{
  tuple<int, int> t1;
  tuple<int, int> t2;
  if (fib[n - 1] != 0)
    t1 = make_tuple(fib[n - 1], d);
  else
    t1 = FIB(n - 1, d + 1);
  if (fib[n - 2] != 0)
    t2 = make_tuple(fib[n - 2], d);
  else
    t2 = FIB(n - 2, d + 1);
  return make_tuple(get<0>(t1) + get<0>(t2), max(get<1>(t1), get<1>(t2)));
}
int main()
{
  fib = vector<int>(11);
  fib[1] = 1;
  fib[2] = 1;
  tuple<int, int> result = FIB(10, 0);
  cout << get<1>(result) << endl;
}