#include <vector>

using namespace std;

vector<int> solution(vector<int> arr1, vector<int> arr2) {
  //????諛곗뿴???뺣젹???곹깭濡?蹂묓빀?섎뒗 諛곗뿴
  vector<int> merged;
  int i = 0, j = 0;  

  //????諛곗뿴???쒗쉶?섎㈃???뺣젹??諛곗뿴???앹꽦
  while (i < arr1.size() && j < arr2.size()) {
    if (arr1[i] <= arr2[j]) {
      merged.push_back(arr1[i]);
      i++;
    } else {
      merged.push_back(arr2[j]);
      j++;
    }
  }

  //??arr1?대굹 arr2 以??⑥븘?덈뒗 ?먯냼?ㅼ쓣 ?뺣젹??諛곗뿴 ?ㅼ뿉 異붽?
  while (i < arr1.size()) {
    merged.push_back(arr1[i]);
    i++;
  }
  while (j < arr2.size()) {
    merged.push_back(arr2[j]);
    j++;
  }

  return merged;
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
  print(solution({1, 3, 5}, {2, 4, 6})); // 異쒕젰媛?: 1 2 3 4 5 6
  print(solution({1, 2, 3}, {4, 5, 6})); // 異쒕젰媛?: 1 2 3 4 5 6
  
  return 0;
}

