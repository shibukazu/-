#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
struct block
{
  bool isPrime;
  int primeFact;
};
int main()
{
  int N;
  cin >> N;
  vector<block> primeTable(N + 1, block{true});
  for (int i = 2; i * i <= N; i++)
  {
    if (primeTable[i].isPrime)
    {
      for (int j = 2; i * j <= N; j++)
      {
        primeTable[i * j].isPrime = false;
        primeTable[i * j].primeFact = i;
      }
    }
  }
  int next = N;
  while (!primeTable[next].isPrime)
  {
    cout << primeTable[next].primeFact << " ";
    next = next / primeTable[next].primeFact;
  }
  cout << " " << next << endl;
}