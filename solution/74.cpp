﻿#include <vector>

using namespace std;

long long solution(int n) {
  // ??諛붾떏??媛濡?湲몄씠媛 1??寃쎌슦, 諛붾떏??梨꾩슦??諛⑸쾿???섎뒗 1
  if (n == 1) {
    return 1;
  }
  // ??諛붾떏??媛濡?湲몄씠媛 2??寃쎌슦, 諛붾떏??梨꾩슦??諛⑸쾿???섎뒗 2
  if (n == 2) {
    return 2;
  }
  // ???숈쟻 怨꾪쉷踰뺤쓣 ?꾪븳 諛곗뿴 珥덇린??
  // dp[i]??媛濡?湲몄씠媛 i????諛붾떏??梨꾩슦??諛⑸쾿????
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  // ??媛濡?湲몄씠媛 3遺??n源뚯???媛곴컖??寃쎌슦?????諛붾떏??梨꾩슦??諛⑸쾿???섎? 援ы븿
  for (int i = 3; i <= n; i++) {
    // ??dp[i]??dp[i-1]怨?dp[i-2]瑜??뷀븳 媛?
    dp[i] = (dp[i - 1] + dp[i - 2]) % 100Q0000007;
  }
  // ??諛붾떏??媛濡?湲몄씠媛 n????諛붾떏??梨꾩슦??諛⑸쾿???섏씤 dp[n]??諛섑솚
  return dp[n];
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution(4) << endl; //異쒕젰媛?: 5
  
  return 0;
}
