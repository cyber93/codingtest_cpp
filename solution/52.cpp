#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
  int length = weak.size();
  //?? weak 由ъ뒪???뺤옣
  for (int i = 0; i < length; ++i) {
    weak.push_back(weak[i] + n);
  }

  //??珥덇린??
  int answer = dist.size() + 1;

  //???쒖옉???ㅼ젙 諛?移쒓뎄 ?쒖뿴 ?앹꽦
  for (int start = 0; start < length; ++start) {
    do {
      //??移쒓뎄 諛곗튂 諛???怨꾩궛
      int cnt = 1;
      int position = weak[start] + dist[cnt - 1];
      
      //???ㅼ쓬 weak 吏???뺤씤
      for (int index = start; index < start + length; ++index) {
        if (position < weak[index]) {
          cnt += 1;
          //??移쒓뎄 ??珥덇낵 ?뺤씤
          if (cnt > dist.size()) break; 
          position = weak[index] + dist[cnt - 1];
        }
      }
      
      //??理쒖냼 移쒓뎄 ???낅뜲?댄듃
      answer = min(answer, cnt);
    } while (next_permutation(dist.begin(), dist.end())); // ?쒖뿴 ?앹꽦
  }

  //??寃곌낵 諛섑솚
  return answer > dist.size() ? -1 : answer;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
   cout << solution(12, {1, 5, 6, 10},{1, 2, 3, 4}) << endl; //異쒕젰媛?: 2
   cout << solution(12, {1, 3, 4, 9, 10},{3, 5, 7}) << endl; //異쒕젰媛?: 1   
   
   return 0;
}
