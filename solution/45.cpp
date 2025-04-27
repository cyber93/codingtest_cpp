#include <vector>
#include <queue>
#include <cstring>
#include <limits>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int STRAIGHT_COST = 100;
const int CORNER_COST = 600;
const int MAX_SIZE = 26;
const int INF = numeric_limits<int>::max();

struct Path {
  int y, x, direction;
};

bool isValid(int y, int x, int size) {
  return y >= 0 && y < size && x >= 0 && x < size;
}

int solution(vector<vector<int>> board) {
  int boardSize = static_cast<int>(board.size());
  int dist[MAX_SIZE][MAX_SIZE][4];
  memset(dist, -1, sizeof(dist));
  queue<Path> q;

  //???쒖옉 吏?먯쓽 諛⑺뼢???곕씪 鍮꾩슜???щ씪吏덉닔 ?덉쑝誘濡?紐⑤뱺 寃쎌슦????怨좊젮  
  q.push({0, 0, 1});
  q.push({0, 0, 3});
      
  dist[0][0][1] = 0;
  dist[0][0][3] = 0;

  while (!q.empty()) {
    auto [y, x, dir] = q.front();
    q.pop();

    int lastCost = dist[y][x][dir];
      
    //???꾩옱 吏?먯쓣 湲곗??쇰줈 ?대룞媛?ν븳 吏???뺤씤  
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
        
      //???ㅼ쓬 ?대룞???꾨낫 吏?먯씠 board?덉뿉 ?덈뒗 醫뚰몴?닿퀬, ?꾨젮媛 ?곌껐???덈뒗 寃쎌슦
      if (!isValid(ny, nx, boardSize) || board[ny][nx]) continue;

      int newCost = lastCost + (i == dir ? STRAIGHT_COST : CORNER_COST);
      
      //???꾩쭅 ?꾨낫 吏?먯쓣 諛⑸Ц?섏? ?딆븯嫄곕굹, ?댁쟾??援ы뻽??鍮꾩슜蹂대떎 ???곸? 鍮꾩슜??寃쎌슦
      if (dist[ny][nx][i] == -1 || dist[ny][nx][i] > newCost) {
        dist[ny][nx][i] = newCost;
        q.push({ny, nx, i});
      }
    }
  }

  //???꾩갑 吏?먭퉴吏 媛??紐⑤뱺 寃쎈줈 以?理쒖냼瑜??좏깮
  int answer = INF;
  for (int i = 0; i < 4; i++) {
    if (dist[boardSize - 1][boardSize - 1][i] != -1) {
      answer = min(answer, dist[boardSize - 1][boardSize - 1][i]);
    }
  }

  return answer == INF ? -1 : answer;
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  
  cout << solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}) << endl; //異쒕젰媛?: 900
  cout << solution({{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
) << endl; //異쒕젰媛?: 3800
  cout << solution({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}}) << endl; //異쒕젰媛?: 2100
  cout << solution({{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0}}) << endl; //異쒕젰媛?: 3200

  return 0;
}
