#include <bits/stdc++.h>
using namespace std;
/*
  配列が与えられたときにinsertを用いずにmax-heapを構成するアルゴリズム
  計算量 : O(n)
*/
void maxHeapify(vector<int> &heap, int rootIdx);
int N;
int main()
{
  cin >> N;
  vector<int> heap(N);
  for (int i = 0; i < N; i++)
    cin >> heap[i];
  int rootIdx = floor((N - 1 - 1) / 2.0); //完全二分木とみなした時の最も端の親ノードが初期の部分木ルート
  /*
  各親ノードをrootノードとした部分木がヒープ条件を満たすようにする
  */
  for (; rootIdx >= 0; rootIdx--)
  {
    maxHeapify(heap, rootIdx);
  }
  for (int i = 0; i < N; i++)
  {
    cout << " " << heap[i];
  }
  cout << endl;
}
/*
  rootIdxを根とする部分木がヒープ条件を満たすようにする関数
*/
void maxHeapify(vector<int> &heap, int rootIdx)
{
  int leftChildIdx = rootIdx * 2 + 1;  //左の子
  int rightChildIdx = rootIdx * 2 + 2; //右の子

  if (leftChildIdx >= N && rightChildIdx >= N) //子がいない場合
    return;

  else if (rightChildIdx >= N) //左の子しかいない場合
  {
    if (heap[leftChildIdx] > heap[rootIdx])
    {
      swap(heap[leftChildIdx], heap[rootIdx]);
      maxHeapify(heap, leftChildIdx);
    }
  }
  
  
  else //子が二ついる場合
  {
    if (heap[leftChildIdx] > heap[rightChildIdx])
    {
      if (heap[leftChildIdx] > heap[rootIdx])
      {
        swap(heap[leftChildIdx], heap[rootIdx]);
        maxHeapify(heap, leftChildIdx);
      }
    }
    else
    {
      if (heap[rightChildIdx] > heap[rootIdx])
      {
        swap(heap[rightChildIdx], heap[rootIdx]);
        maxHeapify(heap, rightChildIdx);
      }
    }
  }
}