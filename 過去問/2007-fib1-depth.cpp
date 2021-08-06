#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
tuple<int, int> FIB(int n, int d)
{
  if (n <= 2)
    return make_tuple(1, d);
  else
  {
    tuple<int, int> t1 = FIB(n - 1, d + 1);
    tuple<int, int> t2 = FIB(n - 2, d + 1);
    return make_tuple(get<0>(t1) + get<0>(t2), max(get<1>(t1), get<1>(t2)));
  }
}
int main()
{
  tuple<int, int> result = FIB(10, 0);
  cout << get<1>(result) << endl;
}