#include <vector>
#include <tuple>

using namespace std;

const int INF = 99999;
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int numNodes, const vector<tuple<int, int, int>> edges) {
  //??洹몃옒??諛?諛⑸Ц ?щ? 珥덇린??
  for (int i = 0; i < MAX_NODES; ++i) {
    fill_n(graph[i], MAX_NODES, INF);
    visited[i] = false;
  }
  
  //???낅젰諛쏆? 媛꾩꽑 ?뺣낫瑜?洹몃옒?꾨줈 ?쒗쁽
  for (const auto& [from, to, weight] : edges) {
    graph[from][to] = weight;
  }

  //???쒖옉 ?몃뱶瑜??쒖쇅??紐⑤뱺 ?몃뱶??理쒖냼 鍮꾩슜??INF濡?珥덇린??
  vector<int> distances(numNodes, INF);
  distances[start] = 0;

  for (int i = 0; i < numNodes - 1; ++i) {
    int minDistance = INF;
    int closestNode = -1;

    //??理쒖냼 嫄곕━ ?몃뱶 李얘린
    for (int j = 0; j < numNodes; ++j) {
      if (!visited[j] && distances[j] < minDistance) {
        minDistance = distances[j];
        closestNode = j;
      }
    }

    //??李얠? ?몃뱶瑜?諛⑸Ц 泥섎━
    visited[closestNode] = true;

    //???몄젒 ?몃뱶?????嫄곕━ ?낅뜲?댄듃
    for (int j = 0; j < numNodes; ++j) {
      int newDistance = distances[closestNode] + graph[closestNode][j];
      if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
        distances[j] = newDistance;
      }
    }
  }

  return distances;
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
  
  print(solution(0, 3, {{0, 1, 9},{0, 2, 3},{1, 0, 5},{2, 1, 1}})); //異쒕젰媛?: 0 4 3
  print(solution(0, 4, {{0, 1, 1}, {1, 2, 5}, {2, 3, 1}})); //異쒕젰媛?: 0 1 6 7
  return 0;
}
