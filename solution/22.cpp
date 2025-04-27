#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phoneBook) {
  //???꾪솕踰덊샇 紐⑸줉???ㅻ쫫李⑥닚?쇰줈 ?뺣젹
  sort(phoneBook.begin(), phoneBook.end());

  //??紐⑤뱺 ?꾪솕踰덊샇瑜??쒗쉶?섎㈃???ㅼ쓬 踰덊샇? 鍮꾧탳
  for (int i = 0; i < phoneBook.size() - 1; ++i) {
    //???꾩옱 踰덊샇媛 ?ㅼ쓬 踰덊샇???묐몢?댁씤 寃쎌슦 false 諛섑솚
    if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())) {
      return false;
    }
  }

  //???대뼡 踰덊샇???ㅻⅨ 踰덊샇???묐몢?닿? ?꾨땶 寃쎌슦 true 諛섑솚
  return true;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  //bool 諛섑솚????true??1, false??0 ?낅땲??
  cout << solution({"119", "97674223", "1195524421"}) << endl; //異쒕젰媛?: 0
  cout << solution({"123", "456", "789"}) << endl; //異쒕젰媛?: 1
  cout << solution({"12", "123", "1235", "567", "88"}) << endl; //異쒕젰媛?: 0
  
  return 0;
}
