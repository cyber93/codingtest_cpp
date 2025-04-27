#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> adjList;
vector<int> result;

void bfs(int start) {
  unordered_set<int> visited;
  queue<int> q;

  // ???쒖옉 ?몃뱶 諛⑸Ц
  q.push(start);
  visited.insert(start);
  result.push_back(start);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    // ???꾩옱 ?몃뱶? ?몄젒???몃뱶 以??꾩쭅 諛⑸Ц?섏? ?딅뒗 ?몃뱶 諛⑸Ц
    for (int neighbor : adjList[node]) {
      if (visited.find(neighbor) == visited.end()) {
        q.push(neighbor);
        visited.insert(neighbor);
        result.push_back(neighbor);
      }
    }
  }
}

vector<int> solution(vector<pair<int, int>> graph, int start) {
  // ???몄젒 由ъ뒪???앹꽦
  for (auto &edge : graph) {
    int u = edge.first;
    int v = edge.second;
    adjList[u].push_back(v);
  }

  // ???쒖옉 ?몃뱶遺???덈퉬 ?곗꽑 ?먯깋 ?쒖옉
  bfs(start);

  return result;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>

using namespace std;


void init()
{
  adjList.clear();
  result.clear();
 
}
void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
    
}

int main()
{
  
  print(solution({{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9}}, 1)); //異쒕젰媛?: 1 2 3 4 5 6 7 8 9
  init();
  print(solution({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}, 1)); //異쒕젰媛?: 1 2 3 4 5 0
  return 0;
}
