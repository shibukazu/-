#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
struct Edge
{
  int from;
  int to;
  int cost;
};
struct Node
{
  int idx;
  ll minCost;
};
const ll INFTY = numeric_limits<int>::max();
int V, E, START;
vector<list<Edge *>> adjList;
vector<Node *> nodes;
int bellman_ford();
int main()
{
  cin >> V >> E >> START;
  adjList = vector<list<Edge *>>(V);
  nodes = vector<Node *>(V);
  for (int i = 0; i < E; i++)
  {
    int S, T, D;
    cin >> S >> T >> D;
    adjList[S].push_back(new Edge{S, T, D});
  }
  int code = bellman_ford();
  if (code == 0)
  {
    for (int i = 0; i < V; i++)
    {
      Node *node = nodes[i];
      if (node->minCost >= 10000001)
      {
        cout << "INF" << endl;
      }
      else
      {
        cout << node->minCost << endl;
      }
    }
  }
  else
  {
    cout << "NEGATIVE CYCLE" << endl;
  }
}
// 負閉路が存在する場合エラーコード1を返す
int bellman_ford()
{
  /*
  以下初期化
  */
  //ダイクストラと同様に初期化する
  nodes[START] = new Node{START, 0};
  for (int i = 0; i < V; i++)
  {
    if (i == START)
      continue;
    nodes[i] = new Node{i, INFTY};
  }
  /*
  以下最小コスト計算
  */
  //|V|-1回,全ての辺について各頂点への最短距離の更新を試行する
  //->負閉路が存在しない場合はこれで最短距離が確定する
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < V; j++)
    {
      for (auto it = adjList[j].begin(); it != adjList[j].end(); it++)
      {
        Edge *edge = *(it);
        if (nodes[edge->to]->minCost > nodes[edge->from]->minCost + edge->cost)
        {
          nodes[edge->to]->minCost = nodes[edge->from]->minCost + edge->cost;
        }
      }
    }
  }

  /*
  以下負閉路の存在を調べる
  */
  for (int j = 0; j < V; j++)
  {

    for (auto it = adjList[j].begin(); it != adjList[j].end(); it++)
    {
      Edge *edge = *(it);
      //更新が行われる場合負閉路が存在する
      if (nodes[edge->to]->minCost > nodes[edge->from]->minCost + edge->cost)
      {
        return 1;
      }
    }
  }
  return 0;
}
