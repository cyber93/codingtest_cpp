#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, vector<char>> adjList;
vector<char> result;
unordered_set<char> visited;

void dfs(char node) {
  //???꾩옱 node瑜?諛⑸Ц??紐⑸줉 諛?諛⑸Ц??寃쎈줈 異붽?
  visited.insert(node);
  result.push_back(node);

  //???꾩옱 node? ?몄젒???몃뱶 以? 諛⑸Ц?섏? ?딆? node?ㅼ뿉 ???源딆씠?곗꽑?먯깋??怨꾩냽 吏꾪뻾
  for (char neighbor : adjList[node]) {
    if (visited.find(neighbor) == visited.end()) {
      dfs(neighbor);
    }
  }
}

vector<char> solution(vector<pair<char, char>> graph, char start) {
  //???몄젒 由ъ뒪???앹꽦
  for (auto& edge : graph) {
    char u = edge.first;
    char v = edge.second;
    adjList[u].push_back(v);
  }

  //???쒖옉 ?몃뱶遺??源딆씠?곗꽑?먯깋 ?쒖옉
  dfs(start);
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
  visited.clear();
}
void print(vector<char> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<char>(cout, " "));
  cout << endl;
    
}

int main()
{
  //bool 諛섑솚????true??1, false??0 ?낅땲??
  print(solution({{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}}, 'A')); //異쒕젰媛?: A B C D E
  init();
  print(solution({{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'}}, 'A')); //異쒕젰媛?: A B D E F C

  return 0;
}
