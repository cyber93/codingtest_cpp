#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
  vector<string> answer;
  unordered_map<string, string> uid;

  for (const auto& line : record) {
    //??媛?record????댁꽌,  cmd?먮뒗 紐낅졊?대? ??ν븯怨? id?먮뒗 ?됰꽕?꾩쓣 ???
    stringstream ss(line);
    string cmd, id, nickname;
    ss >> cmd >> id;
    //??紐낅졊?닿? Enter ?뱀? Change??寃쎌슦 nickname???됰꽕?꾩쓣 ???
    if (cmd != "Leave") {
      ss >> nickname;
      uid[id] = nickname;
    }
  }

  for (const auto& line : record) {
    stringstream ss(line);
    string cmd, id;
    ss >> cmd >> id;
    //??Enter 諛?Change 紐낅졊?댁쓽 寃쎌슦 理쒖쥌 ?됰꽕?꾧낵 ?뺥빐吏?臾몄옄?댁쓣 answer??異붽?
    if (cmd == "Enter") {
      answer.push_back(uid[id] + "?섏씠 ?ㅼ뼱?붿뒿?덈떎.");
    } else if (cmd == "Leave") {
      answer.push_back(uid[id] + "?섏씠 ?섍컮?듬땲??");
    }
    // "Change"??硫붿떆吏 ?앹꽦???곹뼢??二쇱? ?딆쑝誘濡?臾댁떆
  }

  return answer;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>
#include <iterator>
void print(vector<string> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution( {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan"} ));
  // Prodo?섏씠 ?ㅼ뼱?붿뒿?덈떎. Ryan?섏씠 ?ㅼ뼱?붿뒿?덈떎. Prodo?섏씠 ?섍컮?듬땲?? Prodo?섏씠 ?ㅼ뼱?붿뒿?덈떎.    

  return 0;
}
