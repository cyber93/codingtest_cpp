#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
  vector<int> answer(2, 0);
  unordered_set<string> usedWords;
    
  usedWords.insert(words[0]);

  //????踰덉㎏ ?⑥뼱遺???앷퉴吏 諛섎났
  for (int i = 1; i < words.size(); ++i) {
    //???⑥뼱媛 ?대? ?ъ슜?섏뿀嫄곕굹, ?앸쭚?뉕린 洹쒖튃??留욎? ?딅뒗 寃쎌슦
    if (!usedWords.insert(words[i]).second || words[i].front() != words[i - 1].back()) {
      //???뚮젅?댁뼱 踰덊샇? ??踰덊샇 ?????諛붾줈 諛섑솚
      answer[0] = i % n + 1;
      answer[1] = i / n + 1;
      return answer;
    }
  }

  //??以묎컙???덈씫?섎뒗 ?뚮젅?댁뼱媛 ?놁쑝硫?[0, 0] 諛섑솚
  return answer;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>
#include <iterator>

using namespace std;

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"})); // 寃곌낵媛?: 3 3
  print(solution(5, {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"})); // 寃곌낵媛?: 0 0
  print(solution(2, {"hello", "one", "even", "never", "now", "world", "draw"})); // 寃곌낵媛?: 1 3
  
  return 0;
}
