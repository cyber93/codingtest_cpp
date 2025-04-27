#include <queue>

using namespace std;

int solution(int N, int K) {
    queue<int> q;

    // ??1遺??N源뚯???踰덊샇瑜??먯뿉 異붽?
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

  //???먯뿉 ?섎굹???붿냼媛 ?⑥쓣 ?뚭퉴吏 ?쒗쉶
    while (q.size() > 1) { 
        for (int i = 0; i < K - 1; i++) {
            //??K踰덉㎏ ?щ엺??李얘린 ?꾪빐 ?욎뿉?쒕????쒓굅?섍퀬 ?ㅼ뿉 異붽?
            q.push(q.front());
            q.pop();
        }
        //??K踰덉㎏ ?щ엺 ?쒓굅
        q.pop();
    }

    //??留덉?留됱쑝濡??⑥? ?붿냼 諛섑솚
    return q.front();
}


//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
    
    cout << solution(5, 2) << endl; // 3

}
