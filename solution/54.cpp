#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  //???뚰뙆踰?媛쒖닔(26媛?留뚰겮 鍮덈룄??諛곗뿴 ?앹꽦
  vector<int> counts(26, 0); 

  //??臾몄옄?댁쓽 媛?臾몄옄?????鍮덈룄?섎? 鍮덈룄??諛곗뿴?????
  for (char c : s) {
    counts[c - 'a']++;
  }

  //??鍮덈룄??諛곗뿴???쒗쉶?섎㈃???뺣젹??臾몄옄?댁쓣 ?앹꽦
  string sorted_str = "";
  for (int i = 0; i < 26; i++) {
    sorted_str += string(counts[i], i + 'a');
  }

  return sorted_str;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution("hello") << endl; // 異쒕젰媛?: ehllo
  cout << solution("algorithm") << endl; // 異쒕젰媛?: aghilmort
  
  return 0;
}
