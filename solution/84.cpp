#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    //??媛??ш린???곕Ⅸ 洹ㅼ쓽 媛쒖닔???몃뒗 counter
    unordered_map<int, int> counter;

    //???ш린蹂꾨줈 洹ㅼ쓽 媛쒖닔瑜???
    for (int i = 0; i < tangerine.size(); ++i) {
        counter[tangerine[i]]++;
    }

    //??媛?洹ㅼ쓽 媛쒖닔留?????? ?대? ?대┝李⑥닚 ?뺣젹
    vector<int> sorted_counts;
    for (const auto& kv : counter) {
        sorted_counts.push_back(kv.second);
    }
    sort(sorted_counts.rbegin(), sorted_counts.rend());

    
    int num_types = 0; // ?꾩옱源뚯? 怨좊Ⅸ 洹ㅼ쓽 醫낅쪟
    int count_sum = 0; // ?꾩옱源뚯? 洹?媛쒖닔??珥???

   //??媛??留롮? 洹ㅼ쓽 媛쒖닔遺???쒗쉶
    for (int count : sorted_counts) {
        count_sum += count;
        num_types++;
   
        //??洹ㅼ쓽 媛쒖닔 ?⑹씠 k ?댁긽 ?섎뒗 ?쒓컙 醫낅즺
        if (count_sum >= k) {
            break;
        }
    }

    return num_types;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution(6, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //異쒕젰媛?: 3
  cout << solution(4, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //異쒕젰媛?: 2
  cout << solution(2, {1, 1, 1, 1, 2, 2, 2, 3}) << endl; //異쒕젰媛?: 1
  
  return 0;
}
