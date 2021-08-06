#include <bits/stdc++.h>
using namespace std;
/*
  max-heapを実現するクラス
  オーダー: 
    insert O(logn)
    pop_max O(logn)
*/
class Heap
{
public:
  vector<int> heap;
  int rearIdx = -1;
  Heap(int size)
  {
    this->heap = vector<int>(size);
  }
  void insert(int key)
  {
    heap[++rearIdx] = key;
    int targetIdx = rearIdx;
    int parentIdx = floor((targetIdx - 1) / 2.0);
    //ヒープ条件が満たされるまで下から上へたどる
    while (parentIdx >= 0)
    {
      if (heap[targetIdx] > heap[parentIdx])
      {
        swap(heap[targetIdx], heap[parentIdx]);
        targetIdx = parentIdx;
        parentIdx = floor((targetIdx - 1) / 2.0);
      }
      else
        break;
    }
  }
  int pop_max()
  {
    int result = heap[0];
    //根の位置に末端の値を移動する
    heap[0] = heap[rearIdx];
    //末端にはどの値よりも小さい値を格納することで必ず交換が起きないようにする
    heap[rearIdx] = INT_MIN;
    //readIdxを減少させることで入っていないことにする
    rearIdx--;
    int parentIdx = 0;
    int leftChildIdx = 2 * parentIdx + 1;
    int rightChildIdx = 2 * parentIdx + 2;

    while (leftChildIdx <= rearIdx || rightChildIdx <= rearIdx)
    {
      //子が二つの場合
      if (leftChildIdx <= rearIdx && rightChildIdx <= rearIdx)
      {
        //子のどちらかが親より大きい場合->swap
        if (heap[leftChildIdx] > heap[parentIdx] || heap[rightChildIdx] > heap[parentIdx])
        {
          if (heap[leftChildIdx] > heap[rightChildIdx])
          {
            swap(heap[parentIdx], heap[leftChildIdx]);
            parentIdx = leftChildIdx;
            leftChildIdx = 2 * parentIdx + 1;
            rightChildIdx = 2 * parentIdx + 2;
          }
          else
          {
            swap(heap[parentIdx], heap[rightChildIdx]);
            parentIdx = rightChildIdx;
            leftChildIdx = 2 * parentIdx + 1;
            rightChildIdx = 2 * parentIdx + 2;
          }
        }
        //子のどちらも親より小さい場合->終了
        else
        {
          break;
        }
      }
      //子が一つの場合(左の子に限定できる)
      else
      {
        //子が親より大きい場合->swap
        if (heap[leftChildIdx] > heap[parentIdx])
        {
          swap(heap[parentIdx], heap[leftChildIdx]);
          parentIdx = leftChildIdx;
          leftChildIdx = 2 * parentIdx + 1;
          rightChildIdx = 2 * parentIdx + 2;
        }
        //子が親より小さい場合->終了
        else
        {
          break;
        }
      }
    }
    return result;
  }
  //削除位置に挿入後、親との大小関係は保証できないからこれは無理そう
  void delete_i(int i)
  {
    cout << "削除値 : " << heap[i] << endl;
    heap[i] = heap[rearIdx];
    rearIdx--;
    while (true)
    {
      //子が２つの場合
      if (2 * i + 2 < rearIdx)
      {
        if (heap[2 * i + 2] > heap[2 * i + 1])
        {
          if (heap[2 * i + 2] > heap[i])
          {
            swap(heap[2 * i + 2], heap[i]);
            i = i * 2 + 2;
          }
        }
        else
        {
          if (heap[2 * i + 1] > heap[i])
          {
            heap[i] = heap[2 * i + 1];
            i = i * 2 + 1;
          }
        }
      }
      //子が一つの場合
      else if (2 * i + 1 < rearIdx)
      {
        if (heap[2 * i + 1] > heap[i])
        {
          swap(heap[2 * i + 1], heap[i]);
          i = 2 * i + 1;
        }
      }
      //子がいない場合
      else
      {
        break;
      }
    }
  }
  void print()
  {
    cout << "i "
         << "value" << endl;
    for (int i = 0; i <= rearIdx; i++)
    {
      cout << i << " " << heap[i] << endl;
    }
    cout << endl;
  }
};
int SIZE = 2000;
int main()
{
  Heap *heap = new Heap(SIZE);
  while (1)
  {
    string order;
    cin >> order;
    if (order == "end")
      break;
    else if (order[0] == 'i')
    {
      int key;
      cin >> key;
      heap->insert(key);
    }
    else if (order[0] == 'e')
    {
      int result;
      result = heap->pop_max();
      cout << result << endl;
    }
    else if (order[0] == 'p')
    {
      heap->print();
    }
    else if (order[0] == 'd')
    {
      int i;
      cin >> i;
      heap->delete_i(i);
    }
  }
}