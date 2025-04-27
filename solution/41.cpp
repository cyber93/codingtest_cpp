#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 100;
const int dx[4] = {-1, 0, 1, 0}; 
const int dy[4] = {0, 1, 0, -1}; 
int check[MAX_SIZE][MAX_SIZE];

//??醫뚰몴 ?뺣낫 諛?愿???곗궛???섍린 ?꾪븳 援ъ“泥?
struct Point {
  int y, x;

  Point(int y, int x) : y(y), x(x) {}

  bool isValid(int width, int height) const {
    return y >= 0 && y < height && x >= 0 && x < width;
  }

  Point move(int i) const {
    return Point(y + dy[i], x + dx[i]);
  }

  bool canMoveTo(const vector<vector<int>>& maps) const {
    return maps[y][x] == 1 && check[y][x] == 0;
  }
};

queue<Point> q; // BFS瑜??꾪븳 ??

int solution(vector<vector<int>> maps) {
  int width = maps[0].size(), height = maps.size();
  q.push({0, 0});
  check[0][0] = 1;

  // ???덈퉬?곗꽑?먯깋 吏꾪뻾
  while (!q.empty()) {
    Point current = q.front();
    q.pop();
   //???꾩옱醫뚰몴 湲곗??쇰줈 ?곹븯醫뚯슦瑜??뺤씤
    for (int i = 0; i < 4; i++) {
      Point next = current.move(i);
      //??踰붿쐞??醫뚰몴?닿퀬 踰쎌씠 ?꾨땶 寃쎌슦
      if (next.isValid(width, height) && next.canMoveTo(maps)) {
        check[next.y][next.x] = check[current.y][current.x] + 1;
        q.push({next.y, next.x});
      }
    }
  }

 //??紐⑹쟻吏???꾨떖媛???щ?瑜??뺤씤 
  int destinationX = width - 1, destinationY = height - 1;
  if (check[destinationY][destinationX] == 0) {
    return -1; // ?꾩갑 吏?먯뿉 ?꾨떖?????놁쓬
  }

  return check[destinationY][destinationX]; // ?꾩갑 吏?먭퉴吏??理쒕떒 嫄곕━ 諛섑솚
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i < MAX_SIZE; i++)
    for(int j = 0 ; j < MAX_SIZE; j++)
      check[i][j] = false;
}
int main()
{
  
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl; //異쒕젰媛?: 11
  init();
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}}) << endl; //異쒕젰媛?: -1

  return 0;
}
