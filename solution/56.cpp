#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx;

//??鍮꾧탳 ?⑥닔
bool compare (string a, string b) {
  return a[idx] == b[idx] ? a < b : a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
  idx = n;
    
  //??媛?臾몄옄?댁쓽 idx踰덉㎏ 臾몄옄瑜?湲곗??쇰줈 ?뺣젹 
  sort (strings.begin(), strings.end(), compare);
  return strings;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>
#include <iterator>

using namespace std;

void print(vector<string> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution({"sun", "bed", "car"}, 1)); //異쒕젰媛?: car bed sun
  print(solution({"abce", "abcd", "cdx"}, 2));  // 異쒕젰媛?: abcd abce cdx

  return 0;
}
