#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;
  vector<int> subArray;

  for (const auto& cmd : commands) {
    //??array?먯꽌 媛?cmd???대떦?섎뒗 ?곸뿭留?subArray濡?蹂듭궗???뺣젹
    subArray.assign(array.begin() + (cmd[0] - 1), array.begin() + cmd[1]);
    sort(subArray.begin(), subArray.end());
      
    //??subArray?먯꽌 k踰?吏?answer??異붽?
    answer.push_back(subArray[cmd[2] - 1]);     
  }

  return answer;
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
  print(solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}})); // 異쒕젰媛?: 5 6 3

  return 0;
}
