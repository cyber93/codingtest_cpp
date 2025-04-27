#include <vector>
#include <limits>
#include <tuple>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source) {
  vector<vector<pair<int, int>>> graph(num_vertices);

  //??媛꾩꽑?뺣낫瑜??쒖슜?댁꽌 ?몄젒由ъ뒪?몃? ?앹꽦
  for (auto& edge : edges) {
    int from, to, weight;
    tie(from, to, weight) = edge;
    graph[from].emplace_back(to, weight);
  }

 //???꾩옱源뚯? 援ы븳 理쒖냼鍮꾩슜??INF濡??ㅼ젙(?쒖옉?몃뱶???쒖쇅)
  vector<int> distance(num_vertices, INF);
  distance[source] = 0;

  //???뺤젏??媛쒖닔 -1 留뚰겮 理쒖냼鍮꾩슜??媛깆떊
  for (int i = 0; i < num_vertices - 1; ++i) {
    for (int u = 0; u < num_vertices; ++u) {
      for (const auto& [v, weight] : graph[u]) {
        if (distance[u] + weight < distance[v]) {
          distance[v] = distance[u] + weight;
        }
      }
    }
  }

  //???뚯쓽 ?쒗솚???덈뒗吏 ?뺤씤
  for (int u = 0; u < num_vertices; ++u) {
    for (const auto& [v, weight] : graph[u]) {
      if (distance[u] + weight < distance[v]) {
        return vector<int>(1, -1);
      }
    }
  }

  return distance;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>

using namespace std;


void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
    
}

int main()
{
  
  print(solution(5, {{0, 1, 4}, {0, 2, 3}, {0, 4, -6}, {1, 3, 5}, {2, 1, 2}, {3, 0, 7}, {3, 2, 4},{4, 2, 2}}, 0)); //異쒕젰媛?: 0 -2 -4 3 -6
  print(solution(4, {{0, 1, 5}, {0, 2, -1}, {1, 2, 2}, {2, 3,-2}, {3, 0, 2}, {3, 1, 6}}, 0)); //異쒕젰媛?: -1

  return 0;
}
