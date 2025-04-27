﻿#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
  //???먰솕?앹뿉 ?꾩슂??蹂?섎? 珥덇린??
  int n = money.size();
  vector<int> dp1(n, 0);
  vector<int> dp2(n, 0);

  //??泥?踰덉㎏ 吏묒쓣 ?곕뒗 寃쎌슦
  dp1[0] = money[0];
  dp1[1] = money[0];
  for (int i = 2; i < n - 1; ++i) {
    dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
  }

  //??泥?踰덉㎏ 吏묒쓣 ?몄? ?딅뒗 寃쎌슦
  dp2[1] = money[1];
  for (int i = 2; i < n; ++i) {
    dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
  }

  //????寃쎌슦 以? 理쒕?媛?李얘린
  int answer = max(dp1[n - 2], dp2[n - 1]);
  return answer;
}



//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution({1, 2, 3, 1}) << endl; //異쒕젰媛?: 4
  
  return 0;
}
