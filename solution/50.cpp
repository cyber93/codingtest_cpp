#include <vector>
#include <algorithm>

using namespace std;

//???꾩옱 ?됱뿉 ?대? ?ㅻⅨ ?몄씠 ?덈뒗吏 ?뺤씤?섎뒗 ?⑥닔
bool isSameRow(int placedRow, int currentRow) {
  return placedRow == currentRow;
}

//???媛곸꽑???ㅻⅨ ?몄씠 ?덈뒗吏 ?뺤씤?섎뒗 ?⑥닔
bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow) {
  return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

//???몄쓣 ?덉쟾?섍쾶 諛곗튂?????덈뒗吏 ?뺤씤?섎뒗 ?⑥닔
bool isSafePosition(const vector<int> &queen, int col, int row) {
  for (int i = 0; i < col; ++i) {
    if (isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row)) {
      return false;
    }
  }
  return true;
}

//???몄쓣 諛곗튂?섎뒗 ?⑥닔
long long placeQueens(vector<int> &queen, int col) {
  int n = queen.size();
  if (col == n) {
    return 1;
  }

  long long count = 0;
  for (int row = 0; row < n; ++row) {
    //???몄쓣 ?볦쓣???덈뒗 ?꾩튂??寃쎌슦 ?몄쓣 ?볦쓬
    if (isSafePosition(queen, col, row)) {
      queen[col] = row;
      count += placeQueens(queen, col + 1);
      queen[col] = -1;
    }
  }
  return count;
}

long long solution(int n) {
  vector<int> queen(n, -1);

  //???몄쓣 ?볦쓣???덈뒗 寃쎌슦???섎? 諛섑솚
  return placeQueens(queen, 0);
}





//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution(4) << endl; // 異쒕젰媛?: 2
  return 0;
}
