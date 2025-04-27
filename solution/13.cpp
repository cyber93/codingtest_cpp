#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  //??蹂대뱶?먯쓽 ?댁쓽 ?ш린留뚰겮 ?ㅽ깮???앹꽦 
  stack<int> lanes[board[0].size()];
  //??蹂대뱶??媛??諛묒쓽 ?됰????꾨줈 ?щ씪媛癒쇱꽌 ?쒗쉶 
  for(int i = board.size()-1 ; i >= 0; --i) {
    for(int j = 0; j<board[0].size(); ++j) {
     //??釉붾윮???덈뒗 寃쎌슦 ?대떦 ?댁뿉 ?대떦?섎뒗 ?ㅽ깮???몄떆 
      if(board[i][j]) {
        lanes[j].push(board[i][j]);
      }
    }
  }

 // 蹂대뱶?먯뿉??爰쇰궦 ?명삎???댁쓣 bucket怨??щ씪吏??명삎??媛쒖닔瑜???ν븷 answer ?좎뼵
  stack<int> bucket;
  int answer = 0;

  for(int m : moves) {
   //???대떦 lane??釉붾윮???덉쑝硫?
    if(lanes[m-1].size()){
      int doll = lanes[m-1].top();
      lanes[m-1].pop();
     //??踰꾪궥??釉붾윮???덇퀬, 媛??理쒓렐???ㅼ뼱媛?釉붾윮怨??꾩옱 釉붾윮??媛숈?吏 ?뺤씤
      if (bucket.size() && bucket.top() == doll) {
        bucket.pop();
        answer += 2;
      } else {
        bucket.push(doll);
      }
    }
  }

  return answer;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
    
    cout << solution( { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} }, {1, 5, 3, 5, 1, 2, 1, 4} ) << endl; // 4
    return 0;
}
