#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0)); // ??dp ?뚯씠釉?珥덇린??
    
    // ??dp ?뚯씠釉붿쓽 留??꾨옒履??쇱씤 珥덇린??
    for (int i = 0; i < n; i++) {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    
    // ???꾨옒履??쇱씤遺???щ씪媛硫댁꽌 dp ?뚯씠釉?梨꾩슦湲?
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    
    return dp[0][0]; // 瑗??湲곗뿉?쒖쓽 理쒕뙎媛?諛섑솚
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

using namespace std;

int main()
{
  cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl; //異쒕젰媛?: 30
  
  return 0;
}
