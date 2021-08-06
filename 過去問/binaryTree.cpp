#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
class BinaryTree
{
private:
  vector<int> T;

public:
  BinaryTree(int size)
  {
    this->T = vector<int>(size + 1, 0);
  }
  void insert(int k)
  {
    int n = 1;
    while (T[n] != 0)
    {
      if (T[n] > k)
        n = n * 2;
      else
        n = n * 2 + 1;
    }
    T[n] = k;
  }
  void print()
  {
    for (int i = 0; i < T.size(); i++)
    {
      cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < T.size(); i++)
    {
      cout << T[i] << " ";
    }
    cout << endl;
  }
  void delete_root(int k)
  {
    int root = 2 * k;
    while (T[root * 2 + 1] != 0)
      root = root * 2 + 1;
    T[k] = T[root];
    T[root] = 0;
    if (T[2 * root] != 0)
      delete_root(root);
  }
};
int main()
{
  BinaryTree *b = new BinaryTree(10);
  for (int i = 0; i < 7; i++)
  {
    int n;
    cin >> n;
    b->insert(n);
  }
  b->print();
  b->delete_root(1);
  b->print();
}