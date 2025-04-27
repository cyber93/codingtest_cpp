#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
  int transforms = 0;
  int removedZeros = 0;
  //?? s媛 ???앹씠 ?좊븣源뚯? 怨꾩냽 諛섎났
  while (s != "1") {
    transforms++;

    //??'0' 媛쒖닔瑜??몄뼱 removedZeros???꾩쟻
    removedZeros += count(s.begin(), s.end(), '0');

    //??'1' 媛쒖닔瑜??멸퀬, ?대? ?댁쭊?섎줈 蹂??
    int onesCount = count(s.begin(), s.end(), '1');
    s = bitset<32>(onesCount).to_string();
    s = s.substr(s.find('1'));
  }

  return {transforms, removedZeros};
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
  print(solution("110010101001")); //異쒕젰媛?: 3 8
  print(solution("01110")); //異쒕젰媛?: 3 3
  print(solution("1111111")); //異쒕젰媛?: 4 1
  
  return 0;
}
