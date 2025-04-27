#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums) {
  //??s??nums??以묐났媛믪쓣 ?쒓굅??吏묓빀
  unordered_set<int> s(nums.begin(), nums.end());

  //??以묐났???쒓굅??媛쒖닔? nums??媛쒖닔以??묒? 媛믪쓣 諛섑솚
  return min(nums.size() / 2, s.size());
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution({3, 1, 2 ,3}) << endl; //異쒕젰媛?: 2
  cout << solution({3, 3, 3, 2, 2, 4}) << endl; //異쒕젰媛?: 3
  cout << solution({3, 3, 3, 2, 2, 2}) << endl; //異쒕젰媛?: 2
  
  return 0;
}
