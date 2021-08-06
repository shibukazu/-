#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
//末端idxを更新するべき場所を二分探索する
//新規の値より大きいものの中で最小のものを見つける
int binarySearch(vector<int> &lastIdxes, int value)
{
  int l = 0, r = lastIdxes.size();
  int candidate;
  while (l < r)
  {
    //固定サイズに対しては線形探索するO(1)
    if (r - l <= 3)
    {
      int result = l;
      while (lastIdxes[result] < value && result < r)
        result++;
      //resultは新規の値よりも大きいものの中で最小のはず
      return result;
    }
    int mid = (l + r) / 2;
    if (value < lastIdxes[mid])
      r = mid;
    else
      l = mid;
  }
  return -1;
}
int main()
{
  int N;
  cin >> N;
  //各サイズの増加部分列における最小の末端idx
  vector<int> lastIdxes(N, INT_MAX);
  //-----------back trace用
  //入力データ保管
  vector<int> data(N);
  //各入力に対する最大の増加部分列長さ(バックトレース用)
  vector<int> maxLengthes(N);
  //各入力に対する最大の増加部分列長さを与えるときの一つ手前の値(バックトレース用)
  vector<int> preValue(N);
  //-------------
  for (int i = 0; i < N; i++)
  {
    int VALUE;
    cin >> VALUE;
    int updateIdx = binarySearch(lastIdxes, VALUE);
    //---------- back trace用
    data[i] = VALUE;
    maxLengthes[i] = updateIdx + 1;
    if (updateIdx > 0)
      preValue[i] = lastIdxes[updateIdx - 1];
    else
      preValue[i] = -1;
    //------------
    lastIdxes[updateIdx] = VALUE;
  }
  for (int i = 0; i < lastIdxes.size(); i++)
  {
    if (lastIdxes[i] == INT_MAX)
    {
      int maxLen = i;
      cout << maxLen << endl;
      //-------back trace
      //最大サイズを与える入力のインデックスを見つける
      //そのインデックスからスタートしてpreValueを探索し続ける
      int maxLenIdx = maxLengthes.size() - 1;
      while (maxLengthes[maxLenIdx] != maxLen)
        maxLenIdx--;
      int backTraceIdx = maxLenIdx;
      cout << data[backTraceIdx] << " ";
      while (1)
      {
        int nextBackTraceIdx = backTraceIdx - 1;
        while (data[nextBackTraceIdx] != preValue[backTraceIdx])
          nextBackTraceIdx--;
        backTraceIdx = nextBackTraceIdx;
        cout << data[backTraceIdx] << " ";
        if (preValue[backTraceIdx] == -1)
          break;
      }
      //---------
      return 0;
    }
  }
  cout << lastIdxes.size() << endl;
  return 0;
}