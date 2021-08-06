#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
/*
配列による二分探索木
ゼロでなければノードが存在する(親がゼロなら子が非ゼロでも子は存在しないとみなす)
idx関係はヒープと同じとする
*/
class BinaryTree
{
private:
  int size;
  vector<int> tree;
  bool has_left_child(int p)
  {
    if (tree[p] == 0)
      return false;
    else
    {
      int l = p * 2, r = p * 2 + 1;
      if (tree[l] != 0)
        return true;
      else
        return false;
    }
  }

public:
  BinaryTree()
  {
    size = 1000;
    tree = vector<int>(size, 0);
  }
  void insert(int key)
  {
    int p = 1, l = p * 2, r = p * 2 + 1;
    while (tree[p] != 0)
    {
      if (key < tree[p])
        p = l;
      else
        p = r;
      l = p * 2;
      r = p * 2 + 1;
    }
    tree[p] = key;
  }
  void del_root_key(int target)
  {
    int l = target * 2, r = target * 2 + 1;
    //1. 子を持たない場合
    if (tree[l] == 0 && tree[r] == 0)
      tree[target] = 0;
    //2. 子を２つ持つ場合
    else if (tree[l] != 0 && tree[r] != 0)
    {
      //右部分木の中で最も左に位置するノードのidx
      int s = r;
      while (this->has_left_child(s))
        s = s * 2;
      tree[target] = tree[s];
      this->del_root_key(s);
    }
    //3. 子を一つ持つ場合
    else if (tree[l] != 0)
    {
      tree[target] = tree[l];
      this->del_root_key(l);
    }
    else
    {
      tree[target] = tree[r];
      this->del_root_key(r);
    }
  }
  //中順出力
  void print(int p)
  {
    int l = p * 2, r = p * 2 + 1;
    if (tree[l] != 0)
      this->print(l);
    cout << tree[p] << endl;
    if (tree[r] != 0)
      this->print(r);
  }
};
int main()
{
  int N;
  cin >> N;
  BinaryTree *bt = new BinaryTree();
  for (int i = 0; i < N; i++)
  {
    int n;
    cin >> n;
    bt->insert(n);
  }
  cout << "--------------------------------" << endl;
  cout << "中順出力チェック" << endl;
  bt->print(1);
  cout << "--------------------------------" << endl;
  cout << "削除個数" << endl;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    bt->del_root_key(0);
    cout << "--------------------------------" << endl;
    cout << "中順出力チェック" << endl;
    bt->print(1);
    cout << "--------------------------------" << endl;
  }
}