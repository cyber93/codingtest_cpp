#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  unordered_map<string, string> parent;

  //??parent???먮ℓ??- ?먮ℓ?먯쓣 李몄뿬?쒗궓 異붿쿇?몄쑝濡?援ъ꽦 
  for (size_t i = 0; i < enroll.size(); ++i) {
    parent[enroll[i]] = referral[i];
  }

  unordered_map<string, int> total;
  //??total? ?먮ℓ??- ?먮ℓ?먯쓽 ?섏씡?쇰줈 援ъ꽦?섍퀬 ?섏씡??0?쇰줈 珥덇린??
  for (const auto& name : enroll) {
    total[name] = 0;
  }

  for (size_t i = 0; i < seller.size(); ++i) {
    //??cur_name? ?ㅼ젣 臾쇨굔?????щ엺?닿퀬, money ?꾩옱 ?먮ℓ?먯쓽 ?섏씡湲?
    int money = amount[i] * 100;
    string cur_name = seller[i];

    while (money > 0 && cur_name != "-") {
      //???ㅼ젣 臾쇨굔?????щ엺??湲곗??쇰줈  異붿쿇?몄쓣 怨꾩냽 異붿쟻?섎ŉ ?⑥? ?섏씡??10%瑜?遺꾨같
      int to_distribute = money / 10;
      total[cur_name] += money - to_distribute;
      //???꾩옱 ?대쫫??異붿쿇?몄씠?덉쑝硫? ?꾩옱?대쫫? 異붿쿇?몄쑝濡?蹂寃? 洹몃젃吏 ?딆쑝硫?醫낅즺 
      if (parent.find(cur_name) != parent.end()) {
        cur_name = parent[cur_name];
      } else {
        break;
      }
      //?? ?꾩옱 ?먮ℓ?먯씠 異붿쿇?몄쑝濡?蹂寃쎈릺?덉쑝誘濡? ?섏씡湲덈룄 ?댁뿉 留욎떠???낅뜲?댄듃
      money = to_distribute;
    }
  }

 //???섏씡湲덉쓣 answer???낅뜲?댄듃 ?댁꽌 諛섑솚
  vector<int> result;
  result.reserve(enroll.size());
  for (const auto& name : enroll) {
    result.push_back(total[name]);
  }

  return result;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                   {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                   {"young", "john", "tod", "emily", "mary"},
                   {12, 4, 2, 5, 10}
                  )); //異쒕젰媛?: 360 958 108 0 450 18 180 1080
                  
        print(solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, 
                       {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
                       {"sam", "emily", "jaimie", "edward"},
                        {2, 3, 5, 4}
                      )); //異쒕젰媛?: 0 110 378 180 270 450 0 0 
    return 0;
}
