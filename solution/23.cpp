#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;
  
  unordered_map<string, int> wantMap;
  //??want瑜??ㅻ줈  number瑜?媛믪쑝濡??댁꽌 wantMap???좎뼵
  for (int i = 0; i < want.size(); i++) 
    wantMap[want[i]] = number[i];


  for (int i = 0; i < discount.size() - 9; i++) {
    // ??i???뚯썝媛???? ?좎씤諛쏆쓣 ???덈뒗 ?덈ぉ???ㅻ줈, 媛쒖닔瑜?媛믪쑝濡??댁꽌  discount_10d ?좎뼵
    unordered_map<string, int> discount_10d;

    // ?? 媛??좎씤?섎뒗 ?덈ぉ???ㅻ줈  媛쒖닔瑜????
    for (int j = i; j < 10 + i; j++)
      discount_10d[discount[j]]++;

   // ???좎씤?섎뒗 ?곹뭹???덈ぉ諛?媛쒖닔媛 ?먰븯???곹뭹???덈ぉ 諛?媛쒖닔? ?쇱튂?섎㈃ 移댁슫??利앷?
    if (wantMap == discount_10d) answer++;
  }

  return answer;
}

//?ш린遺?곕뒗 ?뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
  cout << solution( {"banana", "apple", "rice", "pork", "pot"}, 
                    {3, 2, 2, 2, 1}, 
                    {"chicken", "apple", "apple", "banana", "rice","apple", "pork", "banana", "pork", "rice", "pot","banana", "apple", "banana"}) << endl; // 3
                      
  cout << solution( {"apple"}, 
                    {10}, 
                    {"banana", "banana", "banana", "banana","banana", "banana", "banana", "banana", "banana","banana"}) << endl; // 0
  return 0;
}
