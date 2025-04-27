#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int dfs(int node, int parent, const vector<vector<int>>& graph) {
  int cnt = 1;
  //???몄젒?몃뱶?????源딆씠?곗꽑?먯깋 怨꾩냽 吏꾪뻾
  for (int child : graph[node]) {
    //??臾댄븳?먯깋??諛⑹??섍린 ?꾪빐 ?몄젒???몃뱶 以? 遺紐⑤끂?쒕뒗 ?먯깋?섏? ?딆쓬
    if (child != parent) {
      cnt += dfs(child, node, graph);
    }
  }
  return cnt;
}

int solution(int n, vector<vector<int>> wires) {
  vector<vector<int>> graph(n + 1);
  //??wire?뺣낫瑜??쒖슜?댁꽌 洹몃옒??援ъ텞
  for (auto &wire : wires) {
    int a = wire[0];
    int b = wire[1];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int min_diff = INT_MAX;
  for (auto &wire : wires) {
    int a = wire[0];
    int b = wire[1];

    //???뱀젙 ?꾩꽑???꾩떆濡???젣
    graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
    graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

    //???꾨젰留앹쓣 ?⑥젅?섍퀬 媛??꾨젰留앹쓽 ?≪쟾??媛쒖닔??李⑤? 援ы븿
    int cnt_a = dfs(a, b, graph);
    int cnt_b = n - cnt_a;

    //???꾩옱源뚯? 援ы븳 ?≪쟾?묒쓽 李⑥쓽 ?덈?媛믪쓽 理쒖냼媛믨낵 ?꾩옱 媛믪쨷 ???곸?媛믪쓣 ?앺븿
    min_diff = min(min_diff, abs(cnt_a - cnt_b));

    //???꾩떆濡??쒓굅?덈뜕 ?쒓굅?덈뜕 ?꾩꽑??蹂듦뎄
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  return min_diff;
}




//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  
  cout << solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}}) << endl; //異쒕젰媛?: 3
  cout << solution(4, {{1, 2}, {2, 3}, {3, 4}}) << endl; //異쒕젰媛?: 0
  cout << solution(7, {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}}) << endl; //異쒕젰媛?: 1
  return 0;
}
