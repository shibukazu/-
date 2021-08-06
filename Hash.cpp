#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int SIZE = 100;

class Hash
{
  struct Node
  {
    bool deleted;
    bool empty;
    int num;
  };

private:
  vector<Node> table;
  int size;

public:
  Hash(int size)
  {
    size = size;
    table = vector<Node>{100, Node{false, true}};
  }
  int insert(int key)
  {
    int hash = key % 100;
    int i = hash;
    while (!table[i].deleted && !table[i].empty)
    {
      if (table[i].num == key)
      {
        return i;
      }
      i -= i;
      if (i < 0)
        i += 100;
    }
    table[i].empty = false;
    table[i].num = key;
    return -1;
  }
};
int main()
{
  Hash *h = new Hash(100);
  while (true)
  {
    int n;
    cin >> n;
    cout << h->insert(n) << endl;
  }
}