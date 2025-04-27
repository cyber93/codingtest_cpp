#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxDepth = 0;
bool visited[8] = {false, };

//??理쒕?諛⑸Ц ?섏쟾?섎? 媛깆떊?섎㈃??源딆씠?곗꽑?먯깋?쇰줈 ?섏쟾???먰뿕
void exploreDungeon(int depth, int power, vector<vector<int>>& dungeons) {
  if(maxDepth < depth)
    maxDepth = depth;

  for(int i = 0; i < dungeons.size(); i++) {
    //???대? 諛⑸Ц???섏쟾?닿굅??  理쒖냼 ?꾩슂 ?쇰줈?꾧? ?꾩옱 ?⑥? ?쇰줈??蹂대떎 留롮? 寃쎌슦 
    if(visited[i] || dungeons[i][0] > power)
      continue;
  
    //??諛⑸Ц??媛?ν븳 媛?ν븳 紐⑤뱺 寃쎌슦瑜??뺤씤
    visited[i] = true;
    exploreDungeon(depth + 1, power - dungeons[i][1], dungeons);
    visited[i] = false;
  }
}

int solution(int initialPower,vector<vector<int>> dungeons) {
  //???섏쟾?먯깋 ?쒖옉
  exploreDungeon(0, initialPower, dungeons);

  return maxDepth;
}




//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl; // 異쒕젰媛?: 3
  return 0;
}
