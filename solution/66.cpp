#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
  int answer = 0;

  //???⑥븘?덈뒗 媛??좏븨??媛쒖닔
  unordered_map<int, int> topping_cnt;
  //???덈컲???랁븳 ?좏븨??醫낅쪟
  unordered_set<int> half_topping;

  //??移댁슫?곗뿉 媛??좏븨??媛쒖닔瑜????
  for (auto top : topping) {
    if (topping_cnt.find(top) == topping_cnt.end()) {
      topping_cnt[top] = 1;
    } else {
      topping_cnt[top]++;
    }
  }

  //???욎뿉??遺???좏븨???쒖꽌?濡??쒗쉶
  for (int i = 0; i < topping.size(); i++) {
    //???덈컲???랁븯???좏븨??異붽??섍퀬, ?⑥? ?좏븨媛쒖닔?먯꽌 ?쒖쇅
    half_topping.insert(topping[i]);
    topping_cnt[topping[i]]--;
     //???꾩옱 ?좏븨???⑥븘?덉? ?딆? 寃쎌슦 ?⑥? ?좏븨 紐⑸줉?먯꽌 ??젣
    if (topping_cnt[topping[i]] == 0) {
      topping_cnt.erase(topping[i]);
    }
    //??怨듯룊??寃쎌슦 移댁슫??
    if (topping_cnt.size() == half_topping.size()) {
      answer++;
    }
  }

  return answer;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;


int main()
{
  cout << solution({1, 2, 1, 3, 1, 4, 1, 2}) << endl; // 異쒕젰媛?: 2
  cout << solution({1, 2, 3, 1, 4}) << endl; // 異쒕젰媛?: 0
  
  return 0;
}
