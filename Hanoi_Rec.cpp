#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
vector<stack<int>> hanoi_table(3);
void hanoi(int from, int to, int work, int size)
{
  if (size == 1)
  {
    //stackのtopよりも大きければエラー
    if (!hanoi_table[to].empty() && hanoi_table[to].top() < hanoi_table[from].top())
    {
      cerr << "size error" << endl;
      exit(1);
    }
    else
    {
      hanoi_table[to].push(hanoi_table[from].top());
      hanoi_table[from].pop();
    }
  }

  else
  {
    hanoi(from, work, to, size - 1);
    hanoi(from, to, work, 1);
    hanoi(work, to, from, size - 1);
  }
}
int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    hanoi_table[0].push(n - i);
  hanoi(0, 1, 2, n);
  while (!hanoi_table[1].empty())
  {
    int num = hanoi_table[1].top();
    hanoi_table[1].pop();
    for (int j = 0; j < num; j++)
      cout << "*";
    cout << endl;
  }
}