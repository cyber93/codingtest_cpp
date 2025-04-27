#include <vector>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
  //??寃곌낵媛믪쓣 ??ν븷 踰≫꽣瑜? 0?쇰줈 珥덇린??
  vector<vector<int>> result(3, vector<int>(3, 0));

  //???됰젹 怨깆뀍???섑뻾?⑸땲??
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

vector<vector<int>> transpose(vector<vector<int>> matrix) {
  //??寃곌낵 ?됰젹??0?쇰줈 珥덇린?뷀빀?덈떎.
  vector<vector<int>> result(3, vector<int>(3, 0));

  //???꾩튂 ?됰젹??怨꾩궛?⑸땲??
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result[j][i] = matrix[i][j];
    }
  }

  return result;
}

vector<vector<int>> solution(vector<vector<int>> matrix1, vector<vector<int>>matrix2) {
  //??二쇱뼱吏????됰젹??怨깊빀?덈떎.
  vector<vector<int>> multiplied = multiply(matrix1, matrix2);

  //??怨깆뀍 寃곌낵???꾩튂 ?됰젹??怨꾩궛?⑸땲??
  vector<vector<int>> transposed = transpose(multiplied);
  return transposed;
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
    print(solution( {
                     {1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9},
                    },
                    {
                     {9, 8, 7},
                     {6, 5, 4},
                     {3, 2, 1},
                    }
                    ));
    /*
    異쒕젰媛?:
    30 84 138 
    24 69 114 
    18 54 90 
    */
                    
    print(solution( {
                     {2, 4 ,6},
                     {1, 3, 5},
                     {7, 8, 9},
                    },
                    {
                     {9, 1, 2},
                     {4, 5, 6},
                     {7, 3, 8},
                    }
                    ));
    /*
    異쒕젰媛? 
    76 56 158 
    40 31 74 
    76 60 134 
    */
  return 0;
}
