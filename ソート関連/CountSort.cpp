#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
struct Node
{
  char sticker;
  int value;
};
//0-9の範囲の入力に対する計数ソート
int main()
{
  vector<Node *> inputs(5);
  vector<int> counter(10, 0);
  vector<Node *> result(5);
  for (int i = 0; i < 5; i++)
  {
    int n;
    char c;
    cin >> n >> c;
    inputs[i] = new Node{c, n};
  }
  for (int i = 0; i < 5; i++)
  {
    cout << inputs[i]->value << inputs[i]->sticker << " ";
  }
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    counter[inputs[i]->value]++;
  }
  for (int i = 8; i >= 0; i--)
  {
    counter[i] += counter[i + 1];
  }
  for (int i = 4; i >= 0; i--)
  {
    result[counter[inputs[i]->value]-- - 1] = inputs[i];
  }
  for (int i = 0; i < 5; i++)
  {
    cout << result[i]->value << result[i]->sticker << " ";
  }
  cout << endl;
}
/* テスト入力
9
a
5
b
9
c
9
d
1
a
*/