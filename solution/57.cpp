#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
  //???レ옄瑜?臾몄옄?대줈 蹂??
  string str = to_string(n);

  //????닚?쇰줈 ?뺣젹
  sort(str.rbegin(), str.rend());
  return stoll(str);
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution(118372) << endl; // 異쒕젰媛?: 873211

  return 0;
}
