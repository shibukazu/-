#include <bits/stdc++.h>
using namespace std;
struct Edge
{
  int to;
  int cost;
};
struct Node
{
  int idx;
  int cost;
};
int N;
vector<list<Edge *>> adjList;
vector<Node *> nodes;
void dijkstra()
{
  // ヒープの擬似的更新のための確定済み配列
  vector<bool> freezed(N);

  // 始点以外のコストを大きな値で初期化
  nodes[0] = new Node{0, 0};
  for (int i = 1; i < N; i++)
    nodes[i] = new Node{i, 200000};

  //発見済みでまだ未確定のノードをを保存する最小ヒープ
  priority_queue<Node *, vector<Node *>, function<bool(Node *, Node *)>>
      remainNodes([](Node *node1, Node *node2) { return node1->cost > node2->cost; });
  remainNodes.push(nodes[0]);

  //ヒープが空になるまで行う
  while (!remainNodes.empty())
  {
    Node *minNode = remainNodes.top();
    remainNodes.pop();

    //ヒープは擬似的に更新しているため確定済みのものが再度取り出されうる
    //確定済みのものを取り出した場合はスルー
    if (freezed[minNode->idx])
      continue;

    //取り出した時点で最小コストを確定
    freezed[minNode->idx] = true;

    for (auto it = adjList[minNode->idx].begin(); it != adjList[minNode->idx].end(); it++)
    {
      Edge *edge = *it;
      if (nodes[minNode->idx]->cost + edge->cost < nodes[edge->to]->cost)
      {
        nodes[edge->to]->cost = nodes[minNode->idx]->cost + edge->cost;
        //発見された場合、または更新があった場合はヒープに挿入することで擬似的なヒープの更新とする
        remainNodes.push(nodes[edge->to]);
      }
    }
  }
}
int main()
{
  cin >> N;
  adjList = vector<list<Edge *>>(N);
  nodes = vector<Node *>(N);
  for (int i = 0; i < N; i++)
  {
    int IDX, K;
    cin >> IDX >> K;
    for (int j = 0; j < K; j++)
    {
      int ADJIDX, COST;
      cin >> ADJIDX >> COST;
      Edge *edge = new Edge{ADJIDX, COST};
      adjList[IDX].push_back(edge);
    }
  }
  dijkstra();
  for (int i = 0; i < N; i++)
  {
    cout << nodes[i]->idx << " " << nodes[i]->cost << endl;
  }
}