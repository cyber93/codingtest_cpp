#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    //???꾩옱 ?꾩튂瑜??섑? ?대뒗 ?ш린媛 2?닿퀬 媛믪씠 紐⑤몢 0??踰≫꽣 ?좎뼵
    vector<int> v(2,0);
    
    //?????낅젰?쒖쑝濡?罹먮┃???대룞
    for(string s : keyinput)
    {
        if     (s=="up"    && v[1]<+board[1]/2) v[1]++;
        else if(s=="down"  && v[1]>-board[1]/2) v[1]--;
        else if(s=="left"  && v[0]>-board[0]/2) v[0]--;
        else if(s=="right" && v[0]<+board[0]/2) v[0]++;
    }

    return v;
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
  print(solution({"left", "right", "up", "right", "right"}, {11, 11})); //異쒕젰媛?: 2 1 
  print(solution({"down", "down", "down", "down", "down"}, {7, 9})); //異쒕젰媛?: 0 -4  
  
  return 0;
}
