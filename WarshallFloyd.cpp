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
// Vi -> Vjへの最短コストを格納する二次元配列
vector<vector<ll>> minCosts;
int warshall_floyd();
int main()
{
  cin >> V >> E;
  adjList = vector<list<Edge *>>(V);
  minCosts = vector<vector<ll>>(V, vector<ll>(V, INFTY));
  for (int i = 0; i < E; i++)
  {
    int S, T, D;
    cin >> S >> T >> D;
    adjList[S].push_back(new Edge{S, T, D});
  }
  int code = warshall_floyd();
  if (code == 1)
  {
    cout << "NEGATIVE CYCLE" << endl;
  }
  else
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (minCosts[i][j] > 2 * (int)pow(10, 9))
        {
          cout << "INF"
               << " ";
        }
        else
        {
          cout << minCosts[i][j] << " ";
        }
      }
      cout << endl;
    }
  }
}
//負閉路が存在する場合エラーコード1を返す
int warshall_floyd()
{
  /*
  以下初期化
  */
  //何も経由することがない場合
  //最小コストは二つを結ぶ辺のコストに等しい
  for (int i = 0; i < adjList.size(); i++)
  {
    for (auto it = adjList[i].begin(); it != adjList[i].end(); it++)
    {
      Edge *edge = *(it);
      minCosts[edge->from][edge->to] = edge->cost;
    }
  }
  //自分から自分へはコスト0
  for (int i = 0; i < adjList.size(); i++)
    minCosts[i][i] = 0;

  /*
  以下最小コスト計算
  */
  //V0まで利用できる場合, V1まで利用できる場合,,,, をそれぞれ計算していく
  for (int k = 0; k < V; k++)
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        minCosts[i][j] = min(minCosts[i][j], minCosts[i][k] + minCosts[k][j]);
      }
    }
  }

  /*
  以下負閉路をもつか調べる
  */
  for (int i = 0; i < V; i++)
  {
    if (minCosts[i][i] < 0)
      return 1;
  }
  return 0;
}