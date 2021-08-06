#include <bits/stdc++.h>
using namespace std;
queue<int> PREORDER;
vector<int> INORDER;
//二分木を再構成し、後順で出力するアルゴリズム
void reconstruct(int l, int r)
{
  if (r <= l)
  {
    return;
  }
  int root = PREORDER.front();
  PREORDER.pop();
  int idx; // INORDER内でのrootノードのインデックス
  for (int i = l; i < r; i++)
  {
    if (INORDER[i] == root)
    {
      idx = i;
    }
  }
  //INORDERの部分配列内をidxで分割する
  reconstruct(l, idx);
  reconstruct(idx + 1, r);
  //後順出力のためここで出力する
  cout << root << " ";
}
int main()
{
  int SIZE;
  cin >> SIZE;
  INORDER = vector<int>(SIZE);
  for (int i = 0; i < SIZE; i++)
  {
    int VALUE;
    cin >> VALUE;
    PREORDER.push(VALUE);
  }
  for (int i = 0; i < SIZE; i++)
  {
    cin >> INORDER[i];
  }
  reconstruct(0, SIZE);
}