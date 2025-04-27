#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//???꾩옱移몄쓽 醫뚰몴? ?댁쟾移몄뿉???꾩옱移몄쑝濡?媛??鍮꾩슜
struct Pos {
  int r;
  int c;
  int heightDiff;
  bool operator<(const Pos &p) const {
    return heightDiff > p.heightDiff;
  }
};

int dy[4] = {-1, 0, 1, 0},  dx[4] = {0, 1, 0, -1};
bool visited[301][301];
//???ㅼ쓬 ?대룞??移몄씠 寃⑹옄 ?댁뿉 議댁옱?섎뒗 醫뚰몴?몄? ?뺤씤
bool isValid(int nr, int nc, int rows, int cols) {
  return nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc];
}

int solution(vector<vector<int>> land, int height) {
  int totalCost = 0;
  int rows = land.size(), cols = land[0].size();

  priority_queue<Pos> pq;
  pq.push({0, 0, 0});

  while (!pq.empty()) {
    Pos current = pq.top();
    pq.pop();

    //???대? 諛⑸Ц??移몄?, ??諛⑸Ц?섏? ?딆쓬
    if (visited[current.r][current.c])
      continue;
    //???꾩옱 移몄쑝濡??대룞?섎뒗 鍮꾩슜??異붽?
    totalCost += current.heightDiff;
    //???꾩옱移몄쓽 ?몄젒 移몄쓣 ?쒗쉶
    for (int i = 0; i < 4; i++) {
      int nr = current.r + dy[i], nc = current.c + dx[i];
      if (isValid(nr, nc, rows, cols)) {
        //???대룞媛?ν븳 移멸낵 ?꾩옱移몄쓽 ?믪씠李⑤? 援ы븿
        int diff = abs(land[current.r][current.c] - land[nr][nc]);
        //???믪씠李④? ?щ떎由??ㅼ튂 湲곗?蹂대떎 ??寃쎌슦
        if (diff > height)
          pq.push({nr, nc, diff});
        //???믪씠李④? ?щ떎由??ㅼ튂 湲곗?蹂대떎 ?ъ? ?딆? 寃쎌슦
        else
          pq.push({nr, nc, 0});
      }
    }
    //???꾩옱 移몄쓣 諛⑸Ц?щ?瑜??쒖떆
    visited[current.r][current.c] = true;
  }

  return totalCost;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i <= 300; i++)
    for(int j = 0; j <= 300; j++)
      visited[i][j] = 0;
}

int main()
{
  cout << solution({{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}}, 3) << endl; //異쒕젰媛?: 15
  init();
  cout << solution({{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}}, 1) << endl; //異쒕젰媛?: 18
  
  return 0;
}
