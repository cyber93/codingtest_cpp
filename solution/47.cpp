#include <vector>

using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

void backtrack(int N, int sum, int start) {
  //???⑹씠 10?멸꼍?? 議고빀??寃곌낵??異붽??섍퀬 醫낅즺
  if (sum == 10) {
    results.push_back(selected_nums);
    return;
  }
  for (int i = start; i <= N; ++i) {
    //???⑹씠 10蹂대떎 ?곸? 寃쎌슦, 媛?ν븳 議고빀??怨꾩냽 ?뺤씤
    if (sum + i <= 10) {
      selected_nums.push_back(i);
      backtrack(N, sum + i, i + 1);
      selected_nums.pop_back();
    }
  }
}

vector<vector<int>> solution(int N) {
  //???レ옄 1遺??諛깊듃?섑궧 ?쒖옉
  backtrack(N, 0, 1);
  return results;
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>

using namespace std;

void init()
{
  results.clear();
  selected_nums.clear();    
}

void print(vector<vector<int>> vec)
{
    
  for(int i = 0; i < vec.size(); i++ ){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
    
}

int main()
{
  print(solution(5));
  init();
  /*
    異쒕젰媛?
    1 2 3 4 
    1 4 5 
    2 3 5 
  */
  print(solution(2));
  init();
  /*
    異쒕젰媛??놁쓬)
  */  
  print(solution(7));
  /*
    異쒕젰媛?
    1 2 3 4 
    1 2 7 
    1 3 6 
    1 4 5 
    2 3 5 
    3 7 
    4 6 
  */
  return 0;
}
