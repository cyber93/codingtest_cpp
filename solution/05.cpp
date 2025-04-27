#include <string>
#include <vector>

using namespace std;

vector<vector<int> > solution(vector<vector<int> >arr1, vector<vector<int> >arr2)
{
  // ??理쒖쥌 ?됰젹怨깆쓽 寃곌낵瑜???ν븷 踰≫꽣 ?좎뼵
    vector<vector<int> >answer;
    
   // ??arr1怨?arr2???됰젹怨깆쓣 ?섑뻾?덉쓣??理쒖쥌?곸씤 ?됰젹???ш린留뚰겮 怨듦컙???좊떦
   answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0));

// ??arr1??媛??됯낵 arr2??媛??댁뿉 ???諛섎났臾??섑뻾
  for(int i = 0;i < arr1.size(); i++) 
     for(int j = 0;j < arr2[1].size(); j++)      
         for(int k = 0;k < arr2.size(); k++)
           // ?????됰젹??怨깆쓣 ?섑뻾 
            answer[i][j] += arr1[i][k] * arr2[k][j];

    return answer;
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??

#include <iterator>
#include <iostream>
void print2D(vector<vector<int>> vec)
{
    for(const auto& innerVec : vec){
        copy(innerVec.begin(), innerVec.end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    
    cout << endl;
}

int main()
{
    print2D(solution({{1, 4}, {3, 2}, {4, 1}} ,{{3, 3}, {3,3}}));
    /*
      15 15
      15 15
      15 15
    */
    print2D(solution({{2, 3, 2}, {4, 2, 4}, {3, 1,4}}, {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}} ));     // 1 2 3 
    /*
      22 22 11
      36 28 18
      29 20 14
    */
    
    return 0;
}
