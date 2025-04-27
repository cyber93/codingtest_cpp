#include <vector>

using namespace std;

// ??2李⑥썝 踰≫꽣瑜??몄옄濡?諛쏄퀬 90???뚯쟾
vector<vector<int>> rotate_90(const vector<vector<int>> &arr) {
  int n = arr.size();
  // ???몄옄濡?諛쏆? 踰≫꽣? ?ш린媛 媛숈? 2李⑥썝 諛깊꽣 ?앹꽦(珥덇퉫媛믪? 0)
  vector<vector<int>> rotated_arr(n, vector<int>(n, 0));
  // ??2李⑥썝 踰≫꽣瑜?90?꾨줈 ?뚯쟾
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      rotated_arr[j][n - i - 1] = arr[i][j];
    }
  }
  return rotated_arr;
}

vector<vector<int>> solution(vector<vector<int>> arr, int n) {
  vector<vector<int>> rotated_arr = arr;

  // ??2李⑥썝 踰≫꽣瑜?90?꾨줈 n踰??뚯쟾
  for (int i = 0; i < n; ++i) {
    rotated_arr = rotate_90(rotated_arr);
  }
  return rotated_arr;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<vector<int>> vec)
{
  for(int i = 0 ; i < vec.size(); i++){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
  
}

int main()
{
  print(solution({
                   {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}
                 }, 1));
  /*
    異쒕젰媛?
    13 9 5 1 
    14 10 6 2 
    15 11 7 3 
    16 12 8 4 
  */
  
  print(solution({
                   {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}
                 }, 3));
  /*
    異쒕젰媛?
    4 8 12 16 
    3 7 11 15 
    2 6 10 14 
    1 5 9 13 
  */
             
  return 0;
}
