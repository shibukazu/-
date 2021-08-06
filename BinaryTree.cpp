#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
struct Node
{
  ll value;
  Node *parent;
  Node *leftChild;
  Node *rightChild;
};
Node *root = NULL;

void insert(ll key)
{
  Node *newNode = new Node{key, NULL, NULL, NULL};
  //木が空の場合rootにnewNodeを代入
  if (root == NULL)
  {
    root = newNode;
    return;
  }
  Node *parent = root;
  Node *child = root;
  // 初期子ノードをrootとして子ノードがなくなるまで進む
  while (child != NULL)
  {
    parent = child;
    if (key < parent->value)
    {
      child = parent->leftChild;
    }
    else
    {
      child = parent->rightChild;
    }
  }
  // 子ノードがnullの時の親ノードがparentになる
  newNode->parent = parent;
  if (key < parent->value)
  {
    parent->leftChild = newNode;
  }
  else
  {
    parent->rightChild = newNode;
  }
  return;
}
Node *find(ll key)
{
  Node *base = root;
  while (base != NULL)
  {
    if (base->value == key)
    {
      return base;
    }
    else
    {
      if (key < base->value)
      {
        base = base->leftChild;
      }
      else
      {
        base = base->rightChild;
      }
    }
  }
  return NULL;
}
void deleteKey(ll key)
{
  Node *target = find(key);
  if (target == NULL)
    return;
  ll childNum = 0;
  if (target->leftChild != NULL)
    childNum++;
  if (target->rightChild != NULL)
    childNum++;

  //削除するノードの子が0個の場合
  if (childNum == 0)
  {
    if (target == root)
    {
      root = NULL;
      free(target);
    }
    //削除するノードが左子ノードである場合
    else
    {
      if (target->parent->leftChild == target)
      {
        target->parent->leftChild = NULL;
        free(target);
      }
      //削除するノードが右子ノードである場合
      else
      {
        target->parent->rightChild = NULL;
        free(target);
      }
    }
  }

  //削除するノードの子が1個の場合
  else if (childNum == 1)
  {
    if (target == root)
    {
      Node *child = target->leftChild != NULL ? target->leftChild : target->rightChild;

      root = child;
      child->parent = NULL;
      free(target);
    }
    else
    {
      Node *child = target->leftChild != NULL ? target->leftChild : target->rightChild;
      //削除するノードが左子ノードである場合
      if (target->parent->leftChild == target)
      {
        target->parent->leftChild = child;
        child->parent = target->parent;
        free(target);
      }
      //削除するノードが右子ノードである場合
      else
      {
        target->parent->rightChild = child;
        child->parent = target->parent;
        free(target);
      }
    }
  }

  //削除するノードの子ノードが2個の場合
  //(次節点自体をコピーするからrootかどうかの場合分けは不要)
  /*
  中間順出力を乱さないために中間順出力で次に出力されるもの、
  つまりtargetの右の子を根とする部分木のうち、最も左の子孫を
  targetにコピーし、子孫は削除する
  */
  else
  {
    Node *parent = target->rightChild;
    Node *successor;
    while (parent != NULL)
    {
      Node *child = parent->leftChild;
      if (child == NULL)
      {
        successor = parent;
      }
      parent = child;
    }
    //次節点の値をtargetにコピー
    target->value = successor->value;
    //次節点自身が右の子かどうか
    bool isRightChild;
    if (successor->parent->rightChild == successor)
    {
      isRightChild = true;
    }
    else
    {
      isRightChild = false;
    }
    //次節点が右の子を持つ場合,親と繋げる(左の子を持たないことは保証される)
    if (successor->rightChild != NULL)
    {
      if (isRightChild)
      {
        successor->parent->rightChild = successor->rightChild;
        successor->rightChild->parent = successor->parent;
      }
      else
      {
        successor->parent->leftChild = successor->rightChild;
        successor->rightChild->parent = successor->parent;
      }
    }
    //次節点が子を持たない場合,親の子はNULL
    else
    {
      if (isRightChild)
      {
        successor->parent->rightChild = NULL;
      }
      else
      {
        successor->parent->leftChild = NULL;
      }
    }
    free(successor);
  }
}
void preParse(Node *);
void inParse(Node *);

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  for (ll i = 0; i < N; i++)
  {
    string order;
    cin >> order;
    if (order[0] == 'i')
    {
      ll key;
      cin >> key;
      insert(key);
    }
    else if (order[0] == 'f')
    {
      ll key;
      cin >> key;
      Node *result;
      result = find(key);
      if (result != NULL)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
    else if (order[0] == 'd')
    {
      ll key;
      cin >> key;
      deleteKey(key);
    }
    else
    {
      inParse(root);
      cout << endl;
      preParse(root);
      cout << endl;
    }
  }
}
void preParse(Node *base)
{
  if (base == NULL)
  {
    return;
  }
  else
  {
    cout << " " << base->value;
    preParse(base->leftChild);
    preParse(base->rightChild);
  }
}
void inParse(Node *base)
{
  if (base == NULL)
  {
    return;
  }
  else
  {
    inParse(base->leftChild);
    cout << " " << base->value;
    inParse(base->rightChild);
  }
}