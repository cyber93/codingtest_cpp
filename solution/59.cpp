#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//??臾몄옄?대줈 諛붾????섎? 議고빀?댁꽌 ?ш린瑜?鍮꾧탳
bool compare(const string& lhs, const string& rhs) {
  return (lhs + rhs) > (rhs + lhs);
}

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> strings;

  for (auto elem : numbers) {
    //??numbers???먯냼瑜?臾몄옄?대줈 蹂?뺥빐???몄떆
    strings.push_back(to_string(elem));
  }
  //???뺣젹?⑥닔瑜?湲곗??쇰줈 ?뺣젹 
  sort(strings.begin(), strings.end(), compare);

  //???뺣젹??臾몄옄?댁쓣 ?욎뿉??遺??異붽?
  for (auto elem : strings) {
    answer += elem;
  }

    //??理쒖쥌 ?レ옄媛 0?대㈃ 0??諛섑솚?섍퀬 洹몃젃吏 ?딆쑝硫?answer 諛섑솚
    return answer[0] == '0' ? "0" : answer;
}




//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution({6, 10, 2}) << endl; // 異쒕젰媛?: 6210
  cout << solution({3, 30, 34, 5, 9}) << endl; // 異쒕젰媛?: 9534330
  return 0;
}
