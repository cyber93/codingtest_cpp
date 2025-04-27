#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int amount) {
  vector<int> denominations = {1, 10, 50, 100};
  sort(denominations.rbegin(), denominations.rend()); //???뷀룓 ?⑥쐞瑜????쒖꽌?濡??뺣젹

  vector<int> change; //??嫄곗뒪由꾨룉???댁쓣 踰≫꽣
  for (int coin : denominations) {
    while (amount >= coin) { //???대떦 ?뷀룓 ?⑥쐞濡?嫄곗뒪由꾨룉??怨꾩냽 ?섎닠以?
      change.push_back(coin); //??嫄곗뒪由꾨룉 踰≫꽣 ?낅뜲?댄듃
      amount -= coin; //???뺤궛???꾨즺??嫄곗뒪由꾨룉 類?
    }
  }
  return change; //??嫄곗뒪由꾨룉 諛섑솚
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
  print(solution(123)); //異쒕젰媛?: 100 10 10 1 1 1
  print(solution(350)); //異쒕젰媛?: 100 100 100 50
  
  return 0;
}
