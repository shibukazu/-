#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
struct Node
{
  int n;
  Node *parent;
};
class UnionFind
{
  vector<Node *> nodes;

public:
  UnionFind(int N)
  {
    nodes = vector<Node *>(N);
    for (int i = 0; i < N; i++)
    {
      nodes[i] = new Node{i};
      nodes[i]->parent = nodes[i];
    }
  }
  Node *find(int x)
  {
    Node *child = nodes[x];
    Node *parent = child->parent;
    while (parent != child)
    {
      child = parent;
      parent = child->parent;
    }
    Node *root = parent;
    //発見したroot情報をもとに経路圧縮を行う
    child = nodes[x];
    while (child != root)
    {
      Node *next = child->parent;
      //経路圧縮
      child->parent = root;
      child = next;
    }
    return root;
  }
  void unite(int x, int y)
  {
    Node *rep1 = this->find(x);
    Node *rep2 = this->find(y);
    if (rep1 != rep2)
    {
      rep1->parent = rep2;
    }
  }
};
int main()
{
  int N, Q;
  cin >> N >> Q;
  UnionFind *uf = new UnionFind(N);
  for (int i = 0; i < Q; i++)
  {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0)
      uf->unite(x, y);
    else
    {
      if (uf->find(x) == uf->find(y))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
  }
}