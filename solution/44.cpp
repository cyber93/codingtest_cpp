#include <vector>
#include <queue>
#include <limits>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
  vector<pair<int, int>> graph[N + 1];
  vector<int> distances(N + 1, numeric_limits<int>::max());
  vector<bool> visited(N + 1, false);
  distances[1] = 0; 

  //??諛⑺뼢???곕줈 ?놁쑝誘濡? ?묐갑??紐⑤몢 ?숈씪??媛以묒튂 ?낅젰
  for (const auto& r : road) {
    int a = r[0], b = r[1], cost = r[2];
    graph[a].push_back({b, cost});
    graph[b].push_back({a, cost});
  }

  //??異쒕컻?먯쓣 heap??異붽?
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
  heap.push({0, 1}); 

  while (!heap.empty()) {
    int dist = heap.top().first;
    int node = heap.top().second;
    heap.pop();

    //???대? 諛⑸Ц???몃뱶??臾댁떆
    if (visited[node]) continue; 
    visited[node] = true;

    for (const auto& next : graph[node]) {
      int next_node = next.first;
      int next_dist = next.second;
      int cost = dist + next_dist;

      //??嫄곗퀜媛???몃뱶濡?媛??寃쎈줈??鍮꾩슜????吏㏃? 寃쎌슦
      if (cost < distances[next_node]) {
        distances[next_node] = cost;
        heap.push({cost, next_node});
      }
    }
  }

  int count = 0;

  //?브굅由ш? K ?댄븯???μ냼瑜?移댁슫??
  for (int i = 1; i <= N; i++) {
    if (distances[i] <= K) count++;
  }

  return count;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  
  cout << solution(5, {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}, 3) << endl; //異쒕젰媛?: 4
  cout << solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4) << endl; //異쒕젰媛?: 4
  return 0;
}
