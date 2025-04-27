#include <vector>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
int maxScore = -1;

//???댄뵾移섏? ?쇱씠?몄쓽 ?먯닔李⑥씠瑜?怨꾩궛
int calcScoreDiff(const vector<int> &apeach) {
  int scoreApeach = 0;
  int scoreLion = 0;

  for(int i = 0; i < 11; ++i) {
    if(apeach[i] == 0 && ryan[i] == 0) continue;
    if(apeach[i] >= ryan[i]) scoreApeach += 10 - i;
    else scoreLion += 10 - i;
  }

  return scoreLion - scoreApeach;
}

void dfs(const vector<int> &apeach, int score, int arrow) {
  if(score == -1 || arrow == 0) {
    ryan[10] = arrow;
    int scoreDiff = calcScoreDiff(apeach);
    //???꾩옱 援ы븳 ?먯닔李④? 湲곗〈 理쒕? ?먯닔李⑤낫?????ш퀬, ?쇱씠?몄쓽 ?먯닔媛 ???믪? 寃쎌슦 媛깆떊
    if(scoreDiff > 0 && maxScore < scoreDiff) {
      maxScore = scoreDiff;
      answer = ryan;
    }
    ryan[10] = 0;
    return;
  }

   //???꾩쭅 ?댄뵾移섍? ???붿궡???⑥? 寃쎌슦
  if(arrow > apeach[score]) {
    ryan[score] = apeach[score] + 1;
    dfs(apeach, score - 1, arrow - apeach[score] - 1);
    ryan[score] = 0;
  }

  //???댄뵾移섍? ?붿궡???ъ슜?섏? ?딅뒗 寃쎌슦
  dfs(apeach, score - 1, arrow);
}

vector<int> solution(int n, vector<int> info) {
  //??10??怨쇰뀅遺??紐⑤뱺 議고빀???뺤씤
  dfs(info, 10, n);

  //???쇱씠?몄씠 ?닿만 ???덈뒗 寃쎌슦媛 ?녿뒗 寃쎌슦
  if(maxScore == -1) answer.push_back(-1);

  return answer;
}





//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>
#include <iterator>
using namespace std;

void init(){
  answer.clear();
  maxScore = -1;
  
  for(int i = 0 ; i < ryan.size(); i++)
    ryan[i] = 0;
}

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0})); //異쒕젰媛?: 0 2 2 0 1 0 0 0 0 0 0 
  init();
  print(solution(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})); //異쒕젰媛?: -1
  init();
  print(solution(9, {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1})); //異쒕젰媛?: 1 1 2 0 1 2 2 0 0 0 0 
  return 0;
}
