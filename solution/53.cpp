#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int n, m;

 //???꾩옱 ?꾩튂媛 寃뚯엫?먯쓣 踰쀬뼱?섎뒗吏 ?뺤씤
bool isOutOfBounds(int r, int c) {
  return r < 0 || r >= n || c < 0 || c >= m;
}
int playGame(vector<vector<int>>& board, int curR, int curC, int opR, int opC) {
  //???꾩옱 ?꾩튂媛 0??寃쎌슦??遺덇??ν븯誘濡??ㅽ뀦??0?쇰줈 諛섑솚  
  if (board[curR][curC] == 0) return 0;
  int bestSteps = 0;
    
  //???꾩옱 ?꾩튂瑜?湲곗??쇰줈 媛?ν븳 諛⑺뼢 紐⑤몢 ?뺤씤  
  for (int dir = 0; dir < 4; ++dir) {
    int nextR = curR + dx[dir];
    int nextC = curC + dy[dir];
    //???ㅼ쓬 ?꾩튂媛 踰붿쐞瑜?硫뗭뼱??寃쎌슦???먯깋?먯꽌 ?쒖쇅
    if (isOutOfBounds(nextR, nextC) || board[nextR][nextC] == 0) continue;
    //???꾩옱 ?꾩튂濡??대룞?대낫怨??ㅼ쓬 ??吏꾪뻾
    board[curR][curC] = 0;
    int steps = playGame(board, opR, opC, nextR, nextC) + 1;
    board[curR][curC] = 1;
      
    //???꾩옱源뚯? 援ы븳 理쒕? ?대룞?잛닔?, ?꾩옱 ?대룞?잛닔瑜?媛吏怨?理쒖꽑???ㅽ븯??寃쎌슦???대룞?잛닔瑜?援ы븿
    if (bestSteps % 2 == 0 && steps % 2 == 1) bestSteps = steps;
    else if (bestSteps % 2 == 0 && steps % 2 == 0) bestSteps = max(bestSteps, steps);
    else if (bestSteps % 2 == 1 && steps % 2 == 1) bestSteps = min(bestSteps, steps);
  }
  return bestSteps;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
  n = board.size();
  m = board[0].size();
    
  //?? 理쒖꽑???ㅽ븳寃쎌슦 ?대룞?잛닔瑜?諛섑솚  
  return playGame(board, aloc[0], aloc[1], bloc[0], bloc[1]);
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
  cout <<solution( {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << endl;//異쒕젰媛?: 5
  cout <<solution( {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << endl;//異쒕젰媛?: 4
  
  return 0;
}
