#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board) {
  //??二쇱뼱吏?2李⑥썝 蹂대뱶???됯낵 ?댁쓽 媛쒖닔瑜?蹂?섏뿉 ??ν빀?덈떎.
  int ROW = board.size(), COL = board[0].size();

  //??媛??됯낵 ?댁쓣 ?쒗쉶?섎ŉ 媛?????뺤궗媛곹삎??湲몄씠 ?뺤씤
  for (int i = 1; i < ROW; ++i) {
    for (int j = 1; j < COL; ++j) {
      //???꾩옱 ?꾩튂??媛믪씠 1??寃쎌슦
      if (board[i][j] == 1) {
        //???꾩옱 ?꾩튂?먯꽌 ?? ?쇱そ, ?媛곸꽑 ?쇱そ ?꾩쓽 媛믪쓣 援ы븿
        int up = board[i - 1][j];
        int left = board[i][j - 1];
        int up_left = board[i - 1][j - 1];

        //???꾩옱 ?꾩튂??媛믪쓣 ?댁쟾 ?꾩튂?ㅼ쓽 媛믩뱾 以?媛???묒? 媛믪뿉 1???뷀븳 媛믪쑝濡??낅뜲?댄듃
        board[i][j] = min(min(up, left), up_left) + 1;
      }
    }
  }

  //??蹂대뱶?먯꽌 媛????媛?理쒕? ?뺤궗媛곹삎????蹂??湲몄씠) ?뺤씤
  int max_val = 0;
  for (const auto& row : board) {
    max_val = max(max_val, *max_element(row.begin(), row.end()));
  }
  //??理쒕? ?뺤궗媛곹삎 ?볦씠 諛섑솚
  return max_val * max_val;
}




//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << endl; //異쒕젰媛?: 9
  cout << solution({{0, 0, 1, 1}, {1, 1, 1, 1}}) << endl; //異쒕젰媛?: 4  
  return 0;
}
