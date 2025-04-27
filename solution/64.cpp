#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {

  //??N*N 2李⑥썝 踰≫꽣瑜??좎뼵?섍퀬 珥덇퉫媛믪쓣 0?쇰줈 ??
  vector<vector<int>> snail_array(n, vector<int>(n, 0));
  int num = 1;
  // ?됯낵 ?댁쓽 ?쒖옉怨????몃뜳?ㅻ? ?ㅼ젙
  int start_row = 0, end_row = n - 1;
  int start_col = 0, end_col = n - 1;

  //???쒖씪 ?멸컖遺???ы뙺???섏뿴 洹쒖튃?濡?梨꾩?
  while (start_row <= end_row && start_col <= end_col) {
    // 媛???쇱そ ?쀫?遺??먯꽌 媛???꾨옒 諛붾줈 吏곸쟾 源뚯?  梨꾩슦湲?
    for (int i = start_col; i <= end_col; ++i) {
      snail_array[start_row][i] = num++;
    }
    ++start_row;

    // 媛???쇱そ  ?꾨옒遺遺??먯꽌 媛???ㅻⅨ履?諛붾줈 吏곸쟾 源뚯? 梨꾩슦湲?
    for (int i = start_row; i <= end_row; ++i) {
      snail_array[i][end_col] = num++;
    }
    --end_col;

    // 媛???ㅻⅨ履??꾨옒遺遺??먯꽌 媛????諛붾줈 吏곸쟾 源뚯? 梨꾩슦湲?
    if (start_row <= end_row) {
      for (int i = end_col; i >= start_col; --i) {
        snail_array[end_row][i] = num++;
      }
      --end_row;
    }

    // 媛???쀫?遺??먯꽌 媛???쇱そ 諛붾줈 吏곸쟾 源뚯? 梨꾩슦湲?
    if (start_col <= end_col) {
      for (int i = end_row; i >= start_row; --i) {
        snail_array[i][start_col] = num++;
      }
      ++start_col;
    }
  }

  return snail_array;
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
    print(solution(3));
    /*
    異쒕젰媛?:
    1 2 3 
    8 9 4 
    7 6 5
    */
                    
    print(solution(4));
    /*
    異쒕젰媛? 
    1 2 3 4 
    12 13 14 5 
    11 16 15 6 
    10 9 8 7
    */
  return 0;
}
