#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

//??源딆씠 ?곗꽑 ?먯깋(DFS)???섑뻾?섎뒗 ?⑥닔
void dfs(const vector<vector<int>>& network, int node) {
  visited[node] = true;

  for (int i = 0; i < network[node].size(); i++) {
    if (network[node][i] && !visited[i]) { 
      dfs(network, i);
    }
  }
}

int solution(int n, vector<vector<int>> computers) {
  visited = vector<bool>(computers.size(), false);

  int networkCount = 0; 

 //???ㅽ듃?뚰겕???섎? ?뺤씤
  for (int i = 0; i < computers.size(); i++) {
    if (!visited[i]) { 
      dfs(computers, i);
      networkCount++;
    }
  }

  return networkCount;
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

void init()
{
  visited.clear();
}
int main()
{
  
  cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl; //異쒕젰媛?: 2
  init();
  cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl; //異쒕젰媛?: 1

  return 0;
}
