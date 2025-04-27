#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
  sort(d.begin(), d.end()); //??踰≫꽣 d瑜??ㅻ쫫李⑥닚?쇰줈 ?뺣젹
  int count = 0; //??吏?먰븷 ???덈뒗 遺?쒖쓽 媛쒖닔瑜??몃뒗 蹂??

  for (int amount : d) {
    if (budget < amount) {
      break; //???⑥? ?덉궛???좎껌??湲덉븸蹂대떎 ?묒쑝硫????댁긽 吏?먰븷 ???놁쑝誘濡?醫낅즺
    }
    budget -= amount; //???덉궛?먯꽌 ?좎껌??湲덉븸??李④컧
    count += 1;
  }

  return count;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
  cout << solution({1, 3, 2, 5, 4}, 9) << endl; //異쒕젰媛?: 3
  cout << solution({2, 2, 3, 3}, 10) << endl; //異쒕젰媛?: 4
  
  return 0;
}
