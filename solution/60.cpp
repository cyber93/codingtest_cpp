#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int counts[100001] = {};

void updateCounts(const string& s) {
  string numStr;
  //???몄옄濡?諛쏆? 臾몄옄?댁쓣 ?쒗쉶
  for (char ch : s) {
    //???꾩옱 臾몄옄媛 ?レ옄??寃쎌슦
    if (isdigit(ch)) {
      numStr += ch;
    //???꾩옱 臾몄옄媛 ?レ옄媛 ?꾨땶 寃쎌슦
    } else {
      if (!numStr.empty()) {
        //??怨꾩닔?뺣젹???섍린 ?꾪빐 媛??レ옄??媛쒖닔瑜????
        counts[stoi(numStr)]++;
        numStr.clear();
      }
    }
  }
}

vector<int> solution(string s) {
  vector<int> answer;
  //??吏묓빀???닿릿 臾몄옄?댁쓽 媛??먯냼瑜?怨꾩닔?뺣젹
  updateCounts(s);

  vector<pair<int, int>> freqPairs;
  for (int i = 1; i <= 100000; i++) {
    //??吏묓빀???덈뒗 ?먯냼??寃쎌슦 (媛쒖닔, 媛? ?뺤떇?쇰줈 ?몄떆
    if (counts[i] > 0) {
      freqPairs.push_back({counts[i], i});
    }
  }

  //??媛??먯냼??媛쒖닔瑜?湲곗??쇰줈 ?대┝李⑥닚 ?뺣젹
  sort(freqPairs.rbegin(), freqPairs.rend());

  //???먯냼??媛쒖닔濡??대┝李⑥닚 ?뺣젹??踰≫꽣瑜??쒗쉶?섎ŉ ?먯냼瑜??몄떆
  for (const auto& p : freqPairs) {
    answer.push_back(p.second);
  }

  return answer;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i <= 100000; i++)
    counts[i] = 0;    
}

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}


int main()
{
  print(solution("{{2}, {2, 1}, {2, 1, 3}, {2, 1, 3, 4}}")); // 異쒕젰媛?: 2 1 3 4
  init();
  print(solution("{{1, 2, 3}, {2, 1}, {1, 2, 4, 3}, {2}}")); // 異쒕젰媛?: 2 1 3 4
  init();
  print(solution("{{20, 111}, {111}}")); // 異쒕젰媛?: 111 20
  init();
  print(solution("{{123}}")); // 異쒕젰媛?: 123
  init();
  print(solution("{{4, 2, 3}, {3}, {2, 3, 4, 1}, {2, 3}}")); // 異쒕젰媛?: 3 2 4 1 
  
  return 0;
}
