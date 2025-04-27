#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int green, int white) {
  // ??寃⑹옄??珥?媛쒖닔 (?뚮???寃⑹옄 + ?곗깋 寃⑹옄)
  int total_size = green + white;
  // ???몃줈 湲몄씠??踰붿쐞??3遺??(?뚮???寃⑹옄 + ?곗깋 寃⑹옄)???쒓낢洹?
  for (int vertical = 3; vertical <= sqrt(total_size); ++vertical) {
    // ???ш컖??援ъ꽦???섎뒗吏 ?뺤씤
    if (total_size % vertical == 0) {
      int horizontal = total_size / vertical; // ???ш컖?뺤쓽 媛濡?湲몄씠
      // ??移댄렖 ?뺥깭濡?留뚮뱾 ???덈뒗吏 ?뺤씤
      if (green == (horizontal + vertical - 2) * 2) {
        return {horizontal, vertical}; // ??{媛濡?湲몄씠, ?몃줈 湲몄씠}
      }
    }
  }
  return {}; // ??留뚯빟 ?듭쓣 李얠? 紐삵뻽?ㅻ㈃ 鍮?踰≫꽣瑜?諛섑솚
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(10, 2)); //異쒕젰媛?: 4 3
  print(solution(8, 1)); //異쒕젰媛?: 3 3
  print(solution(24, 24)); //異쒕젰媛?: 8 6
  
  return 0;
}
