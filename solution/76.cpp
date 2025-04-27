#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {
  // ??媛??됰쭏???댁쟾 ?됱뿉?쒖쓽 理쒕? ?먯닔瑜??뷀빐媛硫?理쒕? ?먯닔 ?꾩쟻
  for (int i = 1; i < land.size(); ++i) {
    for (int j = 0; j < 4; ++j) {
      // ???댁쟾 ?됱뿉???꾩옱 ?댁쓽 媛믪쓣 ?쒖쇅???섎㉧吏 ?대뱾 以묒뿉??媛????媛믪쓣 ?뷀븿
      int maxVal = 0;
      for (int k = 0; k < 4; ++k) {
        if (k != j) {
          maxVal = max(maxVal, land[i - 1][k]);
        }
      }
      land[i][j] += maxVal;
    }
  }
  // ??留덉?留??됱뿉???살쓣 ???덈뒗 理쒕? ?먯닔瑜?諛섑솚
  return *max_element(land.back().begin(), land.back().end());
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}}) << endl; //異쒕젰媛?: 16
  
  return 0;
}
